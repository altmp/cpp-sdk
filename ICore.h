#pragma once

#include <climits>
#include <memory>
#include <vector>
#include <unordered_map>

#include "deps/alt-math/alt-math.h"
#include "deps/alt-config/alt-config.h"
#include "deps/ConfigBase.h"
#include "types/RGBA.h"
#include "types/MValue.h"
#include "types/Metric.h"
#include "types/WebView.h"

#include "events/CEvent.h"
#include "IResource.h"
#include "IPackage.h"
#include "IDiscordManager.h"
#include "events/CVoiceConnectionEvent.h"

#include "objects/ILocalPlayer.h"
#include "objects/IPed.h"
#include "objects/IObject.h"

#include "script-objects/IBlip.h"
#include "script-objects/ICheckpoint.h"
#include "script-objects/IColShape.h"
#include "script-objects/IWebView.h"
#include "script-objects/IStatData.h"
#include "script-objects/IHandlingData.h"
#include "script-objects/IInterior.h"
#include "script-objects/IAudioCategory.h"
#include "script-objects/INative.h"
#include "script-objects/IMapData.h"
#include "script-objects/IHttpClient.h"
#include "script-objects/IAudio.h"
#include "script-objects/IAudioOutput.h"
#include "script-objects/IAudioFrontendOutput.h"
#include "script-objects/IAudioWorldOutput.h"
#include "script-objects/IAudioAttachedOutput.h"
#include "script-objects/ILocalObject.h"
#include "script-objects/IRml.h"
#include "script-objects/IWeaponData.h"
#include "script-objects/IVirtualEntity.h"
#include "script-objects/IVirtualEntityGroup.h"
#include "script-objects/IMarker.h"
#include "script-objects/ITextLabel.h"
#include "script-objects/IAudioFilter.h"
#include "script-objects/IFont.h"

#include "types/KeyState.h"
#include "types/Permissions.h"
#include "types/VehicleModelInfo.h"
#include "types/WeaponModelInfo.h"
#include "types/PedModelInfo.h"
#include "types/VoiceChat.h"
#include "types/Benefit.h"

#include "common/Order.h"

namespace alt
{
	class IEntity;
	class IPlayer;
	class IVehicle;
	class ICheckpoint;
	class IScriptRuntime;
	class IVoiceChannel;
	class ILocalPlayer;
	class IAudioFilter;
	class ILocalVehicle;
	class ILocalPed;
	class IConnectionInfo;
	class ICustomTexture;

	using CommandCallback = std::function<void(const std::vector<std::string>& args)>;

	static constexpr int32_t DEFAULT_DIMENSION = 0;
	static constexpr int32_t GLOBAL_DIMENSION = INT_MIN;

	class ICore
	{
	public:
		// Shared methods
		virtual std::string GetVersion() const = 0;
		virtual std::string GetBranch() const = 0;

		virtual void LogInfo(const std::string& prefix, const std::string& str, IResource* resource = nullptr) = 0;
		virtual void LogDebug(const std::string& prefix, const std::string& str, IResource* resource = nullptr) = 0;
		virtual void LogWarning(const std::string& prefix, const std::string& str, IResource* resource = nullptr) = 0;
		virtual void LogError(const std::string& prefix, const std::string& str, IResource* resource = nullptr) = 0;
		virtual void LogColored(const std::string& prefix, const std::string& str, IResource* resource = nullptr) = 0;

