#pragma once

#include "../deps/alt-math/alt-math.h"

namespace alt
{
    class IHandlingData : public virtual CRefCountable
    {
    protected:
        virtual ~IHandlingData() = default;

    public:
        virtual uint32_t GetHandlingNameHash() = 0;
        virtual float GetMass() = 0;
        virtual float GetInitialDragCoeff() = 0;
        virtual float GetDownforceModifier() = 0;
        virtual float GetunkFloat1() = 0;
        virtual float GetunkFloat2() = 0;
        virtual Vector3f GetCentreOfMassOffset() = 0;
        virtual Vector3f GetInertiaMultiplier() = 0;
        virtual float GetPercentSubmerged() = 0;
        virtual float GetPercentSubmergedRatio() = 0;
        virtual float GetDriveBiasFront() = 0;
        virtual float GetAcceleration() = 0;
        virtual uint32_t GetInitialDriveGears() = 0;
        virtual float GetDriveInertia() = 0;
        virtual float GetClutchChangeRateScaleUpShift() = 0;
        virtual float GetClutchChangeRateScaleDownShift() = 0;
        virtual float GetInitialDriveForce() = 0;
        virtual float GetDriveMaxFlatVel() = 0;
        virtual float GetInitialDriveMaxFlatVel() = 0;
        virtual float GetBrakeForce() = 0;
        virtual float GetunkFloat4() = 0;
        virtual float GetBrakeBiasFront() = 0;
        virtual float GetBrakeBiasRear() = 0;
        virtual float GetHandBrakeForce() = 0;
        virtual float GetSteeringLock() = 0;
        virtual float GetSteeringLockRatio() = 0;
        virtual float GetTractionCurveMax() = 0;
        virtual float GetTractionCurveMaxRatio() = 0;
        virtual float GetTractionCurveMin() = 0;
        virtual float GetTractionCurveMinRatio() = 0;
        virtual float GetTractionCurveLateral() = 0;
        virtual float GetTractionCurveLateralRatio() = 0;
        virtual float GetTractionSpringDeltaMax() = 0;
        virtual float GetTractionSpringDeltaMaxRatio() = 0;
        virtual float GetLowSpeedTractionLossMult() = 0;
        virtual float GetCamberStiffness() = 0;
        virtual float GetTractionBiasFront() = 0;
        virtual float GetTractionBiasRear() = 0;
        virtual float GetTractionLossMult() = 0;
        virtual float GetSuspensionForce() = 0;
        virtual float GetSuspensionCompDamp() = 0;
        virtual float GetSuspensionReboundDamp() = 0;
        virtual float GetSuspensionUpperLimit() = 0;
        virtual float GetSuspensionLowerLimit() = 0;
        virtual float GetSuspensionRaise() = 0;
        virtual float GetSuspensionBiasFront() = 0;
        virtual float GetSuspensionBiasRear() = 0;
        virtual float GetAntiRollBarForce() = 0;
        virtual float GetAntiRollBarBiasFront() = 0;
        virtual float GetAntiRollBarBiasRear() = 0;
        virtual float GetRollCentreHeightFront() = 0;
        virtual float GetRollCentreHeightRear() = 0;
        virtual float GetCollisionDamageMult() = 0;
        virtual float GetWeaponDamageMult() = 0;
        virtual float GetDeformationDamageMult() = 0;
        virtual float GetEngineDamageMult() = 0;
        virtual float GetPetrolTankVolume() = 0;
        virtual float GetOilVolume() = 0;
        virtual float GetunkFloat5() = 0;
        virtual float GetSeatOffsetDistX() = 0;
        virtual float GetSeatOffsetDistY() = 0;
        virtual float GetSeatOffsetDistZ() = 0;
        virtual uint32_t GetMonetaryValue() = 0;
        virtual uint32_t GetModelFlags() = 0;
        virtual uint32_t GetHandlingFlags() = 0;
        virtual uint32_t GetDamageFlags() = 0;

