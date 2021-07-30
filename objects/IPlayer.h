#pragma once

#include "IEntity.h"
#include "IVehicle.h"
#include "../types/Cloth.h"
#include "../types/DlcCloth.h"
#include "../types/Prop.h"
#include "../types/DlcProp.h"

namespace alt
{
	class IPlayer : public virtual IEntity
	{
	protected:
		virtual ~IPlayer() = default;

	public:
		virtual StringView GetName() const = 0;

		virtual uint16_t GetHealth() const = 0;
		virtual uint16_t GetMaxHealth() const = 0;

		virtual bool HasWeaponComponent(uint32_t weapon, uint32_t component) const = 0;
		virtual Array<uint32_t> GetCurrentWeaponComponents() const = 0;

		virtual uint8_t GetWeaponTintIndex(uint32_t weapon) const = 0;
		virtual uint8_t GetCurrentWeaponTintIndex() const = 0;

		virtual uint32_t GetCurrentWeapon() const = 0;

		virtual bool IsDead() const = 0;

		virtual bool IsJumping() const = 0;
		virtual bool IsInRagdoll() const = 0;
		virtual bool IsAiming() const = 0;
		virtual bool IsShooting() const = 0;
		virtual bool IsReloading() const = 0;

		virtual uint16_t GetArmour() const = 0;
		virtual uint16_t GetMaxArmour() const = 0;

		virtual float GetMoveSpeed() const = 0;

		virtual Vector3f GetAimPos() const = 0;
		virtual Vector3f GetHeadRotation() const = 0;

		virtual bool IsInVehicle() const = 0;
		virtual Ref<IVehicle> GetVehicle() const = 0;
		virtual uint8_t GetSeat() const = 0;

		virtual Ref<IEntity> GetEntityAimingAt() const = 0;
		virtual Vector3f GetEntityAimOffset() const = 0;

		virtual bool IsFlashlightActive() const = 0;

#ifdef ALT_SERVER_API
		virtual bool IsConnected() const = 0;
		virtual uint32_t GetPing() const = 0;
		virtual StringView GetIP() const = 0;
		virtual uint64_t GetSocialID() const = 0;
		virtual uint64_t GetHwidHash() const = 0;
		virtual uint64_t GetHwidExHash() const = 0;
		virtual StringView GetAuthToken() const = 0;

		virtual void Spawn(Vector3f pos, uint32_t delayMs) = 0;
		virtual void Despawn() = 0;
		virtual void SetModel(uint32_t model) = 0;
		virtual void SetArmour(uint16_t armor) = 0;
		virtual void SetMaxArmour(uint16_t armor) = 0;
		virtual void SetCurrentWeapon(uint32_t weapon) = 0;
		virtual void SetWeaponTintIndex(uint32_t weapon, uint8_t tintIndex) = 0;
		virtual void AddWeaponComponent(uint32_t weapon, uint32_t component) = 0;
		virtual void RemoveWeaponComponent(uint32_t weapon, uint32_t component) = 0;
		virtual void ClearBloodDamage() = 0;
		virtual void SetHealth(uint16_t health) = 0;
		virtual void SetMaxHealth(uint16_t health) = 0;
		virtual void GiveWeapon(uint32_t weapon, int32_t ammo, bool selectWeapon) = 0;
		virtual bool RemoveWeapon(uint32_t weapon) = 0;
		virtual void RemoveAllWeapons() = 0;
		virtual void SetDateTime(int day, int month, int year, int hour, int minute, int second) = 0;
		virtual void SetWeather(uint32_t weather) = 0;
		virtual void Kick(StringView reason = "Kicked") = 0;
		virtual alt::Cloth GetClothes(uint8_t component) const = 0;
		virtual void SetClothes(uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette) = 0;
		virtual alt::DlcCloth GetDlcClothes(uint8_t component) const = 0;
		virtual void SetDlcClothes(uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette, uint32_t dlc) = 0;
		virtual alt::Prop GetProps(uint8_t component) const = 0;
		virtual void SetProps(uint8_t component, uint16_t drawable, uint8_t texture) = 0;
		virtual alt::DlcProp GetDlcProps(uint8_t component) const = 0;
		virtual void SetDlcProps(uint8_t component, uint8_t drawable, uint8_t texture, uint32_t dlc) = 0;
		virtual void ClearProps(uint8_t component) = 0;
		virtual bool IsEntityInStreamingRange(Ref<IEntity> entity) = 0;
#endif // ALT_SERVER_API

#ifdef ALT_CLIENT_API
		virtual bool IsTalking() const = 0;
		virtual float GetMicLevel() const = 0;

		virtual float GetSpatialVolume() const = 0;
		virtual void SetSpatialVolume(float volume) = 0;
		virtual float GetNonSpatialVolume() const = 0;
		virtual void SetNonSpatialVolume(float volume) = 0;
#endif // ALT_CLIENT_API
		
		const std::type_info& GetTypeInfo() const override { return typeid(this); }
	};
} // namespace alt
