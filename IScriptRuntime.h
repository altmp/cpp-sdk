#pragma once

#include "types/StringView.h"
#include "IResource.h"

namespace alt
{
	class IPackage;

	class IScriptRuntime
	{
	public:
		virtual ~IScriptRuntime() = default;

		virtual bool RequiresMain() const { return true; }

		virtual IResource::Impl* CreateImpl(IResource* resource) = 0;
		virtual void DestroyImpl(IResource::Impl* impl) = 0;

		virtual void OnTick() { };
		virtual void OnDispose() { };

#ifdef ALT_SERVER_API
		virtual bool GetProcessClientType(std::string& clientType) { return false; }
		virtual void ProcessClientFile(IResource* resource, IPackage* clientPackage) { };
#endif
	};
}