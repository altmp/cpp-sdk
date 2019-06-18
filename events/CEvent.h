#pragma once

#include <functional>

namespace alt
{
	class CEvent
	{
	public:
		enum class Type : uint16_t
		{
			NONE,

			// Shared
			PLAYER_CONNECT,
			PLAYER_DISCONNECT,
			
			SERVER_SCRIPT_EVENT,
			CLIENT_SCRIPT_EVENT,

			META_CHANGE,
			SYNCED_META_CHANGE,

			PLAYER_DAMAGE,
			PLAYER_DEATH,

			CHECKPOINT_EVENT,
			COLSHAPE_EVENT,
			PLAYER_ENTER_VEHICLE,
			PLAYER_LEAVE_VEHICLE,
			PLAYER_CHANGE_VEHICLE_SEAT,

			REMOVE_ENTITY_EVENT,

			DATA_NODE_RECEIVED_EVENT,

			CONSOLE_COMMAND_EVENT,

			// Client
			CONNECTION_COMPLETE,
			DISCONNECT_EVENT,
			WEB_VIEW_EVENT,
			KEYBOARD_EVENT,
			GAME_ENTITY_CREATE,
			GAME_ENTITY_DESTROY,

			ALL,
			SIZE
		};

		CEvent(Type _type) :type(_type) { }

		Type GetType() const { return type; };
		bool WasCancelled() const { return cancelled; }
		void Cancel() const { cancelled = true; }

	private:
		Type type;
		mutable bool cancelled;
	};
}