		virtual MValueNone CreateMValueNone() = 0;
		virtual MValueNil CreateMValueNil() = 0;
		virtual MValueBool CreateMValueBool(bool val) = 0;
		virtual MValueInt CreateMValueInt(int64_t val) = 0;
		virtual MValueUInt CreateMValueUInt(uint64_t val) = 0;
		virtual MValueDouble CreateMValueDouble(double val) = 0;
		virtual MValueString CreateMValueString(const std::string& val) = 0;
		virtual MValueString CreateMValueString(const char* val) = 0;
		virtual MValueList CreateMValueList(Size size = 0) = 0;
		virtual MValueDict CreateMValueDict() = 0;
		virtual MValueBaseObject CreateMValueBaseObject(IBaseObject* val) = 0;
		virtual MValueBaseObject CreateMValueBaseObject(std::shared_ptr<IBaseObject> val) = 0;
		virtual MValueFunction CreateMValueFunction(IMValueFunction::Impl *impl) = 0;
		virtual MValueVector2 CreateMValueVector2(Vector2f val) = 0;
		virtual MValueVector3 CreateMValueVector3(Vector3f val) = 0;
		virtual MValueRGBA CreateMValueRGBA(RGBA val) = 0;
		virtual MValueByteArray CreateMValueByteArray(const uint8_t *data, Size size) = 0;
		virtual MValueByteArray CreateMValueByteArray(Size size) = 0;
		virtual alt::Size GetMValueSize(MValue mValue) = 0;
		virtual alt::Size GetMValueArgsSize(MValueArgs mValue) = 0;

		virtual IVirtualEntity* CreateVirtualEntity(IVirtualEntityGroup* group, Position pos, uint32_t streamingDistance, std::unordered_map<std::string, MValue> data) = 0;
		virtual IVirtualEntityGroup* CreateVirtualEntityGroup(uint32_t maxEntitiesInStream, const std::string& name = "") = 0;

		virtual IColShape* CreateColShapeCylinder(Position pos, float radius, float height) = 0;
		virtual IColShape* CreateColShapeSphere(Position pos, float radius) = 0;
		virtual IColShape* CreateColShapeCircle(Position pos, float radius) = 0;
		virtual IColShape* CreateColShapeCube(Position pos, Position pos2) = 0;
		virtual IColShape* CreateColShapeRectangle(float x1, float y1, float x2, float y2, float z) = 0;
		virtual IColShape* CreateColShapePolygon(float minZ, float maxZ, std::vector<Vector2f> points) = 0;

		virtual bool IsDebug() const = 0;

		virtual uint32_t Hash(const std::string& str) const = 0;

		virtual bool RegisterScriptRuntime(const std::string& resourceType, IScriptRuntime *runtime) = 0;

		virtual bool SubscribeCommand(const std::string& cmd, CommandCallback cb) = 0;

		virtual bool FileExists(const std::string& path) = 0;
		virtual std::string FileRead(const std::string& path) = 0;

		virtual IResource *GetResource(const std::string& name) = 0;

		virtual IEntity* GetEntityBySyncID(uint16_t id) const = 0;
		virtual IBaseObject* GetBaseObjectByID(alt::IBaseObject::Type type, uint32_t id) const = 0;

		virtual std::vector<IBaseObject*> GetBaseObjects(alt::IBaseObject::Type type) const = 0;
		virtual std::vector<IEntity*> GetEntities() const = 0;

		virtual void TriggerLocalEvent(const std::string& ev, MValueArgs args) = 0;
		virtual void TriggerLocalEventOnMain(const std::string& ev, MValueArgs args) = 0;

		virtual bool HasMetaData(const std::string& key) const = 0;
		virtual MValueConst GetMetaData(const std::string& key) const = 0;
		virtual void SetMetaData(const std::string& key, MValue val) = 0;
		virtual void DeleteMetaData(const std::string& key) = 0;
		virtual std::vector<std::string> GetMetaDataKeys() const = 0;

		virtual bool HasSyncedMetaData(const std::string& key) const = 0;
		virtual MValueConst GetSyncedMetaData(const std::string& key) const = 0;
		virtual std::vector<std::string> GetSyncedMetaDataKeys() const = 0;

		virtual const std::vector<Permission> GetRequiredPermissions() const = 0;
		virtual const std::vector<Permission> GetOptionalPermissions() const = 0;

        virtual alt::IPackage::PathInfo Resolve(IResource *resource, const std::string& path, const std::string& currentModulePath) const = 0;

		virtual void DestroyBaseObject(IBaseObject* handle) = 0;

		virtual const std::vector<IResource*> GetAllResources() const = 0;

		virtual std::string StringToSHA256(const std::string& str) const = 0;

