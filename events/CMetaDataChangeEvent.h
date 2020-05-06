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
		CMetaChangeEvent(Ref<IEntity> _target, StringView _key, MValueConst _val, MValueConst _oldVal) :
			CEvent(Type::META_CHANGE),
			target(_target),
			key(_key),
			val(_val),
			oldVal(_oldVal)
		{

		}

		Ref<IEntity> GetTarget() const { return target; }
		StringView GetKey() const { return key; }
		MValueConst GetVal() const { return val; }
		MValueConst GetOldVal() const { return oldVal; }

	private:
		Ref<IEntity> target;
		String key;
		MValueConst val;
		MValueConst oldVal;
	};
}
