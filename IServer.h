#pragma once

#include "deps/alt-math/alt-math.h"
#include "types/RGBA.h"
#include "types/MValue.h"
#include "types/MValueList.h"
#include "types/StringView.h"

#include "events/CEvent.h"

#include "script-objects/IBlip.h"
#include "script-objects/IColShape.h"

namespace alt
{
	class IEntity;
	class IPlayer;
	class IVehicle;
	class ICheckpoint;
	class IScriptRuntime;
	class IVoiceChannel;

	using EventCallback = bool(*)(const CEvent* e);
	using TickCallback = void(*)();
	using CommandCallback = void(*)(StringView cmd, Array<StringView> args);

	class IServer
	{
	public:
		virtual StringView GetRootDirectory() = 0;

		virtual IResource* GetResource(StringView name) = 0;
		virtual bool RequireResource(IResource* referrer, IResource* resource) = 0;

		virtual void LogInfo(StringView str) = 0;
		virtual void LogDebug(StringView str) = 0;
		virtual void LogWarning(StringView str) = 0;
		virtual void LogError(StringView str) = 0;
		virtual void LogColored(StringView str) = 0;

		virtual uint32_t Hash(StringView str) const = 0;

		virtual bool RegisterScriptRuntime(StringView resourceType, IScriptRuntime* runtime) = 0;

		virtual void SubscribeEvent(CEvent::Type ev, EventCallback cb) = 0;
		virtual void SubscribeTick(TickCallback cb) = 0;
		virtual void SubscribeCommand(StringView cmd, CommandCallback cb) = 0;

		virtual void TriggerServerEvent(StringView ev, MValueList args) = 0;
		virtual void TriggerClientEvent(IPlayer* target, StringView ev, MValueList args) = 0;

		virtual IVehicle* CreateVehicle(uint32_t model, Position pos, Rotation rot) = 0;

		// TODO make enum for types
		virtual ICheckpoint* CreateCheckpoint(IPlayer* target, uint8_t type, Position pos, float radius, float height, RGBA color) = 0;

		virtual IBlip* CreateBlip(IPlayer* target, IBlip::Type type, Position pos) = 0;
		virtual IBlip* CreateBlip(IPlayer* target, IBlip::Type type, IEntity* attachTo) = 0;

		virtual IVoiceChannel* CreateVoiceChannel(bool spatial, float maxDistance) = 0;

		virtual IColShape* CreateColShapeCylinder(Position pos, float radius, float height) = 0;
		virtual IColShape* CreateColShapeSphere(Position pos, float radius) = 0;
		virtual IColShape* CreateColShapeCircle(Position pos, float radius) = 0;
		virtual IColShape* CreateColShapeCube(Position pos, Position pos2) = 0;
		virtual IColShape* CreateColShapeRectangle(Position pos, Position pos2) = 0;

		virtual IEntity* GetEntityByID(uint16_t id) const = 0;

		virtual void DestroyBaseObject(IBaseObject* handle) = 0;

		virtual Array<IPlayer*> GetPlayersByName(StringView name) const = 0;

		virtual Array<IEntity*> GetEntities() const = 0;
		virtual Array<IPlayer*> GetPlayers() const = 0;
		virtual Array<IVehicle*> GetVehicles() const = 0;

		virtual uint32_t GetNetTime() const = 0;

#ifndef ALT_SERVER
		static IServer& Instance() { return *_instance(); }
		static void SetInstance(IServer* server) { _instance() = server; }

	private:
		static IServer*& _instance()
		{
			static IServer* instance = nullptr;
			return instance;
		}
#endif
	protected:
		virtual ~IServer() = default;
	};
}