		virtual bool IsEventEnabled(alt::CEvent::Type type) const = 0;
		virtual void ToggleEvent(alt::CEvent::Type type, bool state) = 0;
		
		virtual CVoiceConnectionEvent::State GetVoiceConnectionState() const = 0;

		virtual uint32_t GetNetTime() const = 0;

#ifdef ALT_CLIENT_API // Client methods
		virtual uint64_t GetServerTime() const = 0;
		virtual IDiscordManager *GetDiscordManager() const = 0;
		virtual IStatData *GetStatData(const std::string& statname) const = 0;
		virtual std::shared_ptr<alt::IHandlingData> GetHandlingData(uint32_t modelHash) const = 0;
		virtual std::shared_ptr<alt::IWeaponData> GetWeaponData(uint32_t weaponHash) const = 0;
		virtual std::vector<std::shared_ptr<alt::IWeaponData>> GetAllWeaponData() const = 0;
		virtual std::shared_ptr<alt::IAudioCategory> GetAudioCategory(const std::string& name) const = 0;

		virtual std::shared_ptr<alt::IInterior> GetInterior(uint32_t interiorId) const = 0;

		virtual void TriggerServerEvent(const std::string& ev, MValueArgs args) = 0;
		virtual void TriggerServerEventUnreliable(const std::string& ev, MValueArgs args) = 0;
        /**
		 * Triggers server rpc answer
		 *
		 * This is only needed to be called when rpc event is answered with WillAnswer()
		 * The rpc is answered automatically when its Answer() method is called
		 *
		 * @param answerID answerID from the event
		 * @param args answer args
		 * @param error error string
		 */
		virtual void TriggerServerRPCAnswer(uint16_t answerID, MValue args, const std::string& error) = 0;
		virtual uint16_t TriggerServerRPCEvent(const std::string& ev, MValueArgs args) = 0;

		virtual ILocalPlayer* GetLocalPlayer() const = 0;

		virtual KeyState GetKeyState(uint32_t keyCode) const = 0;
		virtual bool AreControlsEnabled() const = 0;
		virtual Vector2f GetCursorPosition(bool normalized = false) const = 0;
		virtual void SetCursorPosition(Vector2f pos, bool normalized = false) = 0;

		virtual bool SetConfigFlag(const std::string& flag, bool state) = 0;
		virtual bool GetConfigFlag(const std::string& flag) const = 0;
		virtual bool DoesConfigFlagExist(const std::string& flag) const = 0;

		virtual void SetVoiceInputMuted(bool state) = 0;
		virtual bool IsVoiceInputMuted() const = 0;
		virtual bool IsVoiceActivationEnabled() const = 0;
		virtual void ToggleVoiceControls(bool state) = 0;
		virtual bool AreVoiceControlsEnabled() const = 0;
		virtual uint32_t GetVoiceActivationKey() = 0;
		virtual bool ToggleVoiceInput(bool state) = 0;
		virtual bool ToggleVoiceActivation(bool state) = 0;
		virtual bool SetVoiceActivationLevel(float level) = 0;
		virtual float GetVoiceActivationLevel() const = 0;
		virtual bool ToggleNoiseSuppression(bool state) = 0;
		virtual bool IsNoiseSuppressionEnabled() const = 0;
		virtual bool GetActiveVoiceInputDevice(std::optional<std::string>& uid) const = 0;
		virtual bool SetActiveVoiceInputDevice(const std::optional<std::string>& uid) = 0;
		virtual bool GetVoiceInputDeviceList(std::vector<SoundDeviceInfo>& devices) const = 0;

		virtual std::string GetLicenseHash() const = 0;
		virtual std::string GetLocale() const = 0;
		virtual bool IsInStreamerMode() const = 0;
		virtual bool IsMenuOpen() const = 0;
		virtual bool IsConsoleOpen() const = 0;

		virtual std::vector<alt::INative *> GetAllNatives() const = 0;
		virtual std::shared_ptr<INative::Context> CreateNativesContext() const = 0;

