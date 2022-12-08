#pragma once

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerDimensionChangeEvent : public CEvent
	{
	public:
		CPlayerDimensionChangeEvent(const std::shared_ptr<IPlayer>& _target, int32_t _oldDimension, int32_t _newDimension) :
			CEvent(Type::PLAYER_DIMENSION_CHANGE),
			target(_target),
			oldDimension(_oldDimension),
			newDimension(_newDimension)
		{
		}

		IPlayer* GetTarget() const { return target.get(); }
		int32_t GetOldDimension() const { return oldDimension; }
		int32_t GetNewDimension() const { return newDimension; }

	private:
		std::shared_ptr<IPlayer> target;
		int32_t oldDimension;
		int32_t newDimension;
	};
}
