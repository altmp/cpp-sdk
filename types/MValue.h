#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "../types/Types.h"
#include "../Ref.h"
#include "../types/RGBA.h"
#include "../deps/alt-math/alt-math.h"

namespace alt
{
	class IBaseObject;

	class IMValue;
	class IMValueNone;
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
	class IMValueVector2;
	class IMValueVector3;
	class IMValueRGBA;
	class IMValueByteArray;

	using MValue = std::shared_ptr<IMValue>;
	using MValueNone = std::shared_ptr<IMValueNone>;
	using MValueNil = std::shared_ptr<IMValueNil>;
	using MValueBool = std::shared_ptr<IMValueBool>;
	using MValueInt = std::shared_ptr<IMValueInt>;
	using MValueUInt = std::shared_ptr<IMValueUInt>;
	using MValueDouble = std::shared_ptr<IMValueDouble>;
	using MValueString = std::shared_ptr<IMValueString>;
	using MValueList = std::shared_ptr<IMValueList>;
	using MValueDict = std::shared_ptr<IMValueDict>;
	using MValueBaseObject = std::shared_ptr<IMValueBaseObject>;
	using MValueFunction = std::shared_ptr<IMValueFunction>;
	using MValueVector2 = std::shared_ptr<IMValueVector2>;
	using MValueVector3 = std::shared_ptr<IMValueVector3>;
	using MValueRGBA = std::shared_ptr<IMValueRGBA>;
	using MValueByteArray = std::shared_ptr<IMValueByteArray>;

	using MValueConst = std::shared_ptr<const IMValue>;
	using MValueNoneConst = std::shared_ptr<const IMValueNone>;
	using MValueNilConst = std::shared_ptr<const IMValueNil>;
	using MValueBoolConst = std::shared_ptr<const IMValueBool>;
	using MValueIntConst = std::shared_ptr<const IMValueInt>;
	using MValueUIntConst = std::shared_ptr<const IMValueUInt>;
	using MValueDoubleConst = std::shared_ptr<const IMValueDouble>;
	using MValueStringConst = std::shared_ptr<const IMValueString>;
	using MValueListConst = std::shared_ptr<const IMValueList>;
	using MValueDictConst = std::shared_ptr<const IMValueDict>;
	using MValueBaseObjectConst = std::shared_ptr<const IMValueBaseObject>;
	using MValueFunctionConst = std::shared_ptr<const IMValueFunction>;
	using MValueVector2Const = std::shared_ptr<const IMValueVector2>;
	using MValueVector3Const = std::shared_ptr<const IMValueVector3>;
	using MValueRGBAConst = std::shared_ptr<const IMValueRGBA>;
	using MValueByteArrayConst = std::shared_ptr<const IMValueByteArray>;

	using MValueArgs = std::vector<MValueConst>;

	class IMValue : public std::enable_shared_from_this<IMValue>
	{
	public:
		enum class Type : uint8_t
		{
			NONE,
			NIL,
			BOOL,
			INT,
			UINT,
			DOUBLE,
			STRING,
			LIST,
			DICT,
			BASE_OBJECT,
			FUNCTION,
			VECTOR3,
			RGBA,
			BYTE_ARRAY,
			VECTOR2
		};

		virtual ~IMValue() = default;

		virtual Type GetType() const = 0;
		virtual std::string ToString() const = 0;
		virtual double ToNumber() const = 0;
		virtual MValue Clone() const = 0;
		virtual bool Equals(MValueConst other) const = 0;
	};

	// Represents lack of value
	class IMValueNone : public virtual IMValue { };

	// Represents null value
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
		virtual const std::string& Value() const = 0;
	};

	class IMValueList : public virtual IMValue
	{
	public:
		virtual Size GetSize() const = 0;
		virtual MValue Get(Size i) = 0;
		virtual MValueConst Get(Size i) const = 0;

		// Transfers ownership of MValue (You should not have any more refs to this copy)
		virtual void Set(Size i, MValue val) = 0;
		virtual void Push(MValue val) = 0;

		// Will clone an MValueConst
		virtual void SetConst(Size i, MValueConst val) = 0;
		virtual void PushConst(MValueConst val) = 0;
	};

	class IMValueDict : public virtual IMValue
	{
	public:
		class Iterator
		{
		public:
			virtual std::string GetKey() = 0;
			virtual MValueConst GetValue() = 0;
		};

		virtual Size GetSize() const = 0;
		virtual MValue Get(const std::string& key) = 0;
		virtual MValueConst Get(const std::string& key) const = 0;
		virtual bool Has(const std::string& key) const = 0;

		// Transfers ownership of MValue (You should not have any more refs to this copy)
		virtual void Set(const std::string& key, MValue val) = 0;

		// Will clone an MValueConst
		virtual void SetConst(const std::string& key, MValueConst val) = 0;

		virtual void Delete(const std::string& key) = 0;

		virtual Iterator* Begin() const = 0;
		virtual Iterator* Next() const = 0;
	};

	class IMValueBaseObject : public virtual IMValue
	{
	public:
		virtual IBaseObject* RawValue() const = 0;
		virtual std::shared_ptr<IBaseObject> Value() const = 0;
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

	class IMValueVector2 : public virtual IMValue
	{
	public:
		virtual Vector2f Value() const = 0;
	};

	class IMValueVector3 : public virtual IMValue
	{
	public:
		virtual Vector3f Value() const = 0;
	};

	class IMValueRGBA : public virtual IMValue
	{
	public:
		virtual RGBA Value() const = 0;
	};

	class IMValueByteArray : public virtual IMValue
	{
	public:
		virtual Size GetSize() const = 0;
		virtual const uint8_t* GetData() const = 0;
		virtual uint8_t* GetData() = 0;
	};
}