		virtual INative* GetNativeByName(const std::string& name) const = 0;
		virtual INative* GetNativeByHash(uint64_t hash) const = 0;

		virtual IWorldObject* GetWorldObjectByScriptID(uint32_t scriptID) const = 0;

		virtual void *GetTextureFromDrawable(uint32_t modelHash, const std::string& targetTextureName) const = 0;

		virtual void RequestIPL(const std::string& ipl) = 0;
		virtual void RemoveIPL(const std::string& ipl) = 0;

		virtual bool BeginScaleformMovieMethodMinimap(const std::string& methodName) = 0;

		virtual int32_t GetMsPerGameMinute() const = 0;
		virtual void SetMsPerGameMinute(int32_t val) = 0;
		virtual void SetWeatherCycle(std::vector<uint8_t> weathers, std::vector<uint8_t> multipliers) = 0;
		virtual void SetWeatherSyncActive(bool active) = 0;

		virtual void SetCamFrozen(bool frozen) = 0;
		virtual bool IsCamFrozen() = 0;

		virtual std::shared_ptr<alt::IMapData> GetMapData(uint8_t zoomDataId) = 0;
		virtual std::shared_ptr<alt::IMapData> GetMapData(const std::string& alias) = 0;
		virtual uint8_t GetMapDataIDFromAlias(const std::string& alias) = 0;
		virtual void ResetMapData(uint8_t zoomDataId) = 0;
		virtual void ResetMapData(const std::string& alias) = 0;
		virtual void ResetAllMapData() = 0;

		virtual bool GetPermissionState(Permission permission) const = 0;

		using TakeScreenshotCallback = std::function<void(const std::string& base64)>;
		/**
		 * This is an async operation.
		 * @param callback will be called when the screenshot has been taken.
		 * The screenshot is taken exactly after the webviews has rendered.
		 */
		virtual bool TakeScreenshot(TakeScreenshotCallback callback) const = 0;

		/**
		 * This is an async operation.
		 * @param callback will be called when the screenshot has been taken.
		 * The screenshot is taken exactly after GTA:V has rendered it's stuff and before alt:V renders anything custom.
		 */
		virtual bool TakeScreenshotGameOnly(TakeScreenshotCallback callback) const = 0;


		virtual IWebView* CreateWebView(const std::string& url, uint32_t drawableHash, const std::string& targetTexture, IResource* res = nullptr, const WebViewHeaders& headers = {}, const std::vector<WebViewCookie>& cookies = {}) = 0;
		virtual IWebView* CreateWebView(const std::string& url, Vector2i position, Vector2i size, bool isVisible, bool isOverlay, IResource* res = nullptr, const WebViewHeaders& headers = {}, const std::vector<WebViewCookie>& cookies = {}) = 0;
		virtual IWebSocketClient* CreateWebSocketClient(const std::string& url, IResource* res = nullptr) = 0;
		virtual IHttpClient* CreateHttpClient(IResource* res = nullptr) = 0;
		virtual IBlip* CreateBlip(IBlip::BlipType type, Vector3f position, IResource* res = nullptr) = 0;
		virtual IBlip* CreateBlip(IBlip::BlipType type, uint32_t entityID, IResource* res = nullptr) = 0;
		virtual IBlip* CreateBlip(Vector3f position, float radius, IResource* res = nullptr) = 0;
		virtual IBlip* CreateBlip(Vector3f position, float width, float height, IResource* res = nullptr) = 0;
		virtual ICheckpoint* CreateCheckpoint(uint8_t type, Vector3f pos, Vector3f next, float radius, float height, alt::RGBA color, alt::RGBA iconColor, uint32_t streamingDistance, IResource* res = nullptr) = 0;
		virtual IAudio* CreateAudio(const std::string& source, float volume, bool isRadio = false, bool clearCache = true, std::string basePath = "", IResource* res = nullptr) = 0;
		virtual IAudioFilter* CreateAudioFilter(uint32_t hash, IResource* res = nullptr) = 0;
		virtual IAudioFrontendOutput* CreateFrontendOutput(uint32_t categoryHash, IResource* res = nullptr) = 0;
		virtual IAudioWorldOutput* CreateWorldOutput(uint32_t categoryHash, alt::Position pos, IResource* res = nullptr) = 0;
		virtual IAudioAttachedOutput* CreateAttachedOutput(uint32_t categoryHash, IWorldObject* entity, IResource* res = nullptr) = 0;
		virtual IRmlDocument* CreateDocument(const std::string& url, const std::string& currentPath, IResource* res = nullptr) = 0;
		virtual IMarker* CreateMarker(IMarker::MarkerType type, Vector3f position, alt::RGBA color, bool useStreaming, uint32_t streamingDistance, IResource* res = nullptr) = 0;
		virtual ITextLabel* CreateTextLabel(const std::string& text, const std::string& fontName, float fontSize, float scale, Vector3f position, Vector3f rot, alt::RGBA color, float outlineWidth, alt::RGBA outlineColor, bool useStreaming, uint32_t streamingDistance, IResource* res = nullptr) = 0;
		virtual ILocalVehicle* CreateLocalVehicle(uint32_t modelHash, int32_t dimension, alt::Position pos, alt::Rotation rot, bool useStreaming, uint32_t streamingDistance, IResource* res = nullptr) = 0;
		virtual ILocalPed* CreateLocalPed(uint32_t modelHash, int32_t dimension, alt::Position pos, alt::Rotation rot, bool useStreaming, uint32_t streamingDistance, IResource* res = nullptr) = 0;

