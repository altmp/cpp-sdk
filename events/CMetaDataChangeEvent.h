#pragma once

#include "../types/StringView.h"
#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
	class IEntity;

	class CMetaChangeEvent : public CEvent
	{
	public:
		CMetaChangeEvent(IEntity* _target, StringView _key, MValue _val) :
			CEvent(Type::META_CHANGE),
			target(_target),
			key(_key),
			val(_val)
		{

		}

		IEntity* GetTarget() const { return target; }
		StringView GetKey() const { return key; }
		MValue GetVal() const { return val; }

	private:
		IEntity* target;
		String key;
		MValue val;
	};
}
