#pragma once

#include <cstdint>

#include "../types/RGBA.h"
#include "IEntity.h"
#include "../script-objects/IHandlingData.h"
#include "../types/VehicleBadgePosition.h"

namespace alt
{
	class IPlayer;

	class IVehicle : public virtual IEntity
	{
	protected:
		virtual ~IVehicle() = default;

	public:
		virtual IPlayer* GetDriver() const = 0;
		virtual bool IsDestroyed() const = 0;
		virtual uint8_t GetMod(uint8_t category) const = 0;
		virtual uint8_t GetModsCount(uint8_t category) const = 0;
		virtual uint8_t GetModKitsCount() const = 0;
		virtual uint8_t GetModKit() const = 0;
		virtual bool IsPrimaryColorRGB() const = 0;
		virtual uint8_t GetPrimaryColor() const = 0;
		virtual RGBA GetPrimaryColorRGB() const = 0;
		virtual bool IsSecondaryColorRGB() const = 0;
		virtual uint8_t GetSecondaryColor() const = 0;
		virtual RGBA GetSecondaryColorRGB() const = 0;
		virtual uint8_t GetPearlColor() const = 0;
		virtual uint8_t GetWheelColor() const = 0;
		virtual uint8_t GetInteriorColor() const = 0;
		virtual uint8_t GetDashboardColor() const = 0;
		virtual bool IsTireSmokeColorCustom() const = 0;
		virtual RGBA GetTireSmokeColor() const = 0;
		virtual uint8_t GetWheelType() const = 0;
		virtual uint8_t GetWheelVariation() const = 0;
		virtual uint8_t GetRearWheelVariation() const = 0;
		virtual bool GetCustomTires() const = 0;
		virtual uint8_t GetSpecialDarkness() const = 0;
		virtual uint32_t GetNumberplateIndex() const = 0;
		virtual std::string GetNumberplateText() const = 0;
		virtual uint8_t GetWindowTint() const = 0;
		virtual uint8_t GetDirtLevel() const = 0;
		virtual bool IsExtraOn(uint8_t extraID) const = 0;
		virtual bool IsNeonActive() const = 0;
		virtual void GetNeonActive(bool *left, bool *right, bool *front, bool *back) const = 0;
		virtual RGBA GetNeonColor() const = 0;
		virtual uint8_t GetLivery() const = 0;
		virtual uint8_t GetRoofLivery() const = 0;
		virtual std::string GetAppearanceDataBase64() const = 0;
		virtual bool IsEngineOn() const = 0;
		virtual bool IsHandbrakeActive() const = 0;
		virtual uint8_t GetHeadlightColor() const = 0;
		virtual uint32_t GetRadioStationIndex() const = 0;
		virtual bool IsSirenActive() const = 0;
		// TODO document available values. Enum?
		virtual uint8_t GetLockState() const = 0;
		// TODO document available values. Enum?
		virtual uint8_t GetDoorState(uint8_t doorId) const = 0;
		virtual bool IsWindowOpened(uint8_t windowId) const = 0;
		virtual bool IsDaylightOn() const = 0;
		virtual bool IsNightlightOn() const = 0;
		virtual uint8_t GetRoofState() const = 0;
		virtual bool IsFlamethrowerActive() const = 0;
		virtual float GetLightsMultiplier() const = 0;
		virtual std::string GetGameStateBase64() const = 0;
		virtual int32_t GetEngineHealth() const = 0;
		virtual int32_t GetPetrolTankHealth() const = 0;
		virtual uint8_t GetWheelsCount() const = 0;
		virtual bool IsWheelBurst(uint8_t wheelId) = 0;
		virtual bool DoesWheelHasTire(uint8_t wheelId) = 0;
		virtual bool IsWheelDetached(uint8_t wheelId) = 0;
		virtual bool IsWheelOnFire(uint8_t wheelId) = 0;
		virtual float GetWheelHealth(uint8_t wheelId) = 0;
		virtual uint8_t GetRepairsCount() const = 0;
		virtual uint32_t GetBodyHealth() const = 0;
		virtual uint32_t GetBodyAdditionalHealth() const = 0;
		virtual std::string GetHealthDataBase64() const = 0;
		virtual uint8_t GetPartDamageLevel(uint8_t partId) = 0;
		virtual uint8_t GetPartBulletHoles(uint8_t partId) = 0;
		virtual bool IsLightDamaged(uint8_t lightId) = 0;
		virtual bool IsWindowDamaged(uint8_t windowId) = 0;
		virtual bool IsSpecialLightDamaged(uint8_t specialLightId) = 0;
		virtual bool HasArmoredWindows() const = 0;
		virtual float GetArmoredWindowHealth(uint8_t windowId) = 0;
		virtual uint8_t GetArmoredWindowShootCount(uint8_t windowId) = 0;
		virtual uint8_t GetBumperDamageLevel(uint8_t bumperId) = 0;
		virtual std::string GetDamageDataBase64() const = 0;
		virtual bool IsManualEngineControl() const = 0;
		virtual std::string GetScriptDataBase64() const = 0;
		virtual void ToggleExtra(uint8_t extraID, bool state) = 0;
		virtual Vector3f GetVelocity() const = 0;
		virtual float GetSteeringAngle() const = 0;

#ifdef ALT_SERVER_API
		virtual void SetFixed() = 0;
		virtual bool SetMod(uint8_t category, uint8_t id) = 0;
		virtual bool SetModKit(uint8_t id) = 0;
		virtual void SetPrimaryColor(uint8_t color) = 0;
		virtual void SetPrimaryColorRGB(RGBA color) = 0;
		virtual void SetSecondaryColor(uint8_t color) = 0;
		virtual void SetSecondaryColorRGB(RGBA color) = 0;
		virtual void SetPearlColor(uint8_t color) = 0;
		virtual void SetWheelColor(uint8_t color) = 0;
		virtual void SetInteriorColor(uint8_t color) = 0;
		virtual void SetDashboardColor(uint8_t color) = 0;
		virtual void SetTireSmokeColor(RGBA color) = 0;
		virtual void SetWheels(uint8_t type, uint8_t variation) = 0;
		virtual void SetRearWheels(uint8_t variation) = 0;
		virtual void SetCustomTires(bool state) = 0;
		virtual void SetSpecialDarkness(uint8_t value) = 0;
		virtual void SetNumberplateIndex(uint32_t index) = 0;
		virtual void SetNumberplateText(const std::string& text) = 0;
		virtual void SetWindowTint(uint8_t tint) = 0;
		virtual void SetDirtLevel(uint8_t level) = 0;
		virtual void SetNeonActive(bool left, bool right, bool front, bool back) = 0;
		virtual void SetNeonColor(RGBA color) = 0;
		virtual void SetLivery(uint8_t livery) = 0;
		virtual void SetRoofLivery(uint8_t roofLivery) = 0;
		virtual void LoadAppearanceDataFromBase64(const std::string& base64) = 0;
		virtual void SetEngineOn(bool state) = 0;
		virtual void SetHeadlightColor(uint8_t color) = 0;
		virtual void SetRadioStationIndex(uint32_t stationIndex) = 0;
		virtual void SetSirenActive(bool state) = 0;
		virtual void SetLockState(uint8_t state) = 0;
		virtual void SetDoorState(uint8_t doorId, uint8_t state) = 0;
		virtual void SetWindowOpened(uint8_t windowId, bool state) = 0;
		virtual void SetRoofState(uint8_t state) = 0;
		virtual void SetLightsMultiplier(float multiplier) = 0;
		virtual void SetEngineHealth(int32_t health) = 0;
		virtual void SetPetrolTankHealth(int32_t health) = 0;
		virtual void SetWheelBurst(uint8_t wheelId, bool state) = 0;
		virtual void SetWheelHasTire(uint8_t wheelId, bool state) = 0;
		virtual void SetWheelDetached(uint8_t wheelId, bool state) = 0;
		virtual void SetWheelOnFire(uint8_t wheelId, bool state) = 0;
		virtual void SetWheelHealth(uint8_t wheelId, float health) = 0;
		virtual void SetWheelFixed(uint8_t wheelId) = 0;
		virtual void SetBodyHealth(uint32_t health) = 0;
		virtual void SetBodyAdditionalHealth(uint32_t health) = 0;
		virtual void SetPartDamageLevel(uint8_t partId, uint8_t damage) = 0;
		virtual void SetPartBulletHoles(uint8_t partId, uint8_t shootsCount) = 0;
		virtual void SetLightDamaged(uint8_t lightId, bool isDamaged) = 0;
		virtual void SetWindowDamaged(uint8_t windowId, bool isDamaged) = 0;
		virtual void SetSpecialLightDamaged(uint8_t specialLightId, bool isDamaged) = 0;
		virtual void SetArmoredWindowHealth(uint8_t windowId, float health) = 0;
		virtual void SetArmoredWindowShootCount(uint8_t windowId, uint8_t count) = 0;
		virtual void SetBumperDamageLevel(uint8_t bumperId, uint8_t damageLevel) = 0;
		virtual void SetManualEngineControl(bool state) = 0;
		virtual void LoadDamageDataFromBase64(const std::string& base64) = 0;
		virtual void LoadScriptDataFromBase64(const std::string& base64) = 0;
		virtual void LoadGameStateFromBase64(const std::string& base64) = 0;
		virtual void LoadHealthDataFromBase64(const std::string& base64) = 0;
		virtual IVehicle* GetAttached() const = 0;
		virtual IVehicle* GetAttachedTo() const = 0;
		virtual bool IsDriftMode() const = 0;
		virtual void SetDriftMode(bool state) = 0;
		virtual bool IsHornActive() const = 0;