		virtual IFont* RegisterFont(IResource* resource, const std::string& path, const std::string& currentPath) = 0;
		
		virtual void SetAngularVelocity(uint32_t entityId, alt::Vector4f velocity) = 0;

		virtual bool IsGameFocused() const = 0;

		virtual void LoadModel(uint32_t hash) = 0;
		virtual void LoadModelAsync(uint32_t hash) = 0;

		virtual bool LoadYtyp(const std::string& path) = 0;
		virtual bool UnloadYtyp(const std::string& path) = 0;

		virtual std::string HeadshotToBase64(uint8_t id) = 0;

		virtual void SetDlcClothes(int32_t scriptID, uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette, uint32_t dlc) = 0;
		virtual void SetDlcProps(int32_t scriptID, uint8_t component, uint8_t drawable, uint8_t texture, uint32_t dlc) = 0;
		virtual void ClearProps(int32_t scriptID, uint8_t component) = 0;

		virtual void SetWatermarkPosition(uint8_t pos) = 0;

		virtual uint16_t GetFps() const = 0;
		virtual uint16_t GetPing() const = 0;
		virtual uint64_t GetTotalPacketsSent() const = 0;
		virtual uint32_t GetTotalPacketsLost() const = 0;
		virtual std::string GetServerIp() const = 0;
		virtual uint16_t GetServerPort() const = 0;
		virtual std::string GetClientPath() const = 0;

		virtual bool HasLocalMetaData(const std::string& key) const = 0;
		virtual MValue GetLocalMetaData(const std::string& key) const = 0;
		
		virtual bool CopyToClipboard(const std::string& value) = 0;

		virtual void ToggleRmlDebugger(bool state) = 0;
		virtual bool LoadRmlFontFace(IResource* resource, const std::string& path, const std::string& currentPath, const std::string& name, bool italic = false, bool bold = false) const = 0;
		virtual void ToggleRmlControls(bool state) = 0;
		virtual bool AreRmlControlsEnabled() const = 0;

		virtual Vector3f WorldToScreen(Vector3f pos) = 0;
		virtual Vector3f ScreenToWorld(Vector2f pos) = 0;
		virtual Vector3f GetCamPos() = 0;
		virtual Vector2i GetScreenResolution() const = 0;

		virtual void SetMinimapComponentPosition(const std::string& name, char alignX, char alignY, Vector2f pos, Vector2f size) = 0;
		virtual void ResetMinimapComponentPosition(const std::string& name) = 0;
		virtual void SetMinimapIsRectangle(bool state) = 0;

