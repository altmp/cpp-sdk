#pragma once

#include "CEvent.h"
#include "../objects/IBaseObject.h"

namespace alt
{
	class CCreateBaseObjectEvent : public CEvent
	{
	public:
		CCreateBaseObjectEvent(const std::shared_ptr<IBaseObject>& _target) :
			CEvent(Type::CREATE_BASE_OBJECT_EVENT),
			target(_target)
		{

		}

		IBaseObject* GetObject() const { return target.get(); }

	private:
		std::shared_ptr<IBaseObject> target;
	};
}
