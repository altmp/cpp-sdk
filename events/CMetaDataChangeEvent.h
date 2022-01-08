#pragma once

#include "../types/StringView.h"
#include "../types/MValue.h"
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IEntity;

	class CMetaChangeEvent : public CEvent
	{
	public:
		CMetaChangeEvent(Ref<IEntity> _target, const std::string _key, MValueConst _val, MValueConst _oldVal) :
			CEvent(Type::META_CHANGE),
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
