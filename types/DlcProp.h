#pragma once

#include <iostream>
#include <cstdint>

namespace alt
{
	struct DlcProp
	{
		uint32_t dlc = 0;
		uint8_t drawableId = 0;
		uint8_t textureId = 0;

		DlcProp() = default;

		DlcProp(uint32_t _dlc, uint8_t _drawableId, uint8_t _textureId) :
				dlc(_dlc), drawableId(_drawableId), textureId(_textureId) { }

		friend std::ostream &operator<<(std::ostream &stream, const DlcProp &prop)
		{
			stream << "DlcProp{ "<< (int)prop.dlc << (int)prop.drawableId << ", " << (int)prop.textureId << " }";
			return stream;
		}
	};
}
