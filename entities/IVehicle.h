#pragma once

#include <cstdint>

#include "../types/String.h"
#include "../types/StringView.h"
#include "../types/RGBA.h"
#include "IEntity.h"

namespace alt
{
	class IPlayer;

	class IVehicle : public virtual IEntity
	{
	public:
		virtual IPlayer* GetDriver() = 0;

		virtual uint8_t GetMod(uint8_t category) = 0;
		virtual uint8_t GetModsCount(uint8_t category) = 0;
		virtual bool SetMod(uint8_t category, uint8_t id) = 0;

		virtual uint8_t GetModKitsCount() = 0;
		virtual uint8_t GetModKit() = 0;
		virtual bool SetModKit(uint8_t id) = 0;

		virtual bool IsPrimaryColorRGB() = 0;
		virtual uint8_t GetPrimaryColor() = 0;
		virtual RGBA GetPrimaryColorRGB() = 0;
		virtual void SetPrimaryColor(uint8_t color) = 0;
		virtual void SetPrimaryColorRGB(RGBA color) = 0;

		virtual bool IsSecondaryColorRGB() = 0;
		virtual uint8_t GetSecondaryColor() = 0;
		virtual RGBA GetSecondaryColorRGB() = 0;
		virtual void SetSecondaryColor(uint8_t color) = 0;
		virtual void SetSecondaryColorRGB(RGBA color) = 0;

		virtual uint8_t GetPearlColor() = 0;
		virtual void SetPearlColor(uint8_t color) = 0;

		virtual uint8_t GetWheelColor() = 0;
		virtual void SetWheelColor(uint8_t color) = 0;

		virtual uint8_t GetInteriorColor() = 0;
		virtual void SetInteriorColor(uint8_t color) = 0;

		virtual uint8_t GetDashboardColor() = 0;
		virtual void SetDashboardColor(uint8_t color) = 0;

		virtual bool IsTireSmokeColorCustom() = 0;
		virtual RGBA GetTireSmokeColor() = 0;
		virtual void SetTireSmokeColor(RGBA color) = 0;

		virtual uint8_t GetWheelType() = 0;
		virtual uint8_t GetWheelVariation() = 0;
		virtual void SetWheels(uint8_t type, uint8_t variation) = 0;

		virtual bool GetCustomTires() = 0;
		virtual void SetCustomTires(bool state) = 0;

		virtual uint8_t GetSpecialDarkness() = 0;
		virtual void SetSpecialDarkness(uint8_t value) = 0;

		virtual uint32_t GetNumberplateIndex() = 0;
		virtual void SetNumberplateIndex(uint32_t index) = 0;

		virtual StringView GetNumberplateText() = 0;
		virtual void SetNumberplateText(StringView text) = 0;

		virtual uint8_t GetWindowTint() = 0;
		virtual void SetWindowTint(uint8_t tint) = 0;

		virtual uint8_t GetDirtLevel() = 0;
		virtual void SetDirtLevel(uint8_t level) = 0;

		virtual bool IsExtraOn(uint8_t extraID) = 0;
		virtual void ToggleExtra(uint8_t extraID, bool state) = 0;

		virtual bool IsNeonActive() = 0;
		virtual void GetNeonActive(bool* left, bool* right, bool* front, bool* back) = 0;
		virtual void SetNeonActive(bool left, bool right, bool front, bool back) = 0;
		virtual RGBA GetNeonColor() = 0;
		virtual void SetNeonColor(RGBA color) = 0;

		virtual uint8_t GetLivery() = 0;
		virtual void SetLivery(uint8_t livery) = 0;
		virtual uint8_t GetRoofLivery() = 0;
		virtual void SetRoofLivery(uint8_t roofLivery) = 0;

		virtual String GetAppearanceDataBase64() = 0;
		virtual void LoadAppearanceDataFromBase64(StringView base64) = 0;
		
		//vehicle game state
		virtual bool IsEngineOn() = 0;
		virtual void SetEngineOn(bool state) = 0;

		virtual bool IsHandbrakeActive() = 0;

		virtual uint8_t GetHeadlightColor() = 0;
		virtual void SetHeadlightColor(uint8_t color) = 0;

		virtual uint32_t GetRadioStationIndex() = 0;
		virtual void SetRadioStationIndex(uint32_t stationIndex) = 0;

		virtual bool IsSirenActive() = 0;
		virtual void SetSirenActive(bool state) = 0;

