#pragma once

#include "../IResource.h"

#include "CEvent.h"

namespace alt
{
	class CResourceStopEvent : public CEvent
	{
	public:
		CResourceStopEvent(IResource* _resource) :
			CEvent(Type::RESOURCE_STOP),
			resource(_resource)
		{

		}

		IResource* GetResource() const { return resource; }

	private:
		IResource* resource;
	};
}
