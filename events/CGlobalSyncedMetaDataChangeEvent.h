#pragma once

#include "../types/StringView.h"
#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
	class CGlobalSyncedMetaDataChangeEvent : public CEvent
	{
	public:
		CGlobalSyncedMetaDataChangeEvent(StringView _key, MValue _val) :
			CEvent(Type::GLOBAL_SYNCED_META_CHANGE),
			key(_key),
			val(_val)
		{

		}

		StringView GetKey() const { return key; }
		MValue GetVal() const { return val; }

	private:
		String key;
		MValue val;
	};
}
