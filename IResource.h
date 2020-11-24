#pragma once

#include "types/StringView.h"
#include "types/String.h"
#include "types/MValue.h"
#include "types/Permissions.h"
#include "ILocalStorage.h"
#include "script-objects/IWebView.h"
#include "script-objects/IBlip.h"
#include "script-objects/ICheckpoint.h"
#include "script-objects/INative.h"

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
			
			/**
			 * Clientside:
			 * If natives are enabled, it is not necessary to call PushNatives() to make natives invokable.
			 * */
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
		virtual void EnableNatives() = 0;
		virtual Ref<INative::Context> CreateNativesContext() const = 0;
		virtual Ref<INative::Scope> PushNativesScope() = 0;

		virtual ILocalStorage *GetLocalStorage() = 0;

		virtual uint64_t RemoveReference(Ref<CRefCountable> ref) = 0;
#endif
	};
} // namespace alt
