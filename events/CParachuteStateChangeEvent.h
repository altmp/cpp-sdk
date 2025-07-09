#pragma once

#include <cstdint>
#include <memory>

#include "CEvent.h"

namespace alt
{
	class CParachuteStateChangeEvent : public CEvent
	{		
	public:
		enum class ParachuteState : int8_t
		{
			NORMAL = -1,
			CARRING_PARACHUTE = 0,
			OPENING_PARACHUTE = 1,
			OPEN_PARACHUTE = 2,
			REMOVE_PARACHUTE = 3
		};
		
		CParachuteStateChangeEvent(const std::shared_ptr<IPlayer>& _player, ParachuteState _oldState, ParachuteState _newState) :
			CEvent(Type::PARACHUTE_STATE_CHANGE),
			player(_player), oldState(_oldState), newState(_newState)

		{

		}

		std::shared_ptr<IPlayer> GetPlayer() const { return player; }
		ParachuteState GetOldState() const { return oldState; }
		ParachuteState GetNewState() const { return newState; }
	private:		
		std::shared_ptr<IPlayer> player;
		ParachuteState oldState;
		ParachuteState newState;
	};
}
