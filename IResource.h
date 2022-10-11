#pragma once

#include "types/MValue.h"
#include "types/Permissions.h"
#include "ILocalStorage.h"
#include "script-objects/IWebView.h"
#include "script-objects/IWebSocketClient.h"
#include "script-objects/IBlip.h"
#include "script-objects/ICheckpoint.h"
#include "script-objects/INative.h"
#include "deps/alt-config/alt-config.h"
#include <vector>
#include <set>

#include "deps/ConfigBase.h"

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
			std::string type;
			std::string name;
			std::string main;
			IPackage *pkg;
		};

		class Impl
		{
		public:
#ifdef ALT_SERVER_API
			virtual bool MakeClient(CreationInfo *info, Array<std::string> files)
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

		virtual const std::string& GetType() const = 0;
		virtual const std::string& GetName() const = 0;
		virtual const std::string& GetPath() const = 0;
		virtual const std::string& GetMain() const = 0;
		virtual IPackage *GetPackage() const = 0;
		virtual MValueDict GetExports() const = 0;
		virtual const Array<std::string> GetDependencies() const = 0;
		virtual const Array<std::string> GetDependants() const = 0;
		virtual const Array<Permission> GetRequiredPermissions() const = 0;
		virtual const Array<Permission> GetOptionalPermissions() const = 0;

		virtual void SetExports(MValueDict exports) = 0;

#ifdef ALT_SERVER_API
		virtual std::string GetClientType() const = 0;
		virtual std::string GetClientMain() const = 0;
		virtual const std::vector<std::string>& GetClientFiles() const = 0;
		virtual Config::Value::ValuePtr GetConfig() const = 0;
		virtual std::set<std::string> GetMatchedFiles(const std::vector<std::string>& patterns) = 0;
#endif

#ifdef ALT_CLIENT_API
		virtual void EnableNatives() = 0;
		[[nodiscard]]
		virtual Ref<INative::Context> CreateNativesContext() const = 0;
		[[nodiscard]]
		virtual Ref<INative::Scope> PushNativesScope() = 0;

		virtual ILocalStorage *GetLocalStorage() = 0;

		virtual void AddGxtText(uint32_t hash, const std::string& text) = 0;
		virtual void RemoveGxtText(uint32_t hash) = 0;
		virtual const std::string& GetGxtText(uint32_t hash) = 0;
		virtual bool ToggleCursor(bool state) = 0;
		virtual void ToggleGameControls(bool state) = 0;
		virtual bool CursorVisible() = 0;
		virtual bool GameControlsActive() = 0;
#endif
	};
} // namespace alt