		virtual bool IsTrainMissionTrain() const = 0;
		virtual void SetTrainMissionTrain(bool value) = 0;
		virtual int8_t GetTrainTrackId() const = 0;
		virtual void SetTrainTrackId(int8_t trackId) = 0;
		virtual IVehicle* GetTrainEngineId() const = 0;
		virtual void SetTrainEngineId(IVehicle* vehicle) = 0;
		virtual int8_t GetTrainConfigIndex() const = 0;
		virtual void SetTrainConfigIndex(int8_t trainConfigIndex) = 0;
		virtual float GetTrainDistanceFromEngine() const = 0;
		virtual void SetTrainDistanceFromEngine(float distanceFromEngine) = 0;
		virtual bool IsTrainEngine() const = 0;
		virtual void SetTrainIsEngine(bool isEngine) = 0;
		virtual bool IsTrainCaboose() const = 0;
		virtual void SetTrainIsCaboose(bool isCaboose) = 0;
		virtual bool GetTrainDirection() const = 0;
		virtual void SetTrainDirection(bool direction) = 0;
		virtual bool HasTrainPassengerCarriages() const = 0;
		virtual void SetTrainHasPassengerCarriages(bool hasPassengerCarriages) = 0;
		virtual bool GetTrainRenderDerailed() const = 0;
		virtual void SetTrainRenderDerailed(bool renderDerailed) = 0;
		virtual bool GetTrainForceDoorsOpen() const = 0;
		virtual void SetTrainForceDoorsOpen(bool forceDoorsOpen) = 0;
		virtual float GetTrainCruiseSpeed() const = 0;
		virtual void SetTrainCruiseSpeed(float cruiseSpeed) = 0;
		virtual int8_t GetTrainCarriageConfigIndex() const = 0;
		virtual void SetTrainCarriageConfigIndex(int8_t carriageConfigIndex) = 0;
		virtual IVehicle* GetTrainLinkedToBackwardId() const = 0;
		virtual void SetTrainLinkedToBackwardId(IVehicle* vehicle) = 0;
		virtual IVehicle* GetTrainLinkedToForwardId() const = 0;
		virtual void SetTrainLinkedToForwardId(IVehicle* vehicle) = 0;
		virtual void SetTrainUnk1(bool unk1) = 0;
		virtual bool GetTrainUnk1() const = 0;
		virtual void SetTrainUnk2(bool unk2) = 0;
		virtual bool GetTrainUnk2() const = 0;
		virtual void SetTrainUnk3(bool unk3) = 0;
		virtual bool GetTrainUnk3() const = 0;

