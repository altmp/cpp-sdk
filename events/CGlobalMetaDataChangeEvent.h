#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
	class CGlobalMetaDataChangeEvent : public CEvent
	{
	public:
		CGlobalMetaDataChangeEvent(const std::string _key, MValueConst _val, MValueConst _oldVal) :
			CEvent(Type::GLOBAL_META_CHANGE),
			key(_key),
			val(_val),
			oldVal(_oldVal)
		{

		}

		std::string GetKey() const { return key; }
		MValueConst GetVal() const { return val; }
		MValueConst GetOldVal() const { return oldVal; }

	private:
		std::string key;
		MValueConst val;
		MValueConst oldVal;
	};
}
