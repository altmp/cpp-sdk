#pragma once

#include "deps/alt-math/alt-math.h"
#include "types/RGBA.h"
#include "types/Array.h"
#include "types/MValue.h"
#include "types/StringView.h"
#include "Ref.h"

#include "events/CEvent.h"
#include "IResource.h"
#include "IPackage.h"
#include "IDiscordManager.h"

#include "script-objects/IBlip.h"
#include "script-objects/ICheckpoint.h"
#include "script-objects/IColShape.h"
#include "script-objects/IWebView.h"
#include "script-objects/IStatData.h"
#include "script-objects/IHandlingData.h"
#include "script-objects/INative.h"
#include "script-objects/IMapData.h"

#include "types/KeyState.h"
#include "types/Permissions.h"

namespace alt
{
	class IGFX;
	class IEntity;
	class IPlayer;
	class IVehicle;
	class ICheckpoint;
	class IScriptRuntime;
	class IVoiceChannel;

	using EventCallback = bool (*)(const CEvent *e, void *userData);
	using TickCallback = void (*)(void *userData);
	using CommandCallback = void (*)(StringView cmd, Array<StringView> args, void *userData);

	static constexpr int32_t DEFAULT_DIMENSION = 0;
	static constexpr int32_t GLOBAL_DIMENSION = -2147483648;

	class ICore
	{
	public:
#ifdef ALT_SERVER_API
		static constexpr uint32_t SDK_VERSION = 47;
#else
		static constexpr uint32_t SDK_VERSION = 46;
#endif

		// Shared methods
		virtual String GetVersion() const = 0;
		virtual String GetBranch() const = 0;

		virtual void LogInfo(StringView str) = 0;
		virtual void LogDebug(StringView str) = 0;
		virtual void LogWarning(StringView str) = 0;
		virtual void LogError(StringView str) = 0;
		virtual void LogColored(StringView str) = 0;

		virtual MValueNone CreateMValueNone() = 0;
		virtual MValueNil CreateMValueNil() = 0;
		virtual MValueBool CreateMValueBool(bool val) = 0;
		virtual MValueInt CreateMValueInt(int64_t val) = 0;
		virtual MValueUInt CreateMValueUInt(uint64_t val) = 0;
		virtual MValueDouble CreateMValueDouble(double val) = 0;
		virtual MValueString CreateMValueString(String val) = 0;
		virtual MValueList CreateMValueList(Size size = 0) = 0;
		virtual MValueDict CreateMValueDict() = 0;
		virtual MValueBaseObject CreateMValueBaseObject(Ref<IBaseObject> val) = 0;
		virtual MValueFunction CreateMValueFunction(IMValueFunction::Impl *impl) = 0;
		virtual MValueVector3 CreateMValueVector3(Vector3f val) = 0;
		virtual MValueRGBA CreateMValueRGBA(RGBA val) = 0;
		virtual MValueByteArray CreateMValueByteArray(const uint8_t *data, Size size) = 0;
		virtual MValueByteArray CreateMValueByteArray(Size size) = 0;

		virtual bool IsDebug() const = 0;

		virtual uint32_t Hash(StringView str) const = 0;

		virtual bool RegisterScriptRuntime(StringView resourceType, IScriptRuntime *runtime) = 0;

		virtual void SubscribeEvent(CEvent::Type ev, EventCallback cb, void *userData = nullptr) = 0;
		virtual void SubscribeTick(TickCallback cb, void *userData = nullptr) = 0;
		virtual bool SubscribeCommand(StringView cmd, CommandCallback cb, void *userData = nullptr) = 0;

		virtual bool FileExists(StringView path) = 0;
		virtual String FileRead(StringView path) = 0;

		virtual IResource *GetResource(StringView name) = 0;

		virtual Ref<IEntity> GetEntityByID(uint16_t id) const = 0;

		virtual Array<Ref<IEntity>> GetEntities() const = 0;
		virtual Array<Ref<IPlayer>> GetPlayers() const = 0;
		virtual Array<Ref<IVehicle>> GetVehicles() const = 0;

