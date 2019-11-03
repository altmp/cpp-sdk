#pragma once

#include <cstdint>
#include "String.h"
#include "../Ref.h"
#include "Array.h"

namespace alt
{
	class IBaseObject;

	class IMValue;
	class IMValueNil;
	class IMValueBool;
	class IMValueInt;
	class IMValueUInt;
	class IMValueDouble;
	class IMValueString;
	class IMValueList;
	class IMValueDict;
	class IMValueBaseObject;
	class IMValueFunction;

	using MValue = Ref<IMValue>;
	using MValueNil = Ref<IMValueNil>;
	using MValueBool = Ref<IMValueBool>;
	using MValueInt = Ref<IMValueInt>;
	using MValueUInt = Ref<IMValueUInt>;
	using MValueDouble = Ref<IMValueDouble>;
	using MValueString = Ref<IMValueString>;
	using MValueList = Ref<IMValueList>;
	using MValueDict = Ref<IMValueDict>;
	using MValueBaseObject = Ref<IMValueBaseObject>;
	using MValueFunction = Ref<IMValueFunction>;

	using MValueConst = ConstRef<IMValue>;
	using MValueNilConst = ConstRef<IMValueNil>;
	using MValueBoolConst = ConstRef<IMValueBool>;
	using MValueIntConst = ConstRef<IMValueInt>;
	using MValueUIntConst = ConstRef<IMValueUInt>;
	using MValueDoubleConst = ConstRef<IMValueDouble>;
	using MValueStringConst = ConstRef<IMValueString>;
	using MValueListConst = ConstRef<IMValueList>;
	using MValueDictConst = ConstRef<IMValueDict>;
	using MValueBaseObjectConst = ConstRef<IMValueBaseObject>;
	using MValueFunctionConst = ConstRef<IMValueFunction>;

	using MValueArgs = Array<MValueConst>;

	class IMValue : public virtual CRefCountable
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
			BASE_OBJECT,
			FUNCTION
		};

		virtual ~IMValue() = default;

		virtual Type GetType() const = 0;
		virtual String ToString() const = 0;
		virtual double ToNumber() const = 0;
		virtual MValue Clone() const = 0;
	};

	class IMValueNil : public virtual IMValue { };

	class IMValueBool : public virtual IMValue
	{
	public:
		virtual bool Value() const = 0;
	};

	class IMValueInt : public virtual IMValue
	{
	public:
		virtual int64_t Value() const = 0;
	};

	class IMValueUInt : public virtual IMValue
	{
	public:
		virtual uint64_t Value() const = 0;
	};

	class IMValueDouble : public virtual IMValue
	{
	public:
		virtual double Value() const = 0;
	};

	class IMValueString : public virtual IMValue
	{
	public:
		virtual StringView Value() const = 0;
	};

	class IMValueList : public virtual IMValue
	{
	public:
		virtual Size GetSize() const = 0;
		virtual MValue Get(Size i) = 0;
		virtual MValueConst Get(Size i) const = 0;
		virtual void Set(Size i, MValue val) = 0;
		virtual void Push(MValue val) = 0;
	};

	class IMValueDict : public virtual IMValue
	{
	public:
		class Iterator
		{
		public:
			virtual String GetKey() = 0;
			virtual MValueConst GetValue() = 0;
		};

		virtual Size GetSize() const = 0;
		virtual MValue Get(String key) = 0;
		virtual MValueConst Get(String key) const = 0;
		virtual void Set(String key, MValue val) = 0;
		virtual void Delete(String key) = 0;

		virtual Iterator* Begin() const = 0;
		virtual Iterator* Next() const = 0;
	};

	class IMValueBaseObject : public virtual IMValue
	{
	public:
		virtual IBaseObject* Value() const = 0;
	};

	class IMValueFunction : public virtual IMValue
	{
	public:
		class Impl
		{
		public:
			virtual MValue Call(MValueArgs args) const = 0;

			virtual void AddRef() { ++refCount; }

			virtual void RemoveRef()
			{
				if (--refCount == 0)
					delete this;
			}

		protected:
			~Impl() = default;

		private:
			Size refCount = 0;
		};

		virtual MValue Call(MValueArgs args) const = 0;
	};
}
