#pragma once

#include <cstdint>
#include "../IBaseObject.h"

namespace alt
{
	class IPlayer;

	class IVoiceChannel: public virtual IBaseObject
	{
	public:
		virtual void AddPlayer(IPlayer* player) = 0;
		virtual void RemovePlayer(IPlayer* player) = 0;
		virtual void MutePlayer(IPlayer* player) = 0;
		virtual void UnmutePlayer(IPlayer* player) = 0;
		virtual bool IsPlayerConnected(IPlayer* player) = 0;
		virtual bool IsPlayerMuted(IPlayer* player) = 0;
		virtual bool IsSpatial() = 0;
		virtual float GetMaxDistance() = 0;

	protected:
		virtual ~IVoiceChannel() = default;
	};
}
