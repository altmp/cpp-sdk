#pragma once

#include "../deps/alt-math/alt-math.h"
#include "../types/StringView.h"
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
		virtual uint16_t GetID() const = 0;

		virtual Ref<IPlayer> GetNetworkOwner() const = 0;

		virtual uint32_t GetModel() const = 0;

		virtual Rotation GetRotation() const = 0;
		virtual void SetRotation(Rotation rot) = 0;

		virtual bool HasSyncedMetaData(StringView key) const = 0;
		virtual MValueConst GetSyncedMetaData(StringView key) const = 0;
		virtual bool HasStreamSyncedMetaData(StringView key) const = 0;
		virtual MValueConst GetStreamSyncedMetaData(StringView key) const = 0;
		virtual bool GetVisible() const = 0;

#ifdef ALT_SERVER_API
		virtual void SetNetworkOwner(Ref<IPlayer> player, bool disableMigration) = 0;

		virtual void SetSyncedMetaData(StringView key, MValue val) = 0;
		virtual void DeleteSyncedMetaData(StringView key) = 0;
		virtual void SetStreamSyncedMetaData(StringView key, MValue val) = 0;
		virtual void DeleteStreamSyncedMetaData(StringView key) = 0;
		virtual void SetVisible(bool toggle) = 0;

		virtual void AttachToEntity(Ref<IEntity> entity, uint16_t otherBoneIndex, uint16_t myBoneIndex, Position position, Position rotation) = 0;
#endif // ALT_SERVER_API

#ifdef ALT_CLIENT_API
		virtual int32_t GetScriptGuid() const = 0;
#endif // ALT_CLIENT_API
	};
} // namespace alt
