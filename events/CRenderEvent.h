#pragma once

#include "CEvent.h"

namespace alt
{
	class CRenderEvent : public CEvent
	{
	public:
		CRenderEvent() :
			CEvent(Type::RENDER)
		{}

	private:
	};
};
