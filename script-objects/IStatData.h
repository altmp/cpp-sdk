#pragma once
#include <cstdint>

namespace alt
{
    class IStatData
    {
    protected:
        virtual ~IStatData() = default;

    public:
        virtual void Reset() = 0;
        virtual void SetInt32Value(int32_t value) = 0;
        virtual void SetInt64Value(int64_t value) = 0;
        virtual void SetFloatValue(float value) = 0;
        virtual void SetBoolValue(bool value) = 0;
        virtual void SetUInt8Value(uint8_t value) = 0;
        virtual void SetUInt16Value(uint16_t value) = 0;
        virtual void SetUInt32Value(uint32_t value) = 0;
        virtual void SetUInt64Value(uint64_t value) = 0;
        virtual void SetStringValue(const char *value) = 0;

    private:
        virtual bool GetUnkBool() = 0;

    public:
        virtual int32_t GetInt32Value() = 0;
        virtual int64_t GetInt64Value() = 0;
        virtual float GetFloatValue() = 0;
        virtual bool GetBoolValue() = 0;
        virtual uint8_t GetUInt8Value() = 0;
        virtual uint16_t GetUInt16Value() = 0;
        virtual uint32_t GetUInt32Value() = 0;
        virtual uint64_t GetUInt64Value() = 0;
        virtual const char *GetStringValue() = 0;

    private:
        virtual bool GetUnkBool2() = 0;
        virtual bool GetUnkBool3() = 0;

    public:
        virtual bool IsEqual(void *ptr) = 0;

    private:
        virtual void unkFunc() = 0;

    public:
        virtual const char *GetStatType() = 0;
        virtual int GetSize() = 0;

    };
} // namespace alt
