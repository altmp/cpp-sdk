#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
	class CGlobalSyncedMetaDataChangeEvent : public CEvent
	{
	public:
		CGlobalSyncedMetaDataChangeEvent(const std::string _key, MValueConst _val, MValueConst _oldVal) :
			CEvent(Type::GLOBAL_SYNCED_META_CHANGE),
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
