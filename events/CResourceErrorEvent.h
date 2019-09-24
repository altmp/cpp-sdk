#pragma once

#include "../IResource.h"

#include "CEvent.h"

namespace alt
{
	class CResourceErrorEvent : public CEvent
	{
	public:
		CResourceErrorEvent(IResource* _resource) :
			CEvent(Type::RESOURCE_ERROR),
			resource(_resource)
		{

		}

		IResource* GetResource() const { return resource; }

	private:
		IResource* resource;
	};
}

