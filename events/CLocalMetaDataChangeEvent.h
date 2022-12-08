#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CLocalMetaDataChangeEvent : public CEvent
	{
	public:
		CLocalMetaDataChangeEvent(const std::shared_ptr<IPlayer>& _target, const std::string& _key, MValueConst _val, MValueConst _oldVal) :
			CEvent(Type::LOCAL_SYNCED_META_CHANGE),
			target(_target),
			key(_key),
			val(_val),
			oldVal(_oldVal)
		{

		}

		IPlayer* GetTarget() const { return target.get(); }
		std::string GetKey() const { return key; }
		MValueConst GetVal() const { return val; }
		MValueConst GetOldVal() const { return oldVal; }

	private:
		std::shared_ptr<IPlayer> target;
		std::string key;
		MValueConst val;
		MValueConst oldVal;
	};
}
