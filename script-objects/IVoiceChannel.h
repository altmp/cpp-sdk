#pragma once

#include <cstdint>
#include "../IBaseObject.h"
#include "../Ref.h"

namespace alt
{
	class IPlayer;

	class IVoiceChannel: public virtual IBaseObject
	{
	public:
		virtual ~IVoiceChannel() = default;

		virtual void AddPlayer(Ref<IPlayer> player) = 0;
		virtual void RemovePlayer(Ref<IPlayer> player) = 0;
		virtual void MutePlayer(Ref<IPlayer> player) = 0;
		virtual void UnmutePlayer(Ref<IPlayer> player) = 0;
		virtual bool IsPlayerConnected(Ref<IPlayer> player) = 0;
		virtual bool IsPlayerMuted(Ref<IPlayer> player) = 0;
		virtual bool IsSpatial() = 0;
		virtual float GetMaxDistance() = 0;
	};
}
