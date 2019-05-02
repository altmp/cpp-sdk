#pragma once

#include <cstdint>
#include <unordered_map>

#include "String.h"
#include "Array.h"

namespace alt
{
	class IBaseObject;
	class IResource;

	class MValue
	{
	public:
		enum class Type : uint8_t
		{
			NIL,
			BOOL,
			INT,
			UINT,
			DOUBLE,
			STRING,
			LIST,
			DICT,
			ENTITY,
			FUNCTION
		};

		using Nil = void;
		using Bool = bool;
		using Int = int64_t;
		using UInt = uint64_t;
		using Double = double;
		using String = alt::String;
		using List = alt::Array<MValue>;
		using Dict = std::unordered_map<String, MValue>; //temp
		using Entity = alt::IBaseObject*;
		struct Function { void* invoker; };

		class TypeMismatchException : std::exception
		{
		public:
			const char* what() const noexcept override
			{
				return "type mismatch";
			}
		};

	private:
		template<class... Args>
		struct _TypeTag
		{
			template<uint64_t idx, class _T, class... _Args>
			struct _Type : _Type<idx - 1, _Args...> { };

			template<class _T, class... _Args>
			struct _Type<0, _T, _Args...> { using Type = _T; };

			template<MValue::Type type>
			using Type = typename _Type<(uint64_t)type, Args...>::Type;

			template<uint64_t idx, class U, class _T, class... _Args>
			struct _TypeId : _TypeId<idx + 1, U, _Args...> { };

			template<uint64_t idx, class U, class... _Args>
			struct _TypeId<idx, U, U, _Args...> { static constexpr MValue::Type Id = (MValue::Type)idx; };

			template<class U>
			static constexpr MValue::Type TypeId = _TypeId<0, U, Args...>::Id;
		};

		using TypeTag = _TypeTag<Nil, Bool, Int, UInt, Double, String, List, Dict, Entity, Function>;

		struct _Storage { uint64_t refCount = 1; virtual ~_Storage() = default; };

		template<class T>
		struct Storage : _Storage { T value; };

		template<class T>
		void Create(const T& val)
		{
			type = TypeTag::TypeId<T>;
			auto _storage = new Storage<T>;

			_storage->refCount = 1;
			_storage->value = val;

			storage = _storage;
		}

		void CreateNil()
		{
			type = Type::NIL;
			storage = nullptr;
		}

		void Copy(const MValue& that)
		{
			type = that.type;
			storage = that.storage;

			if (storage)
				++storage->refCount;
		}

		void Destroy()
		{
			if (!storage)
				return;

			--storage->refCount;

			if (storage->refCount == 0)
				delete storage;
		}

		Type type;
		_Storage* storage;

	public:
		MValue() { CreateNil(); }
		MValue(const Bool& val) { Create(val); }
		MValue(const Int& val) { Create(val); }
		MValue(const UInt& val) { Create(val); }
		MValue(const Double& val) { Create(val); }
		MValue(const String& val) { Create(val); }
		MValue(const List& val) { Create(val); }
		MValue(const Dict& val) { Create(val); }
		MValue(const Entity& val) { Create(val); }
		MValue(const Function& val) { Create(val); }

		MValue(int32_t val) { Create<Int>(val); }
		MValue(uint32_t val) { Create<UInt>(val); }
		MValue(const char* val) { Create<String>(val); }
		MValue(const std::string& val) { Create<String>(val); }

		MValue(const MValue& that) { Copy(that); }

		MValue& operator=(const MValue& that)
		{
			Destroy();
			Copy(that);

			return *this;
		}

		Bool ToBool()
		{
			return ToInt() != 0;
		}

		Int ToInt()
		{
			switch (type)
			{
			case Type::BOOL:
				return Get<Bool>();
			case Type::INT:
				return Get<Int>();
			case Type::UINT:
				return Get<UInt>();
			case Type::DOUBLE:
				return Get<Double>();
			}

			return 0;
		}

		UInt ToUInt()
		{
			switch (type)
			{
			case Type::BOOL:
				return Get<Bool>();
			case Type::INT:
				return Get<Int>();
			case Type::UINT:
				return Get<UInt>();
			case Type::DOUBLE:
				return Get<Double>();
			}

			return 0;
		}

		String ToString()
		{
			switch (type)
			{
			case Type::BOOL:
				return Get<Bool>() ? "true" : "false";
			case Type::INT:
				return std::to_string(Get<Int>());
			case Type::UINT:
				return std::to_string(Get<UInt>());
			case Type::DOUBLE:
				return std::to_string(Get<Double>());
			case Type::STRING:
				return Get<String>();
			}

			return "MValue<>";
		}

		Type GetType() const { return type; }

		template<Type _type, typename T = typename TypeTag::Type<_type>>
		typename TypeTag::Type<_type>& Get()
		{
			return Get<T>();
		}

		template<class T>
		T& Get()
		{
			if (TypeTag::TypeId<T> != type)
				throw TypeMismatchException();

			auto _storage = static_cast<Storage<T>*>(storage);
			return _storage->value;
		}

		~MValue() { Destroy(); }
	};
}
