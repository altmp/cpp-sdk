#pragma once

#include <cstdint>

#include "../objects/IWorldObject.h"

namespace alt
{
	class ILocalVehicle : public virtual IWorldObject
	{
	protected:
		virtual ~ILocalVehicle() = default;
	public:
		virtual uint32_t GetID() const = 0;
		virtual uint32_t GetModel() const = 0;
		virtual Rotation GetRotation() const = 0;
		virtual void SetRotation(Rotation rot) = 0;

		virtual uint32_t GetStreamingDistance() const = 0;

		virtual void SetVisible(bool toggle) = 0;
		virtual bool IsVisible() const = 0;

		virtual uint32_t GetScriptID() const = 0;

		//stuff from IVehicle
		virtual uint16_t GetCurrentGear() const = 0;
		virtual float GetWheelSpeed() const = 0;
		virtual float GetCurrentRPM() const = 0;
		virtual uint8_t GetWheelsCount() const = 0;

		virtual Vector3f GetSpeedVector() const = 0;
		virtual uint16_t GetMaxGear() const = 0;
		virtual void SetCurrentGear(uint16_t currentGear) = 0;
		virtual void SetMaxGear(uint16_t gearMax) = 0;
		virtual void SetCurrentRPM(float rpm) = 0;

		virtual bool IsEngineOn() const = 0;
		virtual uint8_t GetLockState() const = 0;
		virtual int32_t GetPetrolTankHealth() const = 0;

		virtual bool IsHandlingModified() const = 0;
		virtual std::shared_ptr<alt::IHandlingData> GetHandling() const = 0;
		virtual void ResetHandling() = 0;
		virtual void ReplaceHandling() = 0;

		virtual void ToggleExtra(uint8_t extraID, bool state) = 0;
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

		virtual float GetEngineTemperature() const = 0;
		virtual void SetEngineTemperature(float value) = 0;
		virtual float GetFuelLevel() const = 0;
		virtual void SetFuelLevel(float value) = 0;
		virtual float GetOilLevel() const = 0;
		virtual void SetOilLevel(float value) = 0;

#ifdef ALT_CLIENT_API
		virtual uint32_t GetRemoteID() const = 0;
		virtual bool IsRemote() const = 0;
		virtual bool IsStreamedIn() const = 0;
#endif
	};
}