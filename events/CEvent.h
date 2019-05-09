#pragma once

#include <functional>

namespace alt
{
	class CEvent
	{
	public:
		enum class Type : uint16_t
		{
			NONE = 0,

			// Shared
			PLAYER_CONNECT = 1,
			PLAYER_DISCONNECT = 2,
			
			SERVER_SCRIPT_EVENT = 3,
			CLIENT_SCRIPT_EVENT = 4,

			META_CHANGE = 5,
			SYNCED_META_CHANGE = 6,

			PLAYER_DAMAGE = 7,
			PLAYER_DEATH = 8,

			CHECKPOINT_EVENT = 9,
			PLAYER_ENTER_VEHICLE = 10,
			PLAYER_LEAVE_VEHICLE = 11,
			PLAYER_CHANGE_VEHICLE_SEAT = 12,

			REMOVE_ENTITY_EVENT = 13,

			DATA_NODE_RECEIVED_EVENT = 14,

			CONSOLE_COMMAND_EVENT = 15,

			// Client
			WEB_VIEW_EVENT = 16,
			KEYBOARD_EVENT = 17,
			CONNECTION_COMPLETE = 18,
			GAME_ENTITY_CREATE = 19,
			GAME_ENTITY_DESTROY = 20,

			ALL = 21,
			SIZE = 22
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
