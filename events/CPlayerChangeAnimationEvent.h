#pragma once

#pragma once

#include "CEvent.h"
#include "../objects/IPlayer.h"

namespace alt
{
	class CPlayerChangeAnimationEvent : public CEvent
	{
	public:
		CPlayerChangeAnimationEvent(IPlayer* _target, uint32_t _oldAnimationDict, uint32_t _oldAnimationName, uint32_t _newAnimationDict, uint32_t _newAnimationName) :
			CEvent(Type::PLAYER_CHANGE_ANIMATION_EVENT),
			target(_target),
			oldAnimationDict(_oldAnimationDict),
			oldAnimationName(_oldAnimationName),
			newAnimationDict(_newAnimationDict),
			newAnimationName(_newAnimationName)
		{}

		IPlayer* GetTarget() const { return target; }
		uint32_t GetOldAnimationDict() const { return oldAnimationDict; }
		uint32_t GetOldAnimationName() const { return oldAnimationName; }
		uint32_t GetNewAnimationDict() const { return newAnimationDict; }
		uint32_t GetNewAnimationName() const { return newAnimationName; }

	private:
		IPlayer* target;
		uint32_t oldAnimationDict;
		uint32_t oldAnimationName;
		uint32_t newAnimationDict;
		uint32_t newAnimationName;
	};
}

