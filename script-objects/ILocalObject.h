#pragma once

#include "../objects/IObject.h"

namespace alt
{
	class ILocalObject : public virtual IObject
	{
	public:
		virtual void SetModel(uint32_t model) = 0;
		virtual void SetAlpha(uint8_t alpha) = 0;
		virtual void ResetAlpha() = 0;

		virtual bool IsDynamic() const = 0;

		virtual void SetLodDistance(uint16_t distance) = 0;

		virtual bool HasGravity() const = 0;
		virtual void ToggleGravity(bool toggle) = 0;

		virtual void AttachToEntity(IEntity* entity, int16_t boneIndex, alt::Position pos, alt::Rotation rot, bool useSoftPinning, bool collision, bool fixedRot) = 0;
		virtual void AttachToEntity(uint32_t scriptId, int16_t boneIndex, alt::Position pos, alt::Rotation rot, bool useSoftPinning, bool collision, bool fixedRot) = 0;
		virtual void Detach(bool dynamic) = 0;

		virtual bool IsCollisionEnabled() const = 0;
		virtual void ToggleCollision(bool toggle, bool keepPhysics) = 0;

		virtual void PlaceOnGroundProperly() = 0;

		virtual void SetPositionFrozen(bool toggle) = 0;
		virtual bool IsPositionFrozen() const = 0;

		virtual void ActivatePhysics() = 0;

		virtual void SetTextureVariation(uint8_t variation) = 0;

		// True = Created by GTA, False = Created by API
		virtual bool IsWorldObject() const = 0;

		virtual uint32_t GetStreamingDistance() const = 0;

		virtual void SetVisible(bool toggle) = 0;
		virtual bool IsVisible() const = 0;
#ifdef ALT_CLIENT_API
		virtual bool IsStreamedIn() const = 0;
		virtual bool UsesStreaming() const = 0;

		virtual bool IsWeaponObject() const = 0;

		//weapon object only
		virtual void SetTintIndex(int tintIndex) = 0;
		virtual int GetTintIndex() const = 0;

		virtual void GiveComponent(int componentType) = 0;
		virtual void RemoveComponent(int componentType) = 0;

		virtual void SetComponentTintIndex(int componentType, int tintIndex) = 0;
		virtual int GetComponentTintIndex(int componentType) = 0;
#endif
	};
}