        virtual void SetMass(float val) = 0;
        virtual void SetInitialDragCoeff(float val) = 0;
        virtual void SetDownforceModifier(float val) = 0;
        virtual void SetunkFloat1(float val) = 0;
        virtual void SetunkFloat2(float val) = 0;
        virtual void SetCentreOfMassOffset(Vector3f val) = 0;
        virtual void SetInertiaMultiplier(Vector3f val) = 0;
        virtual void SetPercentSubmerged(float val) = 0;
        virtual void SetPercentSubmergedRatio(float val) = 0;
        virtual void SetDriveBiasFront(float val) = 0;
        virtual void SetAcceleration(float val) = 0;
        virtual void SetInitialDriveGears(uint32_t val) = 0;
        virtual void SetDriveInertia(float val) = 0;
        virtual void SetClutchChangeRateScaleUpShift(float val) = 0;
        virtual void SetClutchChangeRateScaleDownShift(float val) = 0;
        virtual void SetInitialDriveForce(float val) = 0;
        virtual void SetDriveMaxFlatVel(float val) = 0;
        virtual void SetInitialDriveMaxFlatVel(float val) = 0;
        virtual void SetBrakeForce(float val) = 0;
        virtual void SetunkFloat4(float val) = 0;
        virtual void SetBrakeBiasFront(float val) = 0;
        virtual void SetBrakeBiasRear(float val) = 0;
        virtual void SetHandBrakeForce(float val) = 0;
        virtual void SetSteeringLock(float val) = 0;
        virtual void SetSteeringLockRatio(float val) = 0;
        virtual void SetTractionCurveMax(float val) = 0;
        virtual void SetTractionCurveMaxRatio(float val) = 0;
        virtual void SetTractionCurveMin(float val) = 0;
        virtual void SetTractionCurveMinRatio(float val) = 0;
        virtual void SetTractionCurveLateral(float val) = 0;
        virtual void SetTractionCurveLateralRatio(float val) = 0;
        virtual void SetTractionSpringDeltaMax(float val) = 0;
        virtual void SetTractionSpringDeltaMaxRatio(float val) = 0;
        virtual void SetLowSpeedTractionLossMult(float val) = 0;
        virtual void SetCamberStiffness(float val) = 0;
        virtual void SetTractionBiasFront(float val) = 0;
        virtual void SetTractionBiasRear(float val) = 0;
        virtual void SetTractionLossMult(float val) = 0;
        virtual void SetSuspensionForce(float val) = 0;
        virtual void SetSuspensionCompDamp(float val) = 0;
        virtual void SetSuspensionReboundDamp(float val) = 0;
        virtual void SetSuspensionUpperLimit(float val) = 0;
        virtual void SetSuspensionLowerLimit(float val) = 0;
        virtual void SetSuspensionRaise(float val) = 0;
        virtual void SetSuspensionBiasFront(float val) = 0;
        virtual void SetSuspensionBiasRear(float val) = 0;
        virtual void SetAntiRollBarForce(float val) = 0;
        virtual void SetAntiRollBarBiasFront(float val) = 0;
        virtual void SetAntiRollBarBiasRear(float val) = 0;
        virtual void SetRollCentreHeightFront(float val) = 0;
        virtual void SetRollCentreHeightRear(float val) = 0;
        virtual void SetCollisionDamageMult(float val) = 0;
        virtual void SetWeaponDamageMult(float val) = 0;
        virtual void SetDeformationDamageMult(float val) = 0;
        virtual void SetEngineDamageMult(float val) = 0;
        virtual void SetPetrolTankVolume(float val) = 0;
        virtual void SetOilVolume(float val) = 0;
        virtual void SetunkFloat5(float val) = 0;
        virtual void SetSeatOffsetDistX(float val) = 0;
        virtual void SetSeatOffsetDistY(float val) = 0;
        virtual void SetSeatOffsetDistZ(float val) = 0;
        virtual void SetMonetaryValue(uint32_t val) = 0;
        virtual void SetModelFlags(uint32_t val) = 0;
        virtual void SetHandlingFlags(uint32_t val) = 0;
        virtual void SetDamageFlags(uint32_t val) = 0;

        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };
} // namespace alt
