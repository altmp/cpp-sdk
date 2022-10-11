#pragma once

#include <string>
#include <sstream>
#include <variant>
#include <vector>
#include <map>
#include <memory>

namespace Config
{
	class Value
	{
	public:
		using ValuePtr = std::shared_ptr<Value>;

		enum class Type : uint8_t
		{
			NONE,
			STRING,
			BOOL,
			NUMBER,
			LIST,
			DICT
		};
		using None = std::nullptr_t;
		using String = std::string;
		using Bool = bool;
		using Number = double;
		using List = std::vector<ValuePtr>;
		using Dict = std::map<std::string, ValuePtr>;
		using Any = std::variant<None, String, Bool, Number, List, Dict>;

		Value(Value&& _value) : type(_value.type), value(_value.value) {}
		Value(const Value& _value) : type(_value.type), value(_value.value) {}
		Value(Type _type, Any _value) : type(_type), value(_value) {}
		Value() : type(Type::NONE), value(nullptr) {}
		Value(String& _value) : type(Type::STRING), value(_value) {}
		Value(const char* _value) : type(Type::STRING), value(_value) {}
		Value(Bool _value) : type(Type::BOOL), value(_value) {}
		Value(Number _value) : type(Type::NUMBER), value(_value) {}
		Value(List& _value) : type(Type::LIST), value(_value) {}
		Value(Dict& _value) : type(Type::DICT), value(_value) {}

		constexpr Type GetType() { return type; }
		constexpr bool IsNone() { return type == Type::NONE; }
		constexpr bool IsString() { return type == Type::STRING; }
		constexpr bool IsBool() { return type == Type::BOOL; }
		constexpr bool IsNumber() { return type == Type::NUMBER; }
		constexpr bool IsList() { return type == Type::LIST; }
		constexpr bool IsDict() { return type == Type::DICT; }

		template<typename T>
		T As(T defaultValue = T())
		{
			try
			{
				if constexpr (std::is_same_v<T, String>) return std::get<String>(value);
				if constexpr (std::is_same_v<T, Bool>) return std::get<Bool>(value);
				if constexpr (std::is_integral_v<T> || std::is_floating_point_v<T>) return std::get<Number>(value);
				if constexpr (std::is_same_v<T, List>) return std::get<List>(value);
				if constexpr (std::is_same_v<T, Dict>) return std::get<Dict>(value);
				return defaultValue;
			}
			catch (...)
			{
				return defaultValue;
			}
		}

		ValuePtr Get(const std::string& key)
		{
			if (!IsDict()) return std::make_shared<Value>(Type::NONE, nullptr);
			Dict dict = As<Dict>();
			auto found = dict.find(key);
			if (found == dict.end()) return std::make_shared<Value>(Type::NONE, nullptr);
			return found->second;
		}

		ValuePtr Get(size_t index)
		{
			if (!IsList()) return std::make_shared<Value>(Type::NONE, nullptr);
			List list = As<List>();
			if (list.size() <= index) return std::make_shared<Value>(Type::NONE, nullptr);
			return list.at(index);
		}

		size_t GetSize()
		{
			if (IsDict()) return As<Dict>().size();
			if (IsList()) return As<List>().size();
			return 0;
		}

		ValuePtr operator[](const std::string& key)
		{
			return Get(key);
		}
		ValuePtr operator[](const char* key)
		{
			return Get(key);
		}
		ValuePtr operator[](size_t index)
		{
			return Get(index);
		}

		// Type conversions
		operator String()
		{
			return As<String>();
		}
		operator Bool()
		{
			return As<Bool>();
		}
		operator Number()
		{
			return As<Number>();
		}
		operator List()
		{
			return As<List>();
		}
		operator Dict()
		{
			return As<Dict>();
		}

		// For debug
		std::string ToString(uint32_t indentLevel = 0)
		{
			constexpr auto getIndent = [](uint32_t indentLevel) -> std::string {
				return std::string(indentLevel * 2, ' ');
			};

			if (IsString())
			{
				std::string str;
				str += "'";
				str += As<String>();
				str += "'";
				return str;
			}
			if (IsBool())
			{
				bool val = As<Bool>();
				return val ? "true" : "false";
			}
			if (IsNumber())
			{
				double val = As<Number>();
				// Weird hack to check if the number has any decimal points
				if (abs(val - int64_t(val)) == 0) return std::to_string((int64_t)val);
				return std::to_string(val);
			}
			if (IsList())
			{
				std::stringstream stream;
				stream << getIndent(indentLevel) << "[\n";
				List list = As<List>();
				for (size_t i = 0, size = list.size(); i < size; i++)
				{
					stream << getIndent(indentLevel + 1);
					if (list[i]->IsDict() || list[i]->IsList()) stream << "\n";
					stream << list[i]->ToString(indentLevel + 1);
					if (i != size - 1) stream << ",";
					stream << "\n";
				}
				stream << getIndent(indentLevel) << "]";
				return stream.str();
			}
			if (IsDict())
			{
				std::stringstream stream;
				stream << getIndent(indentLevel) << "{\n";
				Dict dict = As<Dict>();
				for (auto it = dict.begin(); it != dict.end(); it++)
				{
					stream << getIndent(indentLevel + 1) << it->first << ": ";
					if (it->second->IsDict() || it->second->IsList()) stream << "\n";
					stream << it->second->ToString(indentLevel + 1);
					if (it != --dict.end()) stream << ",";
					stream << "\n";

				}
				stream << getIndent(indentLevel) << "}";
				return stream.str();
			}
			return "<none>";
		}

	private:
		Type type;
		Any value;
	};

	template<class Derived>
	class ConfigBase
	{
	public:
		using Value = Config::Value;
		using ValuePtr = Config::Value::ValuePtr;

		static ValuePtr Parse(const std::string& input, std::string& error)
		{
			return Derived::Parse(input, error);
		}
	};

}
