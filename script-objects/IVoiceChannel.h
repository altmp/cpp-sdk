#pragma once

#include <cstdint>
#include <vector>
#include "../objects/IBaseObject.h"

namespace alt
{
	class IPlayer;

	class IVoiceChannel : public virtual IBaseObject
	{
	public:
		virtual ~IVoiceChannel() = default;

		virtual bool IsSpatial() const = 0;
		virtual float GetMaxDistance() const = 0;

		virtual bool HasPlayer(IPlayer* player) const = 0;
		virtual void AddPlayer(IPlayer* player) = 0;
		virtual void RemovePlayer(IPlayer* player) = 0;

		virtual bool IsPlayerMuted(IPlayer* player) const = 0;
		virtual void MutePlayer(IPlayer* player) = 0;
		virtual void UnmutePlayer(IPlayer* player) = 0;

		virtual const std::vector<IPlayer*> GetPlayers() const = 0;
		virtual size_t GetPlayerCount() const = 0;

		virtual uint32_t GetFilter() const = 0;
		virtual void SetFilter(uint32_t filter) = 0;

		virtual int32_t GetPriority() const = 0;
		virtual void SetPriority(int32_t priority) = 0;
	};
} // namespace alt
