#pragma once

#include "CEvent.h"
#include "../deps/alt-math/alt-math.h"

namespace alt
{
	class CWindowResolutionChangeEvent : public CEvent
	{
	public:
		CWindowResolutionChangeEvent(Vector2i _oldResolution, Vector2i _newResolution) :
			CEvent(Type::WINDOW_RESOLUTION_CHANGE),
			oldResolution(_oldResolution),
			newResolution(_newResolution)
		{
		}

		Vector2i GetOldResolution() const { return oldResolution; }
		Vector2i GetNewResolution() const { return newResolution; }

	private:
		Vector2i oldResolution;
		Vector2i newResolution;
	};
}