		virtual void TriggerLocalEvent(StringView ev, MValueArgs args) = 0;

		virtual bool HasMetaData(StringView key) const = 0;
		virtual MValueConst GetMetaData(StringView key) const = 0;
		virtual void SetMetaData(StringView key, MValue val) = 0;
		virtual void DeleteMetaData(StringView key) = 0;

		virtual bool HasSyncedMetaData(StringView key) const = 0;
		virtual MValueConst GetSyncedMetaData(StringView key) const = 0;

		virtual const Array<Permission> GetRequiredPermissions() const = 0;
		virtual const Array<Permission> GetOptionalPermissions() const = 0;

		virtual void DestroyBaseObject(Ref<IBaseObject> handle) = 0;

#ifdef ALT_CLIENT_API // Client methods
		virtual IDiscordManager *GetDiscordManager() const = 0;
		virtual IStatData *GetStatData(StringView statname) const = 0;
		virtual IHandlingData *GetHandlingData(uint32_t modelHash) const = 0;
		virtual IGFX* GetGFX() const = 0;

		virtual alt::IPackage::PathInfo Resolve(IResource *resource, alt::StringView path, StringView currentModulePath) const = 0;

		virtual void TriggerServerEvent(StringView ev, MValueArgs args) = 0;

		virtual Ref<IPlayer> GetLocalPlayer() const = 0;

		virtual bool IsSandbox() const = 0;
		virtual KeyState GetKeyState(uint32_t keyCode) const = 0;
		virtual bool AreControlsEnabled() const = 0;
		virtual Vector2i GetCursorPosition() const = 0;
		virtual void SetCursorPosition(Vector2i pos) = 0;

		virtual bool SetConfigFlag(StringView flag, bool state) = 0;
		virtual bool GetConfigFlag(StringView flag) const = 0;
		virtual bool DoesConfigFlagExist(StringView flag) const = 0;

		virtual void SetVoiceInputMuted(bool state) = 0;
		virtual bool IsVoiceInputMuted() const = 0;
		virtual bool IsVoiceActivationEnabled() const = 0;
		virtual void ToggleVoiceControls(bool state) = 0;

		virtual String GetLicenseHash() const = 0;
		virtual String GetLocale() const = 0;
		virtual bool IsInStreamerMode() const = 0;
		virtual bool IsMenuOpen() const = 0;
		virtual bool IsConsoleOpen() const = 0;

		virtual const Array<INative *> GetAllNatives() const = 0;
		virtual Ref<INative::Context> CreateNativesContext() const = 0;

		virtual Ref<IEntity> GetEntityByScriptGuid(int32_t scriptGuid) const = 0;

		virtual void *GetTextureFromDrawable(uint32_t modelHash, StringView targetTextureName) const = 0;

		virtual void RequestIPL(StringView ipl) = 0;
		virtual void RemoveIPL(StringView ipl) = 0;

		virtual bool BeginScaleformMovieMethodMinimap(StringView methodName) = 0;

		virtual int32_t GetMsPerGameMinute() const = 0;
		virtual void SetMsPerGameMinute(int32_t val) = 0;
		virtual void SetWeatherCycle(alt::Array<uint8_t> weathers, alt::Array<uint8_t> multipliers) = 0;
		virtual void SetWeatherSyncActive(bool active) = 0;

		virtual void SetCamFrozen(bool frozen) = 0;

		virtual alt::Ref<alt::IMapData> GetMapData(uint8_t zoomDataId) = 0;
		virtual alt::Ref<alt::IMapData> GetMapData(StringView alias) = 0;
		virtual uint8_t GetMapDataIDFromAlias(StringView alias) = 0;
		virtual void ResetMapData(uint8_t zoomDataId) = 0;
		virtual void ResetMapData(StringView alias) = 0;
		virtual void ResetAllMapData() = 0;

		virtual PermissionState GetPermissionState(Permission permission) const = 0;

