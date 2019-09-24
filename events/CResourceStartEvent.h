#pragma once

#include "../IResource.h"

#include "CEvent.h"

namespace alt
{
	class CResourceStartEvent : public CEvent
	{
	public:
		CResourceStartEvent(IResource* _resource) :
			CEvent(Type::RESOURCE_START),
			resource(_resource)
		{

		}

		IResource* GetResource() const { return resource; }

	private:
		IResource* resource;
	};
}
