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
		virtual void WriteClientFile(IResource* resource, IPackage* package, const std::string& fileName, void* buffer, uint64_t size) { };
#endif
	};
}