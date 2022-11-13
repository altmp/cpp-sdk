#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
	class IEntity;

	class CStreamSyncedMetaDataChangeEvent : public CEvent
	{
	public:
		CStreamSyncedMetaDataChangeEvent(IEntity* _target, const std::string& _key, MValueConst _val, MValueConst _oldVal) :
			CEvent(Type::STREAM_SYNCED_META_CHANGE),
			target(_target),
			key(_key),
			val(_val),
			oldVal(_oldVal)
		{

		}

		IEntity* GetTarget() const { return target; }
		std::string GetKey() const { return key; }
		MValueConst GetVal() const { return val; }
		MValueConst GetOldVal() const { return oldVal; }

	private:
		IEntity* target;
		std::string key;
		MValueConst val;
		MValueConst oldVal;
	};
}