		virtual Config::Value::ValuePtr GetClientConfig() const = 0;

		using RequestOAuth2TokenCallback = std::function<void(bool success, const std::string& token)>;
		virtual bool DiscordRequestOAuth2Token(const std::string& appid, RequestOAuth2TokenCallback callback) = 0;

		virtual bool IsFocusOverriden() const = 0;
		virtual Vector3f GetFocusOverridePos() const = 0;
		virtual Vector3f GetFocusOverrideOffset() const = 0;
		virtual IEntity* GetFocusOverrideEntity() const = 0;
		virtual void OverrideFocusPosition(Vector3f pos, Vector3f offset = Vector3f{ 0, 0, 0 }) = 0;
		virtual void OverrideFocusEntity(IEntity* entity) = 0;
		virtual void ClearFocusOverride() = 0;
		virtual void LoadDefaultIpls() = 0;

		virtual bool IsPointOnScreen(Vector3f point) const = 0;

		virtual ILocalObject* CreateLocalObject(uint32_t modelHash, Vector3f position, Vector3f rot, bool noOffset = false, bool dynamic = false, bool useStreaming = false, uint32_t streamingDistance = 0, IResource* res = nullptr) = 0;
		virtual ILocalObject* CreateWeaponObject(Position pos, Rotation rot, uint32_t weaponHash, uint32_t modelHash = 0, int numAmmo = 100, bool createDefaultComponents = true, float scale = 1.f, bool useStreaming = false, uint32_t streamingDistance = 0, IResource* res = nullptr) = 0;
		virtual const std::vector<ILocalObject*> GetWorldObjects() const = 0;
		virtual const std::vector<ILocalObject*> GetWeaponObjects() const = 0;

		virtual Vector3f GetPedBonePos(int32_t scriptId, uint16_t boneId) const = 0;

		virtual IBaseObject* GetBaseObjectByRemoteID(alt::IBaseObject::Type type, uint32_t id) const = 0;

		virtual std::vector<IVirtualEntity*> GetVirtualEntitiesStreamedIn() const = 0;
		
		virtual const char* GetGxtEntry(uint32_t hash) const = 0;

		virtual void InternalAddCefBootstrap(const std::string& bootstrap) = 0;

		virtual bool IsFullScreen() const = 0;

		virtual IBlip* GetBlipByGameID(uint32_t gameID) const = 0;
		virtual ICheckpoint* GetCheckpointByGameID(uint32_t gameID) const = 0;

		virtual bool IsWebViewGpuAccelerationActive() const = 0;

		virtual uint32_t GetPoolSize(const std::string& pool) const = 0;
		virtual uint32_t GetPoolCount(const std::string& pool) const = 0;
		virtual std::vector<uint32_t> GetPoolEntities(const std::string& pool) const = 0;

		virtual std::vector<uint32_t> GetVoicePlayers() const = 0;

		virtual void RemoveVoicePlayer(uint32_t player) = 0;

		virtual float GetVoiceSpatialVolume(uint32_t player) const = 0;
		virtual void SetVoiceSpatialVolume(uint32_t player, float volume) = 0;

		virtual float GetVoiceNonSpatialVolume(uint32_t player) const = 0;
		virtual void SetVoiceNonSpatialVolume(uint32_t player, float volume) = 0;

		virtual void AddVoiceFilter(uint32_t player, alt::IAudioFilter* filter) = 0;
		virtual void RemoveVoiceFilter(uint32_t player) = 0;
		virtual alt::IAudioFilter* GetVoiceFilter(uint32_t player) const = 0;
		virtual void UpdateClipContext(const std::unordered_map<std::string, std::string>& context) = 0;
		virtual bool ReloadVehiclePhysics(uint32_t modelHash) = 0;

		virtual double GetCPULoad() const = 0;
		virtual uint32_t GetVideoMemoryUsage() const = 0;
		virtual uint32_t GetRAMUsage() const = 0;
		virtual uint32_t GetTotalRAM() const = 0;
		virtual uint32_t GetCurrentProcessRamUsage() const = 0;
#endif

#ifdef ALT_SERVER_API // Server methods
		virtual const std::string& GetRootDirectory() = 0;

