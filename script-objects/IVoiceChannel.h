#pragma once

#include <cstdint>
#include <vector>
#include "../objects/IBaseObject.h"
#include "../Ref.h"

namespace alt
{
	class IPlayer;

	class IVoiceChannel : public virtual IBaseObject
	{
	public:
		virtual ~IVoiceChannel() = default;

		virtual bool IsSpatial() const = 0;
		virtual float GetMaxDistance() const = 0;

		virtual bool HasPlayer(Ref<IPlayer> player) const = 0;
		virtual void AddPlayer(Ref<IPlayer> player) = 0;
		virtual void RemovePlayer(Ref<IPlayer> player) = 0;

		virtual bool IsPlayerMuted(Ref<IPlayer> player) const = 0;
		virtual void MutePlayer(Ref<IPlayer> player) = 0;
		virtual void UnmutePlayer(Ref<IPlayer> player) = 0;

		virtual const std::vector<Ref<IPlayer>> GetPlayers() const = 0;
		virtual size_t GetPlayerCount() const = 0;
		
		const std::type_info& GetTypeInfo() const override { return typeid(this); }
	};
} // namespace alt
