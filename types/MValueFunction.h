#pragma once

#include "MValue.h"
#include "MValueList.h"

#include "../IResource.h"

namespace alt
{
	class MValueFunction : public MValue
	{
	public:
		struct Invoker { virtual MValue Invoke(MValueList args) = 0; };

		MValueFunction(const MValue::Function& func) :
			MValue(func)
		{

		}

		MValueFunction(Invoker* invoker) :
			MValue(MValue::Function{ invoker })
		{

		}

		MValueFunction(MValue val)
		{
			if (val.GetType() != Type::FUNCTION)
				throw TypeMismatchException();

			*(MValue*)this = val;
		}

		Invoker* GetInvoker()
		{
			const MValue::Function& fn = Get<MValue::Function>();
			return static_cast<Invoker*>(fn.invoker);
		}
	};
}