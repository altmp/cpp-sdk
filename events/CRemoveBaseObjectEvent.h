#pragma once

#include "CEvent.h"
#include "../objects/IBaseObject.h"

namespace alt
{
	class CRemoveBaseObjectEvent : public CEvent
	{
	public:
		CRemoveBaseObjectEvent(const std::shared_ptr<IBaseObject>& _target) :
			CEvent(Type::REMOVE_BASE_OBJECT_EVENT),
			target(_target)
		{

		}

		IBaseObject* GetObject() const { return target.get(); }

	private:
		std::shared_ptr<IBaseObject> target;
	};
}
