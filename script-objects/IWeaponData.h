#pragma once

#include "../CRefCountable.h"

namespace alt
{
	class IWeaponData : public virtual CRefCountable
	{
	protected:
		virtual ~IWeaponData() = default;

	public:
		virtual uint32_t GetNameHash() const = 0;
		virtual uint32_t GetModelHash() const = 0;
		virtual float GetRecoilShakeAmplitude() const = 0;
		virtual float GetRecoilAccuracyMax() const = 0;
		virtual float GetRecoilAccuracyToAllowHeadshotPlayer() const = 0;
		virtual float GetRecoilRecoveryRate() const = 0;
		virtual float GetAnimReloadRate() const = 0;
		virtual float GetVehicleReloadTime() const = 0;
		virtual float GetLockOnRange() const = 0;
		virtual float GetAccuracySpread() const = 0;
		virtual float GetRange() const = 0;
		virtual float GetDamage() const = 0;
		virtual uint32_t GetClipSize() const = 0;
		virtual float GetTimeBetweenShots() const = 0;
		virtual float GetHeadshotDamageModifier() const = 0;
		virtual float GetPlayerDamageModifier() const = 0;

		virtual void SetRecoilShakeAmplitude(float val) = 0;
		virtual void SetRecoilAccuracyMax(float val) = 0;
		virtual void SetRecoilAccuracyToAllowHeadshotPlayer(float val) = 0;
		virtual void SetRecoilRecoveryRate(float val) = 0;
		virtual void SetAnimReloadRate(float val) = 0;
		virtual void SetVehicleReloadTime(float val) = 0;
		virtual void SetLockOnRange(float val) = 0;
		virtual void SetAccuracySpread(float val) = 0;
		virtual void SetRange(float val) = 0;
		virtual void SetDamage(float val) = 0;
		virtual void SetHeadshotDamageModifier(float val) = 0;
		virtual void SetPlayerDamageModifier(float val) = 0;

		const std::type_info& GetTypeInfo() const override { return typeid(this); }
	};
}
