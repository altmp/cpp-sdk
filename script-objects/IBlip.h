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
		virtual Vector2f GetScaleXY() const = 0;
		virtual void SetScaleXY(float x, float y) = 0;
		virtual int GetDisplay() const = 0;
		virtual void SetDisplay(int display) = 0;
		virtual int GetSprite() const = 0;
		virtual int GetColor() const = 0;
		virtual alt::RGBA GetSecondaryColor() const = 0;
		virtual int GetAlpha() const = 0;
		virtual int GetFlashTimer() const = 0;
		virtual int GetFlashInterval() const = 0;
		virtual bool GetAsFriendly() const = 0;
		virtual bool GetRoute() const = 0;
		virtual bool GetBright() const = 0;
		virtual int GetNumber() const = 0;
		virtual bool GetShowCone() const = 0;
		virtual bool GetFlashes() const = 0;
		virtual bool GetFlashesAlternate() const = 0;
		virtual bool GetAsShortRange() const = 0;
		virtual int GetPriority() const = 0;
		virtual float GetRotation() const = 0;
		virtual const char *GetGxtName() const = 0;
		virtual const char *GetName() const = 0;
		virtual alt::RGBA GetRouteColor() const = 0;
		virtual bool GetPulse() const = 0;
		virtual bool GetAsMissionCreator() const = 0;
		virtual bool GetTickVisible() const = 0;
		virtual bool GetHeadingIndicatorVisible() const = 0;
		virtual bool GetOutlineIndicatorVisible() const = 0;
		virtual bool GetFriendIndicatorVisible() const = 0;
		virtual bool GetCrewIndicatorVisible() const = 0;
		virtual int GetCategory() const = 0;
		virtual bool GetAsHighDetail() const = 0;
		virtual bool GetShrinked() const = 0;

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

		const std::type_info& GetTypeInfo() const override { return typeid(this); }
	};
} // namespace alt