		virtual bool IsBoatAnchorActive() const = 0;
		virtual void SetBoatAnchorActive(bool state) = 0;

		virtual bool SetSearchLight(bool state, IEntity* spottedEntity) = 0;

		virtual uint8_t GetLightState() const = 0;
		virtual void SetLightState(uint8_t state) = 0;

		virtual bool HasTimedExplosion() const = 0;
		virtual IPlayer* GetTimedExplosionCulprit() const = 0;
		virtual uint32_t GetTimedExplosionTime() const = 0;
		virtual void SetTimedExplosion(bool state, IPlayer* culprit, uint32_t time) = 0;
		
		virtual bool IsTowingDisabled() const = 0;
		virtual void SetDisableTowing(bool state) = 0;
		
		virtual float GetRocketRefuelSpeed() const = 0;
		virtual void SetRocketRefuelSpeed(float rocketRefuelSpeed) = 0;
		
		virtual uint32_t GetCounterMeasureCount() const = 0;
		virtual void SetCounterMeasureCount(uint32_t counterMeasureCount) = 0;
		
		virtual float GetScriptMaxSpeed() const = 0;
		virtual void SetScriptMaxSpeed(float scriptMaxSpeed) = 0;
		
		virtual int32_t GetWeaponCapacity(uint8_t index) const = 0;
		virtual void SetWeaponCapacity(uint8_t index, int32_t state) = 0;
		
