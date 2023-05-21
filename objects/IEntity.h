#pragma once

#include "../deps/alt-math/alt-math.h"
#include "../types/MValue.h"
#include "IWorldObject.h"

namespace alt
{
	class IPlayer;

	class IEntity : public virtual IWorldObject
	{
	protected:
		virtual ~IEntity() = default;

	public:
		virtual uint16_t GetSyncID() const = 0;

		virtual IPlayer* GetNetworkOwner() const = 0;

		virtual uint32_t GetModel() const = 0;

		virtual Rotation GetRotation() const = 0;
		virtual void SetRotation(Rotation rot) = 0;

		virtual bool HasStreamSyncedMetaData(const std::string& key) const = 0;
		virtual MValueConst GetStreamSyncedMetaData(const std::string& key) const = 0;
		virtual std::vector<std::string> GetStreamSyncedMetaDataKeys() const = 0;
		virtual bool GetVisible() const = 0;

#ifdef ALT_SERVER_API
		virtual void SetNetworkOwner(IPlayer* player, bool disableMigration) = 0;

		virtual void SetStreamSyncedMetaData(const std::string& key, MValue val) = 0;
		virtual void DeleteStreamSyncedMetaData(const std::string& key) = 0;
		virtual void SetVisible(bool toggle) = 0;

		virtual void AttachToEntity(IEntity* entity, int16_t otherBoneIndex, int16_t myBoneIndex, Position position, Rotation rotation, bool collision, bool noFixedRotation) = 0;
		virtual void AttachToEntity(IEntity* entity, const std::string& otherBoneName, const std::string& myBoneName, Position position, Rotation rotation, bool collision, bool noFixedRotation) = 0;
		virtual void Detach() = 0;

		virtual void SetStreamed(bool toggle) = 0;
		virtual bool GetStreamed() const = 0;

		virtual bool IsFrozen() const = 0;
		virtual void SetFrozen(bool state) = 0;

		virtual bool HasCollision() const = 0;
		virtual void SetCollision(bool state) = 0;
#endif // ALT_SERVER_API

#ifdef ALT_CLIENT_API
		virtual int32_t GetScriptGuid() const = 0;
#endif // ALT_CLIENT_API
	};
} // namespace alt
