#pragma once

#include <cstdint>
#include "../Ref.h"
#include "../objects/IWorldObject.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class IBlip : public virtual IWorldObject
	{
	public:
		enum class BlipType
		{
			VEHICLE = 1,
			PED = 2,
			OBJECT = 3,
			DESTINATION = 4,
			CONT = 5,
			PICKUP_UNK = 6,
			RADIUS = 7,
			PICKUP = 8,
			COP = 9,
			AREA = 11,
			GALLERY = 12,
			PICKUP_OBJECT = 13
		};

		virtual ~IBlip() = default;

		virtual bool IsGlobal() const = 0;
		virtual Ref<IPlayer> GetTarget() const = 0;
		virtual bool IsAttached() const = 0;
		virtual Ref<IEntity> AttachedTo() const = 0;
		virtual BlipType GetBlipType() const = 0;

#ifdef ALT_CLIENT_API
		virtual Vector2f GetScaleXY() = 0;
		virtual void SetScaleXY(float x, float y) = 0;
		virtual int GetDisplay() = 0;
		virtual void SetDisplay(int display) = 0;
		virtual int GetSprite() = 0;
		virtual int GetColor() = 0;
		virtual alt::RGBA GetSecondaryColor() = 0;
		virtual int GetAlpha() = 0;
		virtual int GetFlashTimer() = 0;
		virtual int GetFlashInterval() = 0;
		virtual bool GetAsFriendly() = 0;
		virtual bool GetRoute() = 0;
		virtual bool GetBright() = 0;
		virtual int GetNumber() = 0;
		virtual bool GetShowCone() = 0;
		virtual bool GetFlashes() = 0;
		virtual bool GetFlashesAlternate() = 0;
		virtual bool GetAsShortRange() = 0;
		virtual int GetPriority() = 0;
		virtual float GetRotation() = 0;
		virtual const char *GetGxtName() = 0;
		virtual const char *GetName() = 0;
		virtual alt::RGBA GetRouteColor() = 0;
		virtual bool GetPulse() = 0;
		virtual bool GetAsMissionCreator() = 0;
		virtual bool GetTickVisible() = 0;
		virtual bool GetHeadingIndicatorVisible() = 0;
		virtual bool GetOutlineIndicatorVisible() = 0;
		virtual bool GetFriendIndicatorVisible() = 0;
		virtual bool GetCrewIndicatorVisible() = 0;
		virtual int GetCategory() = 0;
		virtual bool GetAsHighDetail() = 0;
		virtual bool GetShrinked() = 0;

		virtual void SetSprite(int sprite) = 0;
		virtual void SetColor(int color) = 0;
		virtual void SetRoute(bool state) = 0;
		virtual void SetRouteColor(alt::RGBA color) = 0;
		virtual void SetSecondaryColor(alt::RGBA color) = 0;
		virtual void SetAlpha(int alpha) = 0;
		virtual void SetFlashTimer(int timer) = 0;
		virtual void SetFlashInterval(int interval) = 0;
		virtual void SetAsFriendly(bool friendly) = 0;
		virtual void SetBright(bool bright) = 0;
		virtual void SetNumber(int number) = 0;
		virtual void SetShowCone(bool state) = 0;
		virtual void SetFlashes(bool state) = 0;
		virtual void SetFlashesAlternate(bool state) = 0;
		virtual void SetAsShortRange(bool state) = 0;
		virtual void SetPriority(int state) = 0;
		virtual void SetRotation(float rot) = 0;
		virtual void SetGxtName(const char *name) = 0;
		virtual void SetName(const char *name) = 0;
		virtual void SetPulse(bool val) = 0;
		virtual void SetAsMissionCreator(bool val) = 0;
		virtual void SetTickVisible(bool val) = 0;
		virtual void SetHeadingIndicatorVisible(bool val) = 0;
		virtual void SetOutlineIndicatorVisible(bool val) = 0;
		virtual void SetFriendIndicatorVisible(bool val) = 0;
		virtual void SetCrewIndicatorVisible(bool val) = 0;
		virtual void SetCategory(int val) = 0;
		virtual void SetAsHighDetail(bool val) = 0;
		virtual void SetShrinked(bool val) = 0;
		virtual void Fade(uint32_t opacity, uint32_t duration) = 0;
#endif
	};
} // namespace alt
