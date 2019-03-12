#pragma once

#include "types/StringView.h"

namespace alt
{
	class IPackage;
	class IResource;

	class IScriptRuntime
	{
	public:
		virtual ~IScriptRuntime() = default;

		virtual IResource* CreateResource(IResource::CreationInfo* info) = 0;
		virtual void RemoveResource(IResource* resource) = 0;

		virtual void OnTick() { };
	};
}