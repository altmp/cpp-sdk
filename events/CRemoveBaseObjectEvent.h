#pragma once

#include "CEvent.h"
#include "../Ref.h"
#include "../objects/IBaseObject.h"

namespace alt
{
	class CRemoveBaseObjectEvent : public CEvent
	{
	public:
		CRemoveBaseObjectEvent(Ref<IBaseObject> _target) :
			CEvent(Type::REMOVE_BASE_OBJECT_EVENT),
			target(_target)
		{

		}

		Ref<IBaseObject> GetObject() const { return target; }

	private:
		Ref<IBaseObject> target;
	};
}
