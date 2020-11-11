#pragma once

#include <cstdint>
#include "../types/String.h"

namespace alt
{
    class INative
    {
    protected:
        virtual ~INative() = default;

    public:
        enum class Type
        {
            ARG_BOOL,
            ARG_BOOL_PTR,
            ARG_INT32,
            ARG_INT32_PTR,
            ARG_UINT32,
            ARG_UINT32_PTR,
            ARG_FLOAT,
            ARG_FLOAT_PTR,
            ARG_VECTOR3,
            ARG_VECTOR3_PTR,
            ARG_STRING,
            ARG_STRUCT,
            ARG_VOID
        };

        struct Vector3
        {
            float x, __padx, y, __pady, z, __padz;
        };

        class Context
        {
        protected:
            virtual ~Context() = default;

        public:
            virtual void Reset() = 0;

            virtual void Push(bool val) = 0;
            virtual void Push(bool *val) = 0;
            virtual void Push(int32_t val) = 0;
            virtual void Push(int32_t *val) = 0;
            virtual void Push(uint32_t val) = 0;
            virtual void Push(uint32_t *val) = 0;
            virtual void Push(float val) = 0;
            virtual void Push(float *val) = 0;
            virtual void Push(Vector3 *val) = 0;
            virtual void Push(char *val) = 0;
            virtual void Push(void *val) = 0;

            virtual bool ResultBool() = 0;
            virtual int32_t ResultInt() = 0;
            virtual uint32_t ResultUint() = 0;
            virtual float ResultFloat() = 0;
            virtual Vector3 ResultVector3() = 0;
            virtual const char *ResultString() = 0;
        };

        virtual String GetName() const = 0;
        virtual Type GetRetnType() const = 0;
        virtual Array<Type> GetArgTypes() const = 0;
        virtual bool IsValid() const = 0;
        virtual bool Invoke(Context *ctx) = 0;
    };
} // namespace alt
