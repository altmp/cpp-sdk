#pragma once

#include <vector>
#include <functional>

#include "IEntity.h"
#include "IVehicle.h"
#include "../types/Cloth.h"
#include "../types/DlcCloth.h"
#include "../types/Prop.h"
#include "../types/DlcProp.h"
#include "../types/HeadBlendData.h"
#include "../types/HeadOverlay.h"
#include "../types/Weapon.h"
#include "../types/AmmoSpecialType.h"
#include "../types/AmmoFlags.h"
#include "../types/Decoration.h"
#include "../types/CloudAuthResult.h"

namespace alt
{
	class IAudioFilter;

	class IPlayer : public virtual IEntity
	{
	protected:
		virtual ~IPlayer() = default;

	public:
		virtual std::string GetName() const = 0;

		virtual uint16_t GetHealth() const = 0;
		virtual uint16_t GetMaxHealth() const = 0;

		virtual bool HasWeaponComponent(uint32_t weapon, uint32_t component) const = 0;
		virtual std::vector<uint32_t> GetCurrentWeaponComponents() const = 0;

		virtual uint8_t GetWeaponTintIndex(uint32_t weapon) const = 0;
		virtual uint8_t GetCurrentWeaponTintIndex() const = 0;

		virtual uint32_t GetCurrentWeapon() const = 0;

		virtual bool IsDead() const = 0;

		virtual bool IsJumping() const = 0;
		virtual bool IsInRagdoll() const = 0;
		virtual bool IsAiming() const = 0;
		virtual bool IsShooting() const = 0;
		virtual bool IsReloading() const = 0;
		virtual bool IsEnteringVehicle() const = 0;
		virtual bool IsLeavingVehicle() const = 0;
		virtual bool IsOnLadder() const = 0;
		virtual bool IsInMelee() const = 0;
		virtual bool IsInCover() const = 0;
		virtual bool IsParachuting() const = 0;

		virtual uint16_t GetArmour() const = 0;
		virtual uint16_t GetMaxArmour() const = 0;

		virtual float GetMoveSpeed() const = 0;

		virtual Position GetAimPos() const = 0;
		virtual Rotation GetHeadRotation() const = 0;

		virtual bool IsInVehicle() const = 0;
		virtual IVehicle* GetVehicle() const = 0;
		virtual uint8_t GetSeat() const = 0;

		virtual IEntity* GetEntityAimingAt() const = 0;
		virtual Position GetEntityAimOffset() const = 0;

		virtual bool IsFlashlightActive() const = 0;

		virtual bool IsSuperJumpEnabled() const = 0;
		virtual bool IsCrouching() const = 0;
		virtual bool IsStealthy() const = 0;

		virtual uint32_t GetCurrentAnimationDict() const = 0;
		virtual uint32_t GetCurrentAnimationName() const = 0;

		virtual bool IsSpawned() const = 0;

		virtual float GetForwardSpeed() const = 0;
		virtual float GetStrafeSpeed() const = 0;

#ifdef ALT_SERVER_API
		virtual bool IsConnected() const = 0;
		virtual uint32_t GetPing() const = 0;
		virtual std::string GetIP() const = 0;
		virtual uint64_t GetSocialID() const = 0;
		virtual std::string GetSocialClubName() const = 0;
		virtual uint64_t GetHwidHash() const = 0;
		virtual uint64_t GetHwidExHash() const = 0;
		virtual std::string GetHwid3() const = 0;
		virtual std::string GetAuthToken() const = 0;
		virtual int64_t GetDiscordId() const = 0;

		virtual void Spawn(Position pos, uint32_t delayMs) = 0;
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
		virtual void RemoveAllWeapons(bool removeAllAmmo) = 0;
		virtual void SetDateTime(int day, int month, int year, int hour, int minute, int second) = 0;
		virtual void SetWeather(uint32_t weather) = 0;
		virtual void Kick(const std::string& reason = "Kicked") = 0;
		virtual alt::Cloth GetClothes(uint8_t component) const = 0;
		virtual bool SetClothes(uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette) = 0;
		virtual alt::DlcCloth GetDlcClothes(uint8_t component) const = 0;
		virtual bool SetDlcClothes(uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette, uint32_t dlc) = 0;
		virtual bool ClearClothes(uint8_t component) = 0;
		virtual alt::Prop GetProps(uint8_t component) const = 0;
		virtual bool SetProps(uint8_t component, uint16_t drawable, uint8_t texture) = 0;
		virtual alt::DlcProp GetDlcProps(uint8_t component) const = 0;
		virtual bool SetDlcProps(uint8_t component, uint8_t drawable, uint8_t texture, uint32_t dlc) = 0;
		virtual void ClearProps(uint8_t component) = 0;
		virtual bool IsEntityInStreamingRange(uint16_t entityId) = 0;
		virtual void SetInvincible(bool toggle) = 0;
		virtual bool GetInvincible() const = 0;
		virtual void SetIntoVehicle(IVehicle* vehicle, uint8_t seat) = 0;
		virtual void PlayAmbientSpeech(const std::string& speechName, const std::string& speechParam, uint32_t speechDictHash) = 0;
		virtual bool SetHeadOverlay(uint8_t overlayID, uint8_t index, float opacity) = 0;
		virtual bool RemoveHeadOverlay(uint8_t overlayID) = 0;
		virtual bool SetHeadOverlayColor(uint8_t overlayID, uint8_t colorType, uint8_t colorIndex, uint8_t secondColorIndex) = 0;
		virtual HeadOverlay GetHeadOverlay(uint8_t overlayID) const = 0;
		virtual bool SetFaceFeature(uint8_t index, float scale) = 0;
		virtual float GetFaceFeatureScale(uint8_t index) const  = 0;
		virtual bool RemoveFaceFeature(uint8_t index) = 0;
		virtual bool SetHeadBlendPaletteColor(uint8_t id, uint8_t red, uint8_t green, uint8_t blue) = 0;
		virtual void RemoveHeadBlendPaletteColor() = 0;
		virtual RGBA GetHeadBlendPaletteColor(uint8_t id) const = 0;
		virtual void SetHeadBlendData(uint32_t shapeFirstID, uint32_t shapeSecondID, uint32_t shapeThirdID,
			uint32_t skinFirstID, uint32_t skinSecondID, uint32_t skinThirdID,
			float shapeMix, float skinMix, float thirdMix) = 0;
		virtual void RemoveHeadBlendData() = 0;
		virtual HeadBlendData GetHeadBlendData() const  = 0;
		virtual bool SetEyeColor(int16_t eyeColor) = 0;
		virtual int16_t GetEyeColor() const  = 0;
		virtual void SetHairColor(uint8_t hairColor) = 0;
		virtual uint8_t GetHairColor() const  = 0;
		virtual void SetHairHighlightColor(uint8_t hairHighlightColor) = 0;
		virtual uint8_t GetHairHighlightColor() const = 0;
		virtual std::vector<Weapon> GetWeapons() const = 0;
		virtual bool HasWeapon(uint32_t weapon) const = 0;

