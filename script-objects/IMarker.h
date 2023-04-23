#pragma once

#include <cstdint>
#include "../objects/IWorldObject.h"

namespace alt
{
	class IMarker : public virtual IWorldObject
	{
	public:
		enum class MarkerType : uint32_t
		{
			MARKER_CONE = 0,
			MARKER_CYLINDER = 1,
			MARKER_ARROW = 2,
			MARKER_ARROW_FLAT = 3,
			MARKER_FLAG = 4,
			MARKER_RING_FLAG = 5,
			MARKER_RING = 6,
			MARKER_PLANE = 7,
			MARKER_BIKE_LOGO1 = 8,
			MARKER_BIKE_LOGO2 = 9,
			MARKER_NUM_0 = 10,
			MARKER_NUM_1 = 11,
			MARKER_NUM_2 = 12,
			MARKER_NUM_3 = 13,
			MARKER_NUM_4 = 14,
			MARKER_NUM_5 = 15,
			MARKER_NUM_6 = 16,
			MARKER_NUM_7 = 17,
			MARKER_NUM_8 = 18,
			MARKER_NUM_9 = 19,
			MARKER_CHEVRON_1 = 20,
			MARKER_CHEVRON_2 = 21,
			MARKER_CHEVRON_3 = 22,
			MARKER_RINGFLAT = 23,
			MARKER_LAP = 24,
			MARKER_HALO = 25,
			MARKER_HALO_POINT = 26,
			MARKER_HALO_ROTATE = 27,
			MARKER_SPHERE = 28,
			MARKER_MONEY = 29,
			MARKER_LINES = 30,
			MARKER_BEAST = 31,
			MARKER_QUESTION_MARK = 32,
			MARKER_TRANSFORM_PLANE = 33,
			MARKER_TRANSFORM_HELICOPTER = 34,
			MARKER_TRANSFORM_BOAT = 35,
			MARKER_TRANSFORM_CAR = 36,
			MARKER_TRANSFORM_BIKE = 37,
			MARKER_TRANSFORM_PUSH_BIKE = 38,
			MARKER_TRANSFORM_TRUCK = 39,
			MARKER_TRANSFORM_PARACHUTE = 40,
			MARKER_TRANSFORM_THRUSTER = 41,
			MARKER_WARP = 42,
			MARKER_BOXES = 43,
			MARKER_PIT_LANE = 44
		};

		virtual ~IMarker() = default;

		virtual uint32_t GetID() const = 0;

#ifdef ALT_CLIENT_API
		virtual bool IsRemote() const = 0;
		virtual uint32_t GetRemoteID() const = 0;
#endif

		virtual bool IsGlobal() const = 0;
		virtual IPlayer* GetTarget() const = 0;

		virtual alt::RGBA GetColor() const = 0;
		virtual void SetColor(alt::RGBA color) = 0;

		virtual bool GetVisible() const = 0;
		virtual void SetVisible(bool visible) = 0;

		virtual MarkerType GetMarkerType() const = 0;
		virtual void SetMarkerType(MarkerType type) = 0;

		virtual Position GetScale() const = 0;
		virtual void SetScale(Position scale) = 0;

		virtual Rotation GetRotation() const = 0;
		virtual void SetRotation(Rotation _rot) = 0;

		virtual Position GetDirection() const = 0;
		virtual void SetDirection(Position dir) = 0;
	};
} // namespace alt
