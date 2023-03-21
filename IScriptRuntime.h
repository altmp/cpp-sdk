#pragma once

#include "IResource.h"

#include <cstdint>
#include <functional>

namespace alt
{
	enum InitState: uint8_t
	{
		DownloadingResources = 0,
		ValidatingResources,
		DownloadingRuntime,
		ValidatingRuntime,
		DownloadingAdditionalResources
	};

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

#ifdef ALT_CLIENT_API
		// Called every time when connecting to a server
		virtual void Init(std::function<void(bool success, std::string error)> next, std::function<void(InitState state, float progress, float total)> setProgress)
		{
			next(true, "");
		}
#endif
	};
}