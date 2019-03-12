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

		virtual void Spawn(Position pos, uint32_t delayMs) = 0;
		virtual void Despawn() = 0;

		virtual StringView GetName() const = 0;
		virtual void SetName(StringView name) = 0;

		virtual uint16_t GetHealth() const = 0;
		virtual void SetHealth(uint16_t health) = 0;

		virtual void SetDateTime(int day, int month, int year, int hour, int minute, int second) = 0;
		virtual void SetWeather(uint32_t weather) = 0;

		virtual bool IsDead() const = 0;

		virtual bool IsJumping() const = 0;
		virtual bool IsInRagdoll() const = 0;
		virtual bool IsAiming() const = 0;
		virtual bool IsShooting() const = 0;
		virtual bool IsReloading() const = 0;

		virtual uint16_t GetArmor() const = 0;
		virtual void SetArmor(uint16_t armor) = 0;

		virtual float GetMoveSpeed() const = 0;

		virtual uint32_t GetWeapon() const = 0;
		virtual uint16_t GetAmmo() const = 0;

		virtual Position GetAimPos() const = 0;
		virtual Rotation GetHeadRotation() const = 0;

		virtual bool IsInVehicle() const = 0;
		virtual IVehicle* GetVehicle() const = 0;
		virtual uint8_t GetSeat() const = 0;

		virtual void Kick(StringView reason = "kicked out") = 0;

	protected:
		virtual ~IPlayer() = default;
	};
}
