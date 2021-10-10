#pragma once

#include <cstdint>

#include "../types/String.h"
#include "../types/StringView.h"
#include "../types/RGBA.h"
#include "IEntity.h"
#include "../script-objects/IHandlingData.h"

namespace alt
{
	class IPlayer;

	class IVehicle : public virtual IEntity
	{
	protected:
		virtual ~IVehicle() = default;

	public:
		virtual Ref<IPlayer> GetDriver() const = 0;
		virtual bool IsDestroyed() const = 0;
		virtual uint8_t GetMod(uint8_t category) = 0;
		virtual uint8_t GetModsCount(uint8_t category) = 0;
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
		virtual StringView GetNumberplateText() const = 0;
		virtual uint8_t GetWindowTint() const = 0;
		virtual uint8_t GetDirtLevel() const = 0;
		virtual bool IsExtraOn(uint8_t extraID) const = 0;
		virtual bool IsNeonActive() const = 0;
		virtual void GetNeonActive(bool *left, bool *right, bool *front, bool *back) const = 0;
		virtual RGBA GetNeonColor() const = 0;
		virtual uint8_t GetLivery() const = 0;
		virtual uint8_t GetRoofLivery() const = 0;
		virtual String GetAppearanceDataBase64() = 0;
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
		virtual String GetGameStateBase64() = 0;
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
		virtual String GetHealthDataBase64() = 0;
		virtual uint8_t GetPartDamageLevel(uint8_t partId) = 0;
		virtual uint8_t GetPartBulletHoles(uint8_t partId) = 0;
		virtual bool IsLightDamaged(uint8_t lightId) = 0;
		virtual bool IsWindowDamaged(uint8_t windowId) = 0;
		virtual bool IsSpecialLightDamaged(uint8_t specialLightId) = 0;
		virtual bool HasArmoredWindows() const = 0;
		virtual float GetArmoredWindowHealth(uint8_t windowId) = 0;
		virtual uint8_t GetArmoredWindowShootCount(uint8_t windowId) = 0;
		virtual uint8_t GetBumperDamageLevel(uint8_t bumperId) = 0;
		virtual String GetDamageDataBase64() = 0;
		virtual bool IsManualEngineControl() const = 0;
		virtual String GetScriptDataBase64() = 0;
		virtual void ToggleExtra(uint8_t extraID, bool state) = 0;
		virtual Vector3f GetVelocity() const = 0;

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
		virtual void SetNumberplateText(StringView text) = 0;
		virtual void SetWindowTint(uint8_t tint) = 0;
		virtual void SetDirtLevel(uint8_t level) = 0;
		virtual void SetNeonActive(bool left, bool right, bool front, bool back) = 0;
		virtual void SetNeonColor(RGBA color) = 0;
		virtual void SetLivery(uint8_t livery) = 0;
		virtual void SetRoofLivery(uint8_t roofLivery) = 0;
		virtual void LoadAppearanceDataFromBase64(StringView base64) = 0;
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
		virtual void LoadDamageDataFromBase64(StringView base64) = 0;
		virtual void LoadScriptDataFromBase64(StringView base64) = 0;
		virtual void LoadGameStateFromBase64(StringView base64) = 0;
		virtual void LoadHealthDataFromBase64(StringView base64) = 0;
		virtual Ref<IVehicle> GetAttached() const = 0;
		virtual Ref<IVehicle> GetAttachedTo() const = 0;
		virtual bool IsDriftMode() const = 0;
		virtual void SetDriftMode(bool state) = 0;
#endif // ALT_SERVER_API

#ifdef ALT_CLIENT_API
		virtual float GetWheelSpeed() const = 0;
		virtual uint16_t GetCurrentGear() const = 0;
		virtual float GetCurrentRPM() const = 0;
		virtual Vector3f GetSpeedVector() const = 0;
		virtual uint16_t GetMaxGear() const = 0;

		virtual void SetCurrentGear(uint16_t currentGear) = 0;
		virtual void SetMaxGear(uint16_t gearMax) = 0;

		virtual bool IsHandlingModified() const = 0;
		virtual alt::Ref<alt::IHandlingData> GetHandling() const = 0;
		virtual void ResetHandling() = 0;
		virtual void ReplaceHandling() = 0;

		virtual uint8_t GetLightsIndicator() const = 0;
		virtual void SetLightsIndicator(uint8_t lightsIndicatorFlag) = 0;
#endif // ALT_CLIENT_API
		
		const std::type_info& GetTypeInfo() const override { return typeid(this); }
	};
} // namespace alt
