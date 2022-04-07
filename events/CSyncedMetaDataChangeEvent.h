#pragma once

#include "../types/MValue.h"
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IEntity;

	class CSyncedMetaDataChangeEvent : public CEvent
	{
	public:
		CSyncedMetaDataChangeEvent(Ref<IEntity> _target, const std::string& _key, MValueConst _val, MValueConst _oldVal) :
			CEvent(Type::SYNCED_META_CHANGE),
			target(_target),
			key(_key),
			val(_val),
			oldVal(_oldVal)
		{

		}

		Ref<IEntity> GetTarget() const { return target; }
		std::string GetKey() const { return key; }
		MValueConst GetVal() const { return val; }
		MValueConst GetOldVal() const { return oldVal; }

	private:
		Ref<IEntity> target;
		std::string key;
		MValueConst val;
		MValueConst oldVal;
	};
}
