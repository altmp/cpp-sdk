#pragma once

#include <cstdint>

#include "../types/RGBA.h"
#include "IColShape.h"

namespace alt
{
	class IPlayer;

	class ICheckpoint : public virtual IColShape
	{
	public:
		virtual ~ICheckpoint() = default;

		virtual uint8_t GetCheckpointType() const = 0;
		virtual float GetHeight() const = 0;
		virtual float GetRadius() const = 0;
		virtual RGBA GetColor() const = 0;
		virtual RGBA GetIconColor() const = 0;
		virtual alt::Position GetNextPosition() const = 0;

		virtual void SetCheckpointType(uint8_t type) = 0;
		virtual void SetHeight(float height) = 0;
		virtual void SetRadius(float radius) = 0;
		virtual void SetColor(RGBA color) = 0;
		virtual void SetIconColor(RGBA color) = 0;
		virtual void SetNextPosition(alt::Position pos) = 0;
		
		virtual uint32_t GetStreamingDistance() const = 0;

		virtual void SetVisible(bool toggle) = 0;
		virtual bool IsVisible() const = 0;
#ifdef ALT_CLIENT_API
		virtual bool IsStreamedIn() const = 0;
		virtual uint32_t GetGameID() const = 0;
#endif
#ifdef ALT_SERVER_API
		virtual bool HasStreamSyncedMetaData(const std::string& key) const = 0;
		virtual MValueConst GetStreamSyncedMetaData(const std::string& key) const = 0;
		virtual std::vector<std::string> GetStreamSyncedMetaDataKeys() const = 0;
		
		virtual void SetStreamSyncedMetaData(const std::string& key, MValue val) = 0;
		virtual void DeleteStreamSyncedMetaData(const std::string& key) = 0;
#endif
	};
}