		using TakeScreenshotCallback = void (*)(StringView base64, const void *userData);
		/**
		 * This is an async operation.
		 * @param callback will be called when the screenshot has been taken.
		 * The screenshot is taken exactly after the webviews has rendered.
		 */
		virtual PermissionState TakeScreenshot(TakeScreenshotCallback callback, const void *userData) const = 0;

		/**
		 * This is an async operation.
		 * @param callback will be called when the screenshot has been taken.
		 * The screenshot is taken exactly after GTA:V has rendered it's stuff and before alt:V renders anything custom.
		 */
		virtual PermissionState TakeScreenshotGameOnly(TakeScreenshotCallback callback, const void *userData) const = 0;


		virtual Ref<IWebView> CreateWebView(IResource* res, StringView url, uint32_t drawableHash, StringView targetTexture) = 0;
		virtual Ref<IWebView> CreateWebView(IResource* res, StringView url, Vector2i position, Vector2i size, bool isVisible, bool isOverlay) = 0;
		virtual Ref<IBlip> CreateBlip(IBlip::BlipType type, Vector3f position) = 0;
		virtual Ref<IBlip> CreateBlip(IBlip::BlipType type, uint32_t entityID) = 0;
		virtual Ref<IBlip> CreateBlip(Vector3f position, float radius) = 0;
		virtual Ref<IBlip> CreateBlip(Vector3f position, float width, float height) = 0;
		virtual Ref<ICheckpoint> CreateCheckpoint(uint8_t type, Vector3f pos, Vector3f next, float radius, float height, alt::RGBA color) = 0;

		virtual void SetAngularVelocity(uint32_t, alt::Vector4f) = 0;
#endif

#ifdef ALT_SERVER_API // Server methods
		virtual StringView GetRootDirectory() = 0;

		virtual IResource *StartResource(StringView name) = 0;
		virtual void StopResource(StringView name) = 0;
		virtual IResource *RestartResource(StringView name) = 0;

		virtual void TriggerClientEvent(Ref<IPlayer> target, StringView ev, MValueArgs args) = 0;

		virtual void SetSyncedMetaData(StringView key, MValue val) = 0;
		virtual void DeleteSyncedMetaData(StringView key) = 0;

		virtual Ref<IVehicle> CreateVehicle(uint32_t model, Position pos, Rotation rot) = 0;

		// TODO make enum for types
		virtual Ref<ICheckpoint> CreateCheckpoint(uint8_t type, Position pos, float radius, float height, RGBA color) = 0;

		virtual Ref<IBlip> CreateBlip(Ref<IPlayer> target, IBlip::BlipType type, Position pos) = 0;
		virtual Ref<IBlip> CreateBlip(Ref<IPlayer> target, IBlip::BlipType type, Ref<IEntity> attachTo) = 0;

		virtual Ref<IVoiceChannel> CreateVoiceChannel(bool spatial, float maxDistance) = 0;

		virtual Ref<IColShape> CreateColShapeCylinder(Position pos, float radius, float height) = 0;
		virtual Ref<IColShape> CreateColShapeSphere(Position pos, float radius) = 0;
		virtual Ref<IColShape> CreateColShapeCircle(Position pos, float radius) = 0;
		virtual Ref<IColShape> CreateColShapeCube(Position pos, Position pos2) = 0;
		virtual Ref<IColShape> CreateColShapeRectangle(float x1, float y1, float x2, float y2, float z) = 0;

		virtual Array<Ref<IPlayer>> GetPlayersByName(StringView name) const = 0;

		virtual uint32_t GetNetTime() const = 0;
#endif

		static ICore &Instance()
		{
			return *_instance();
		}
		static void SetInstance(ICore *server) { _instance() = server; }

	protected:
		virtual ~ICore() = default;

	private:
		static ICore *&_instance()
		{
			static ICore *instance = nullptr;
			return instance;
		}
	};
} // namespace alt

#ifdef ALT_CLIENT_API
#include "IGFX.h"
#endif