		virtual bool GetHybridExtraActive() const = 0;
		virtual void SetHybridExtraActive(bool state) = 0;
		
		virtual uint8_t GetHybridExtraState() const = 0;
		virtual void SetHybridExtraState(uint8_t state) = 0;

		virtual Quaternion GetQuaternion() const = 0;
		virtual void SetQuaternion(Quaternion quaternion) = 0;

		virtual float GetAccelerationLevel() const = 0;
		virtual float GetBrakeLevel() const = 0;

		virtual void SetBadge(uint32_t textureDictionary, uint32_t texture, VehicleBadgePosition positions[4]) = 0;
#endif // ALT_SERVER_API

#ifdef ALT_CLIENT_API
		virtual float GetWheelSpeed() const = 0;
		virtual uint16_t GetCurrentGear() const = 0;
		virtual float GetCurrentRPM() const = 0;
		virtual Vector3f GetSpeedVector() const = 0;
		virtual uint16_t GetMaxGear() const = 0;
		virtual void SetSteeringAngle(float value) = 0;

		virtual void SetCurrentGear(uint16_t currentGear) = 0;
		virtual void SetMaxGear(uint16_t gearMax) = 0;
		virtual void SetCurrentRPM(float rpm) = 0;

		virtual bool IsHandlingModified() const = 0;
		virtual std::shared_ptr<alt::IHandlingData> GetHandling() const = 0;
		virtual void ResetHandling() = 0;
		virtual void ReplaceHandling() = 0;

		virtual uint8_t GetLightsIndicator() const = 0;
		virtual void SetLightsIndicator(uint8_t lightsIndicatorFlag) = 0;

		virtual uint8_t GetSeatCount() const = 0;
		virtual uint8_t GetOccupiedSeatsCount() const = 0;

		virtual void ToggleTaxiLight(bool state) = 0;
		virtual bool IsTaxiLightOn() const = 0;

		virtual float GetWheelCamber(uint8_t wheel) const = 0;
		virtual void SetWheelCamber(uint8_t wheel, float value) = 0;
		virtual float GetWheelTrackWidth(uint8_t wheel) const = 0;
		virtual void SetWheelTrackWidth(uint8_t wheel, float value) = 0;
		virtual float GetWheelHeight(uint8_t wheel) const = 0;
		virtual void SetWheelHeight(uint8_t wheel, float value) = 0;
		virtual float GetWheelTyreRadius(uint8_t wheel) const = 0;
		virtual void SetWheelTyreRadius(uint8_t wheel, float value) = 0;
		virtual float GetWheelRimRadius(uint8_t wheel) const = 0;
		virtual void SetWheelRimRadius(uint8_t wheel, float value) = 0;
		virtual float GetWheelTyreWidth(uint8_t wheel) const = 0;
		virtual void SetWheelTyreWidth(uint8_t wheel, float value) = 0;
		virtual uint32_t GetWheelSurfaceMaterial(uint8_t wheel) const = 0;

		virtual bool GetWheelDynamicFlag(uint8_t wheel, uint32_t flag) const = 0;
		virtual void SetWheelDynamicFlag(uint8_t wheel, uint32_t flag, bool state) = 0;
		virtual bool GetWheelConfigFlag(uint8_t wheel, uint32_t flag) const = 0;
		virtual void SetWheelConfigFlag(uint8_t wheel, uint32_t flag, bool state) = 0;

		virtual float GetEngineTemperature() const = 0;
		virtual void SetEngineTemperature(float value) = 0;
		virtual float GetFuelLevel() const = 0;
		virtual void SetFuelLevel(float value) = 0;
		virtual float GetOilLevel() const = 0;
		virtual void SetOilLevel(float value) = 0;
		virtual bool GetEngineLightState() const = 0;
		virtual void SetEngineLightState(bool state) = 0;
		virtual bool GetAbsLightState() const = 0;
		virtual void SetAbsLightState(bool state) = 0;
		virtual bool GetPetrolLightState() const = 0;
		virtual void SetPetrolLightState(bool state) = 0;
		virtual bool GetOilLightState() const = 0;
		virtual void SetOilLightState(bool state) = 0;
		virtual bool GetBatteryLightState() const = 0;
		virtual void SetBatteryLightState(bool state) = 0;
		virtual void ResetDashboardLights() = 0;
		virtual float GetSuspensionHeight() const = 0;
		virtual void SetSuspensionHeight(float value) = 0;

		virtual void SetupTransmission() = 0;
#endif // ALT_CLIENT_API
	};
} // namespace alt
