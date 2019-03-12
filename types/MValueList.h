#pragma once

#include "MValue.h"

namespace alt
{
	class MValueList : public MValue
	{
	public:
		MValueList() :
			MValue(MValue::List())
		{

		}

		MValueList(Size size) :
			MValue(MValue::List(size))
		{

		}

		MValueList(const MValue::List& list) :
			MValue(list)
		{

		}

		MValueList(MValue val)
		{
			if (val.GetType() != Type::LIST)
				throw TypeMismatchException();

			*(MValue*)this = val;
		}

		Size GetSize() { return Get<List>().GetSize(); }

		MValue& operator[](Size key) { return Get<List>()[key]; }

		operator alt::MValue::List() { return Get<List>(); }

		void Push(MValue val) { return Get<List>().Push(val); }
	};
}
