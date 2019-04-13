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

			PLAYER_DAMAGE = 5,
			PLAYER_DEATH = 6,

			CHECKPOINT_EVENT = 7,
			PLAYER_ENTER_VEHICLE = 8,
			PLAYER_LEAVE_VEHICLE = 9,
			PLAYER_CHANGE_VEHICLE_SEAT = 10,

			REMOVE_ENTITY_EVENT = 11,

			CONSOLE_COMMAND_EVENT = 12,

			// Client
			WEB_VIEW_EVENT = 13,
			KEYBOARD_EVENT = 14,
			CONNECTION_COMPLETE = 15,

			ALL = 16,
			SIZE = 17
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
