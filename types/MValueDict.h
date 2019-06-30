#pragma once

#include "MValue.h"

namespace alt
{
	class MValueDict : public MValue
	{
	public:
		MValueDict() :
			MValue(MValue::Dict())
		{

		}

		MValueDict(const MValue::Dict& dict) :
			MValue(dict)
		{

		}

		MValueDict(MValue val)
		{
			if (val.GetType() != Type::DICT)
				throw TypeMismatchException();

			*(MValue*)this = val;
		}

		MValue& operator[](const String& key) { return Get<Dict>()[key]; }

		void Delete(const String& key) { Get<Dict>().erase(key); }
	};
}