		virtual IResource *StartResource(const std::string& name) = 0;
		virtual void StopResource(const std::string& name) = 0;
		virtual void RestartResource(const std::string& name) = 0;

		/*
		 * Adds an extra config key that will be passed from resource.toml to client
		 */
		virtual void AddClientConfigKey(const std::string& key) = 0;

		virtual void TriggerClientEvent(IPlayer* target, const std::string& ev, MValueArgs args) = 0;
		/**
		 * Triggers client rpc answer
		 *
		 * This is only needed to be called when rpc event is answered with WillAnswer()
		 * The rpc is answered automatically when its Answer() method is called
		 *
		 * @param target player to receive the answer
		 * @param answerID answerID from the event
		 * @param args answer args
		 * @param error error string
		 */
		virtual void TriggerClientRPCAnswer(IPlayer* target, uint16_t answerID, MValue args, const std::string& error) = 0;
		virtual uint16_t TriggerClientRPCEvent(IPlayer* target, const std::string& ev, MValueArgs args) = 0;
		virtual void TriggerClientEvent(std::vector<IPlayer*> targets, const std::string& ev, MValueArgs args) = 0;
		virtual void TriggerClientEventForAll(const std::string& ev, MValueArgs args) = 0;

		virtual void TriggerClientEventUnreliable(IPlayer* target, const std::string& ev, MValueArgs args) = 0;
		virtual void TriggerClientEventUnreliable(std::vector<IPlayer*> targets, const std::string& ev, MValueArgs args) = 0;
		virtual void TriggerClientEventUnreliableForAll(const std::string& ev, MValueArgs args) = 0;

		virtual void SetSyncedMetaData(const std::string& key, MValue val) = 0;
		virtual void DeleteSyncedMetaData(const std::string& key) = 0;

		/**
		 * Creates a new vehicle
		 *
		 * @param model vehicle model hash
		 * @param pos spawn position
		 * @param rot spawn rotation
		 * @param streamingDistance streaming distance of the vehicle, when 0 it's 0 server config will be used
		 */
		virtual IVehicle* CreateVehicle(uint32_t model, Position pos, Rotation rot, uint32_t streamingDistance = 0, bool isStatic = false) = 0;

		// TODO make enum for types
		virtual ICheckpoint* CreateCheckpoint(uint8_t type, Position pos, float radius, float height, RGBA color, uint32_t streamingDistance) = 0;
		
		virtual IBlip* CreateBlip(bool global, IBlip::BlipType type, Position pos, std::vector<IPlayer*> targets = {}) = 0;
		virtual IBlip* CreateBlip(bool global, IBlip::BlipType type, IEntity* attachTo, std::vector<IPlayer*> targets = {}) = 0;
		virtual IMarker* CreateMarker(IPlayer* target, IMarker::MarkerType type, Vector3f position, alt::RGBA color, IResource* res = nullptr) = 0;

		virtual IVoiceChannel* CreateVoiceChannel(bool spatial, float maxDistance) = 0;

		virtual std::vector<IPlayer*> GetPlayersByName(const std::string& name) const = 0;

		virtual void SetPassword(const std::string& password) const = 0;
		virtual uint64_t HashServerPassword(const std::string& password) const = 0;

		virtual void StopServer() = 0;

		virtual const VehicleModelInfo& GetVehicleModelByHash(uint32_t hash) const = 0;
		virtual const std::vector<uint32_t>& GetLoadedVehicleModels() const = 0;
		virtual const PedModelInfo& GetPedModelByHash(uint32_t hash) const = 0;
		virtual const WeaponModelInfo& GetWeaponModelByHash(uint32_t hash) const = 0;

		virtual Config::Value::ValuePtr GetServerConfig() const = 0;
		
		virtual void SetWorldProfiler(bool state) = 0;