		virtual bool HasLocalMetaData(const std::string& key) const = 0;
		virtual void SetLocalMetaData(const std::string& key, MValue val) = 0;
		virtual MValueConst GetLocalMetaData(const std::string& key) const = 0;
		virtual void DeleteLocalMetaData(const std::string& key) = 0;
		virtual std::vector<std::string> GetLocalMetaDataKeys() const = 0;

		virtual uint32_t GetInteriorLocation() const = 0;

		virtual uint32_t GetLastDamagedBodyPart() const = 0;
		virtual void SetLastDamagedBodyPart(uint32_t bodyPart) = 0;
		virtual void SetSendNames(bool state) = 0;
		virtual bool GetSendNames() const = 0;

		virtual void PlayAnimation(const std::string& animDict, const std::string& animName, float blendInSpeed, float blendOutSpeed, int duration, int flags, float playbackRate, bool lockX, bool lockY, bool lockZ) = 0;
		virtual void ClearTasks() = 0;
		virtual void PlayScenario(const std::string& name) = 0;

		virtual std::vector<std::pair<IEntity*, int32_t>> GetStreamedEntities() const = 0;

		virtual void SetAmmo(uint32_t ammoHash, uint16_t ammo) = 0;
		virtual uint16_t GetAmmo(uint32_t ammoHash) const = 0;
		virtual void SetWeaponAmmo(uint32_t weaponHash, uint16_t ammo) = 0;
		virtual uint16_t GetWeaponAmmo(uint32_t weaponHash) const = 0;
		virtual void SetAmmoSpecialType(uint32_t ammoHash, AmmoSpecialType ammoSpecialType) = 0;
		virtual AmmoSpecialType GetAmmoSpecialType(uint32_t ammoHash) const = 0;
		virtual void SetAmmoFlags(uint32_t ammoHash, AmmoFlags ammoFlags) = 0;
		virtual AmmoFlags GetAmmoFlags(uint32_t ammoHash) const = 0;
		virtual void SetAmmoMax(uint32_t ammoHash, int32_t ammoMax) = 0;
		virtual int32_t GetAmmoMax(uint32_t ammoHash) const = 0;
		virtual void SetAmmoMax50(uint32_t ammoHash, int32_t ammoMax50) = 0;
		virtual int32_t GetAmmoMax50(uint32_t ammoHash) const = 0;
		virtual void SetAmmoMax100(uint32_t ammoHash, int32_t ammoMax100) = 0;
		virtual int32_t GetAmmoMax100(uint32_t ammoHash) const = 0;

		virtual void AddDecoration(uint32_t collection, uint32_t overlay, uint8_t count = 1) = 0;
		virtual void RemoveDecoration(uint32_t collection, uint32_t overlay) = 0;
		virtual void ClearDecorations() = 0;
		virtual std::vector<CDecoration> GetDecorations() const = 0;

		virtual bool IsNetworkOwnershipDisabled() const = 0;
		virtual void SetNetworkOwnershipDisabled(bool disabled) = 0;

		virtual std::string GetCloudID() const = 0;
		virtual CloudAuthResult GetCloudAuthResult() const = 0;

		virtual std::string GetBloodDamageBase64() const = 0;
		virtual void SetBloodDamageBase64(const std::string& _base64) = 0;
#endif // ALT_SERVER_API

#ifdef ALT_CLIENT_API
		virtual bool IsTalking() const = 0;
		virtual float GetMicLevel() const = 0;

		virtual float GetSpatialVolume() const = 0;
		virtual void SetSpatialVolume(float volume) = 0;
		virtual float GetNonSpatialVolume() const = 0;
		virtual void SetNonSpatialVolume(float volume) = 0;

		virtual void AddFilter(IAudioFilter* filter) = 0;
		virtual void RemoveFilter() = 0;
		virtual IAudioFilter* GetFilter() const = 0;
		virtual std::string GetTaskData() const = 0;
#endif // ALT_CLIENT_API
	};
} // namespace alt
