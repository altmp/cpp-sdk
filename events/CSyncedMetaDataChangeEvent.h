#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
	class IBaseObject;

	class CSyncedMetaDataChangeEvent : public CEvent
	{
	public:
		CSyncedMetaDataChangeEvent(const std::shared_ptr<IBaseObject>& _target, const std::string& _key, MValueConst _val, MValueConst _oldVal) :
			CEvent(Type::SYNCED_META_CHANGE),
			target(_target),
			key(_key),
			val(_val),
			oldVal(_oldVal)
		{

		}

		IBaseObject* GetTarget() const { return target.get(); }
		std::string GetKey() const { return key; }
		MValueConst GetVal() const { return val; }
		MValueConst GetOldVal() const { return oldVal; }

	private:
		std::shared_ptr<IBaseObject> target;
		std::string key;
		MValueConst val;
		MValueConst oldVal;
	};
}