		/**
		 * Creates a new ped
		 *
		 * @param model ped model hash
		 * @param pos spawn position
		 * @param rot spawn rotation
		 * @param streamingDistance streaming distance of the ped, when 0 it's 0 server config will be used
		 */
		virtual IPed* CreatePed(uint32_t model, Position pos, Rotation rot, uint32_t streamingDistance = 0, bool isStatic = false) = 0;

		virtual std::vector<IBaseObject*> GetEntitiesInDimension(int32_t dimension, uint64_t allowedTypes) const = 0;
		virtual std::vector<IBaseObject*> GetEntitiesInRange(Position position, int32_t range, int32_t dimension, uint64_t allowedTypes) const = 0;

		/**
		 * Get closest entities
		 *
		 * @param position starting position
		 * @param range search range
		 * @param dimension search dimension
		 * @param limit max size result
		 * @param allowedTypes types of search objects
		 * @param sortOrder sort order
		 */
		virtual std::vector<IBaseObject*> GetClosestEntities(
 			Position position, int32_t range, int32_t dimension, int32_t limit, uint64_t allowedTypes,
 			common::Order sortOrder = common::Order::kDefault) const = 0;

		/**
		 * Creates a new object
		 *
		 * @param model object model hash
		 * @param pos spawn position
		 * @param rot spawn rotation
		 * @param alpha alpha
		 * @param textureVariation textureVariation
		 * @param lodDistance lodDistance
		 * @param streamingDistance streaming distance of the ped, when 0 it's 0 server config will be used
		 */
		virtual IObject* CreateObject(uint32_t model, Position pos, Rotation rot, uint8_t alpha = 255, uint8_t textureVariation = 0, uint16_t lodDistance = 100, uint32_t streamingDistance = 0, bool isStatic = false) = 0;

		virtual Metric* RegisterMetric(const std::string& metricName, Metric::Type metricType = Metric::Type::METRIC_TYPE_GAUGE, const std::unordered_map<std::string, std::string>& attributes = {}) = 0;

		virtual void UnregisterMetric(alt::Metric* metric) = 0;

		virtual uint32_t GetAmmoHashForWeaponHash(uint32_t weaponHash) const = 0;

		virtual void SetVoiceExternalPublic(const std::string& host, uint16_t port) = 0;
		virtual void SetVoiceExternal(const std::string& host, uint16_t port) = 0;

		virtual uint16_t GetMaxStreamingPeds() const = 0;
		virtual uint16_t GetMaxStreamingObjects() const = 0;
		virtual uint16_t GetMaxStreamingVehicles() const = 0;

		virtual void SetMaxStreamingPeds(uint16_t _limit) = 0;
		virtual void SetMaxStreamingObjects(uint16_t _limit) = 0;
		virtual void SetMaxStreamingVehicles(uint16_t _limit) = 0;

		virtual uint8_t GetStreamerThreadCount() const = 0;
		virtual uint8_t GetMigrationThreadCount() const = 0;
		virtual uint8_t GetSyncSendThreadCount() const = 0;
		virtual uint8_t GetSyncReceiveThreadCount() const = 0;

		virtual void SetStreamerThreadCount(uint8_t _count) = 0;
		virtual void SetMigrationThreadCount(uint8_t _count) = 0;
		virtual void SetSyncSendThreadCount(uint8_t _count) = 0;
		virtual void SetSyncReceiveThreadCount(uint8_t _count) = 0;

		virtual uint32_t GetStreamingTickRate() const = 0;
		virtual uint32_t GetMigrationTickRate() const = 0;
		virtual uint32_t GetColShapeTickRate() const = 0;

		virtual void SetStreamingTickRate(uint32_t _tickRate) = 0;
		virtual void SetMigrationTickRate(uint32_t _tickRate) = 0;
		virtual void SetColShapeTickRate(uint32_t _tickRate) = 0;

		virtual uint32_t GetStreamingDistance() const = 0;
		virtual uint32_t GetMigrationDistance() const = 0;

		virtual void SetStreamingDistance(uint32_t _distance) = 0;
		virtual void SetMigrationDistance(uint32_t _distance) = 0;

		virtual bool HasBenefit(Benefit benefit) const = 0;
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