		// TODO document available values. Enum?
		virtual uint8_t GetLockState() = 0;
		virtual void SetLockState(uint8_t state) = 0;

		// TODO document available values. Enum?
		virtual uint8_t GetDoorState(uint8_t doorId) = 0;
		virtual void SetDoorState(uint8_t doorId, uint8_t state) = 0;

		virtual bool IsWindowOpened(uint8_t windowId) = 0;
		virtual void SetWindowOpened(uint8_t windowId, bool state) = 0;

		virtual bool IsDaylightOn() = 0;
		virtual bool IsNightlightOn() = 0;

		virtual bool IsRoofOpened() = 0;
		virtual void SetRoofOpened(bool state) = 0;

		virtual bool IsFlamethrowerActive() = 0;

		virtual float GetLightsMultiplier() = 0;
		virtual void SetLightsMultiplier(float multiplier) = 0;

		virtual String GetGameStateBase64() = 0;
		virtual void LoadGameStateFromBase64(StringView base64) = 0;

		//vehicle health
		virtual int32_t GetEngineHealth() = 0;
		virtual void SetEngineHealth(int32_t health) = 0;

		virtual int32_t GetPetrolTankHealth() = 0;
		virtual void SetPetrolTankHealth(int32_t health) = 0;

		virtual uint8_t GetWheelsCount() = 0;

		virtual bool IsWheelBurst(uint8_t wheelId) = 0;
		virtual void SetWheelBurst(uint8_t wheelId, bool state) = 0;

		virtual bool DoesWheelHasTire(uint8_t wheelId) = 0;
		virtual void SetWheelHasTire(uint8_t wheelId, bool state) = 0;

		virtual float GetWheelHealth(uint8_t wheelId) = 0;
		virtual void SetWheelHealth(uint8_t wheelId, float health) = 0;

		virtual uint8_t GetRepairsCount() = 0;

		// Will be moved to event
		//virtual IEntity* GetLastAttacker() = 0;
		//virtual uint32_t GetLastDamagedWith() = 0;

		virtual uint32_t GetBodyHealth() = 0;
		virtual void SetBodyHealth(uint32_t health) = 0;
		virtual uint32_t GetBodyAdditionalHealth() = 0;
		virtual void SetBodyAdditionalHealth(uint32_t health) = 0;

		virtual String GetHealthDataBase64() = 0;
		virtual void LoadHealthDataFromBase64(StringView base64) = 0;

		// vehicle damage
		virtual uint8_t GetPartDamageLevel(uint8_t partId) = 0;
		virtual void SetPartDamageLevel(uint8_t partId, uint8_t damage) = 0;
		virtual uint8_t GetPartBulletHoles(uint8_t partId) = 0;
		virtual void SetPartBulletHoles(uint8_t partId, uint8_t shootsCount) = 0;
		virtual bool IsLightDamaged(uint8_t lightId) = 0;
		virtual void SetLightDamaged(uint8_t lightId, bool isDamaged) = 0;
		virtual bool IsWindowDamaged(uint8_t windowId) = 0;
		virtual void SetWindowDamaged(uint8_t windowId, bool isDamaged) = 0;
		virtual bool IsSpecialLightDamaged(uint8_t specialLightId) = 0;
		virtual void SetSpecialLightDamaged(uint8_t specialLightId, bool isDamaged) = 0;
		virtual bool HasArmoredWindows() = 0;
		virtual float GetArmoredWindowHealth(uint8_t windowId) = 0;
		virtual void SetArmoredWindowHealth(uint8_t windowId, float health) = 0;
		virtual uint8_t GetArmoredWindowShootCount(uint8_t windowId) = 0;
		virtual void SetArmoredWindowShootCount(uint8_t windowId, uint8_t count) = 0;
		virtual uint8_t GetBumperDamageLevel(uint8_t bumperId) = 0;
		virtual void SetBumperDamageLevel(uint8_t bumperId, uint8_t damageLevel) = 0;

		virtual String GetDamageDataBase64() = 0;
		virtual void LoadDamageDataFromBase64(StringView base64) = 0;

		//vehicle script data
		virtual void SetManualEngineControl(bool state) = 0;
		virtual bool IsManualEngineControl() = 0;

		virtual String GetScriptDataBase64() = 0;
		virtual void LoadScriptDataFromBase64(StringView base64) = 0;

	protected:
		virtual ~IVehicle() = default;
	};
}
