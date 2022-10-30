#pragma once

#include "CEvent.h"
#include "../Ref.h"
#include "../objects/IBaseObject.h"

namespace alt
{
	class CCreateBaseObjectEvent : public CEvent
	{
	public:
		CCreateBaseObjectEvent(IBaseObject* _target) :
			CEvent(Type::CREATE_BASE_OBJECT_EVENT),
			target(_target)
		{

		}

		IBaseObject* GetObject() const { return target; }

	private:
		IBaseObject* target;
	};
}
