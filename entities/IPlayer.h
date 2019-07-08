#pragma once

#include "IEntity.h"

namespace alt
{
	class IVehicle;

	class IPlayer : public virtual IEntity
	{
	public:
		virtual bool IsConnected() const = 0;

		virtual uint32_t GetPing() const = 0;
		virtual StringView GetIP() const = 0;

		virtual void Spawn(Position pos, uint32_t delayMs) = 0;
		virtual void Despawn() = 0;

		virtual StringView GetName() const = 0;

		virtual uint64_t GetSocialID() const = 0;
		virtual uint64_t GetHwidHash() const = 0;
		virtual uint64_t GetHwidExHash() const = 0;
		virtual StringView GetAuthToken() const = 0;

		virtual uint16_t GetHealth() const = 0;
		virtual void SetHealth(uint16_t health) = 0;
		virtual uint16_t GetMaxHealth() const = 0;
		virtual void SetMaxHealth(uint16_t health) = 0;

		virtual void SetDateTime(int day, int month, int year, int hour, int minute, int second) = 0;
		virtual void SetWeather(uint32_t weather) = 0;

		virtual void GiveWeapon(uint32_t weapon, int32_t ammo, bool selectWeapon) = 0;
		virtual void RemoveWeapon(uint32_t weapon) = 0;
		virtual void RemoveAllWeapons() = 0;

		virtual void AddWeaponComponent(uint32_t weapon, uint32_t component) = 0;
		virtual void RemoveWeaponComponent(uint32_t weapon, uint32_t component) = 0;
		virtual alt::Array<uint32_t> GetCurrentWeaponComponents() const = 0;

		virtual void SetWeaponTintIndex(uint32_t weapon, uint8_t tintIndex) = 0;
		virtual uint8_t GetCurrentWeaponTintIndex() const = 0;

		virtual uint32_t GetCurrentWeapon() const = 0;
		virtual void SetCurrentWeapon(uint32_t weapon) = 0;

		virtual bool IsDead() const = 0;

		virtual bool IsJumping() const = 0;
		virtual bool IsInRagdoll() const = 0;
		virtual bool IsAiming() const = 0;
		virtual bool IsShooting() const = 0;
		virtual bool IsReloading() const = 0;

		virtual uint16_t GetArmour() const = 0;
		virtual void SetArmour(uint16_t armor) = 0;
		virtual uint16_t GetMaxArmour() const = 0;
		virtual void SetMaxArmour(uint16_t armor) = 0;

		virtual float GetMoveSpeed() const = 0;

		virtual uint32_t GetWeapon() const = 0;
		virtual uint16_t GetAmmo() const = 0;

		virtual Position GetAimPos() const = 0;
		virtual Rotation GetHeadRotation() const = 0;

		virtual bool IsInVehicle() const = 0;
		virtual IVehicle* GetVehicle() const = 0;
		virtual uint8_t GetSeat() const = 0;

		virtual IEntity* GetEntityAimingAt() const = 0;
		virtual Position GetEntityAimOffset() const = 0;

		virtual bool IsFlashlightActive() const = 0;

		virtual void Kick(StringView reason = "kicked out") = 0;

#ifdef ALT_SERVER_API
		virtual void SetModel(uint32_t model) = 0;
#endif // ALT_SERVER_API

	protected:
		virtual ~IPlayer() = default;
	};
}
