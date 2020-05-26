#pragma once

#include "deps/alt-math/alt-math.h"
#include "types/RGBA.h"
#include "types/Array.h"
#include "types/MValue.h"
#include "types/StringView.h"
#include "types/Discord.h"
#include "Ref.h"

#include "events/CEvent.h"
#include "IResource.h"

#include "script-objects/IBlip.h"
#include "script-objects/IColShape.h"

#include "types/KeyState.h"

namespace alt
{
	class IEntity;
	class IPlayer;
	class IVehicle;
	class ICheckpoint;
	class IScriptRuntime;
	class IVoiceChannel;

	using EventCallback = bool(*)(const CEvent* e, void* userData);
	using TickCallback = void(*)(void* userData);
	using CommandCallback = void(*)(StringView cmd, Array<StringView> args, void* userData);

	static constexpr int32_t DEFAULT_DIMENSION = 0;
	static constexpr int32_t GLOBAL_DIMENSION = -2147483648;

	class ICore
	{
	public:
		static constexpr uint32_t SDK_VERSION = 36;

		// Shared methods
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
		virtual MValueFunction CreateMValueFunction(IMValueFunction::Impl* impl) = 0;
		virtual MValueVector3 CreateMValueVector3(Vector3f val) = 0;
		virtual MValueRGBA CreateMValueRGBA(RGBA val) = 0;
		virtual MValueByteArray CreateMValueByteArray(const uint8_t* data, Size size) = 0;
		virtual MValueByteArray CreateMValueByteArray(Size size) = 0;

		virtual bool IsDebug() const = 0;

		virtual uint32_t Hash(StringView str) const = 0;

		virtual bool RegisterScriptRuntime(StringView resourceType, IScriptRuntime* runtime) = 0;

		virtual void SubscribeEvent(CEvent::Type ev, EventCallback cb, void* userData = nullptr) = 0;
		virtual void SubscribeTick(TickCallback cb, void* userData = nullptr) = 0;
		virtual bool SubscribeCommand(StringView cmd, CommandCallback cb, void* userData = nullptr) = 0;

		virtual bool FileExists(StringView path) = 0;
		virtual String FileRead(StringView path) = 0;

		virtual IResource* GetResource(StringView name) = 0;

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

#ifdef ALT_CLIENT_API // Client methods
		virtual void RequestDiscordOAuth2Token(DiscordOAuth2Callback callback, void* userData) = 0;
		virtual KeyState GetKeyState(uint32_t keyCode) = 0;

		virtual bool SetConfigFlag(StringView flag, bool state) = 0;
		virtual bool GetConfigFlag(StringView flag) = 0;
		virtual bool DoesConfigFlagExist(StringView flag) = 0;
#endif

#ifdef ALT_SERVER_API // Server methods
		virtual StringView GetRootDirectory() = 0;

		virtual IResource* StartResource(StringView name) = 0;
		virtual void StopResource(StringView name) = 0;
		virtual IResource* RestartResource(StringView name) = 0;

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

		virtual void DestroyBaseObject(Ref<IBaseObject> handle) = 0;

		virtual Array<Ref<IPlayer>> GetPlayersByName(StringView name) const = 0;

		virtual uint32_t GetNetTime() const = 0;
#endif

		static ICore& Instance() { return *_instance(); }
		static void SetInstance(ICore* server) { _instance() = server; }

	protected:
		virtual ~ICore() = default;

	private:
		static ICore*& _instance()
		{
			static ICore* instance = nullptr;
			return instance;
		}
	};
}
