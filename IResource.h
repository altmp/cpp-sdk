#pragma once

#include "types/StringView.h"
#include "types/String.h"
#include "types/MValue.h"
#include "types/Permissions.h"
#include "ILocalStorage.h"
#include "script-objects/IWebView.h"
#include "script-objects/IBlip.h"

namespace alt
{
	class IScriptRuntime;
	class IPackage;
	class CEvent;

	class IResource
	{
	protected:
		virtual ~IResource() = default;

	public:
		struct CreationInfo
		{
			String type;
			String name;
			String main;
			IPackage *pkg;
		};

		class Impl
		{
		public:
#ifdef ALT_SERVER_API
			virtual bool MakeClient(CreationInfo *info, Array<String> files)
			{
				return true;
			};
#endif
			virtual bool Start()
			{
				return true;
			};
			virtual bool Stop() { return true; };

			virtual bool OnEvent(const CEvent *ev) { return true; };
			virtual void OnTick(){};

			virtual void OnCreateBaseObject(Ref<IBaseObject> object){};
			virtual void OnRemoveBaseObject(Ref<IBaseObject> object){};

			virtual ~Impl() = default;
		};

		virtual IScriptRuntime *GetRuntime() const = 0;
		virtual Impl *GetImpl() const = 0;

		virtual bool IsStarted() const = 0;

		virtual StringView GetType() const = 0;
		virtual StringView GetName() const = 0;
		virtual StringView GetPath() const = 0;
		virtual StringView GetMain() const = 0;
		virtual IPackage *GetPackage() const = 0;
		virtual MValueDict GetExports() const = 0;
		virtual const Array<StringView> GetDependencies() const = 0;
		virtual const Array<StringView> GetDependants() const = 0;
		virtual const Array<Permission> GetRequiredPermissions() const = 0;
		virtual const Array<Permission> GetOptionalPermissions() const = 0;

		virtual void SetExports(MValueDict exports) = 0;

#ifdef ALT_CLIENT_API
		virtual ILocalStorage *GetLocalStorage() const = 0;
		virtual void EnableNatives(alt::IResource::Impl*) = 0;
		virtual void PushNativeUpdate() = 0;

		virtual Ref<IWebView> CreateWebView(StringView url, uint32_t drawableHash, StringView targetTexture) = 0;
		virtual Ref<IWebView> CreateWebView(StringView url, Vector2i position, Vector2i size, bool isVisible, bool isOverlay) = 0;
		virtual Ref<IBlip> CreateBlip(IBlip::BlipType type, Vector3f position) = 0;
		virtual Ref<IBlip> CreateBlip(IBlip::BlipType type, uint32_t entityID) = 0;
		virtual Ref<IBlip> CreateBlip(Vector3f position, float radius) = 0;
		virtual Ref<IBlip> CreateBlip(Vector3f position, float width, float height) = 0;
#endif
	};
} // namespace alt
