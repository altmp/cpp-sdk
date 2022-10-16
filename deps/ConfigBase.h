#pragma once

#include <string>
#include <sstream>
#include <variant>
#include <vector>
#include <map>
#include <memory>

namespace Config
{
	namespace internal
	{
		template<class T>
		class ValueWrapper
		{
		public:
			ValueWrapper() : value(nullptr) {}
			ValueWrapper(std::shared_ptr<T> _value) : value(_value) {}
			ValueWrapper(const typename T::String& val)
			{
				value = std::make_shared<T>(val);
			}
			ValueWrapper(const typename T::Bool& val)
			{
				value = std::make_shared<T>(val);
			}
			ValueWrapper(const typename T::Number& val)
			{
				value = std::make_shared<T>(val);
			}
			ValueWrapper(const typename T::List& val)
			{
				value = std::make_shared<T>(val);
			}
			ValueWrapper(const typename T::Dict& val)
			{
				value = std::make_shared<T>(val);
			}
			template<typename U>
			ValueWrapper(const std::vector<U>& vector)
			{
				typename T::List list;
				list.reserve(vector.size());
				for(auto& val : vector)
				{
					list.push_back(val);
				}
				value = std::make_shared<T>(list);
			}

			T* operator->()
			{
				return value.get();
			}

			ValueWrapper operator[](const char* key)
			{
				return value->Get(key);
			}
			ValueWrapper operator[](const std::string& key)
			{
				return value->Get(key);
			}
			ValueWrapper operator[](size_t index)
			{
				return value->Get(index);
			}

			typename T::List::iterator begin()
			{
				if(!value->IsList()) return {};
				return value->AsList().begin();
			}
			typename T::List::iterator end()
			{
				if(!value->IsList()) return {};
				return value->AsList().end();
			}

			operator bool()
			{
				return value && !value->IsNone();
			}
			ValueWrapper& operator=(const ValueWrapper& other)
			{
				if (&other == this) return *this;
				value = other.value;
				return *this;
			}

		private:
			std::shared_ptr<T> value;
		};
	};

	class Value
	{
	public:
		using ValuePtr = internal::ValueWrapper<Value>;

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
		Value(const String& _value) : type(Type::STRING), value(_value) {}
		Value(const char* _value) : type(Type::STRING), value(_value) {}
		Value(Bool _value) : type(Type::BOOL), value(_value) {}
		Value(Number _value) : type(Type::NUMBER), value(_value) {}
		Value(const List& _value) : type(Type::LIST), value(_value) {}
		Value(const Dict& _value) : type(Type::DICT), value(_value) {}

		constexpr Type GetType() { return type; }
		constexpr bool IsNone() { return type == Type::NONE; }
		constexpr bool IsString() { return type == Type::STRING; }
		constexpr bool IsBool() { return type == Type::BOOL; }
		constexpr bool IsNumber() { return type == Type::NUMBER; }
		constexpr bool IsList() { return type == Type::LIST; }
		constexpr bool IsDict() { return type == Type::DICT; }

		template<typename T>
		T As(const T& defaultValue = T())
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
		String AsString(const String& defaultValue = "")
		{
			if(!IsString()) return defaultValue;
			return As<String>(defaultValue);
		}
		Bool AsBool(Bool defaultValue = false)
		{
			if(!IsBool()) return defaultValue;
			return As<Bool>(defaultValue);
		}
		template<typename T = double>
		T AsNumber(T defaultValue = 0)
		{
			if(!IsNumber()) return defaultValue;
			return (T)As<Number>(defaultValue);
		}
		List AsList(const List& defaultValue = {})
		{
			if(!IsList()) return defaultValue;
			return As<List>(defaultValue);
		}
		Dict AsDict(const Dict& defaultValue = {})
		{
			if(!IsDict()) return defaultValue;
			return As<Dict>(defaultValue);
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

		operator bool()
		{
			return IsNone();
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
		static std::string Format(ValuePtr config)
		{
			return Derived::Format(config);
		}
	};

	namespace Util
	{
		static std::string ConvertValueToString(Value::ValuePtr& value, uint32_t indentLevel = 0)
		{
			constexpr auto getIndent = [](uint32_t indentLevel) -> std::string {
				return std::string(indentLevel * 2, ' ');
			};

			if (value->IsString())
			{
				std::string str;
				str += "'";
				str += value->AsString();
				str += "'";
				return str;
			}
			if (value->IsBool())
			{
				bool val = value->AsBool();
				return val ? "true" : "false";
			}
			if (value->IsNumber())
			{
				double val = value->AsNumber();
				// Weird hack to check if the number has any decimal points
				if (abs(val - int64_t(val)) == 0) return std::to_string((int64_t)val);
				return std::to_string(val);
			}
			if (value->IsList())
			{
				std::stringstream stream;
				stream << getIndent(indentLevel) << "[\n";
				Value::List list = value->AsList();
				for (size_t i = 0, size = list.size(); i < size; i++)
				{
					stream << getIndent(indentLevel + 1);
					if (list[i]->IsDict() || list[i]->IsList()) stream << "\n";
					stream << ConvertValueToString(list[i], indentLevel + 1);
					if (i != size - 1) stream << ",";
					stream << "\n";
				}
				stream << getIndent(indentLevel) << "]";
				return stream.str();
			}
			if (value->IsDict())
			{
				std::stringstream stream;
				stream << getIndent(indentLevel) << "{\n";
				Value::Dict dict = value->AsDict();
				for (auto it = dict.begin(); it != dict.end(); it++)
				{
					stream << getIndent(indentLevel + 1) << it->first << ": ";
					if (it->second->IsDict() || it->second->IsList()) stream << "\n";
					stream << ConvertValueToString(it->second, indentLevel + 1);
					if (it != --dict.end()) stream << ",";
					stream << "\n";

				}
				stream << getIndent(indentLevel) << "}";
				return stream.str();
			}
			return "<none>";
		}
	}
}
