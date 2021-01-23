#pragma once

#include <iostream>
#include <cstdint>

namespace alt
{
	struct DlcCloth
	{
		uint32_t dlc = 0;
		uint16_t drawableId = 0;
		uint8_t textureId = 0;
		uint8_t paletteId = 0;

		DlcCloth() = default;

		DlcCloth(uint32_t _dlc, uint16_t _drawableId, uint8_t _textureId, uint8_t _paletteId) :
				dlc(_dlc), drawableId(_drawableId), textureId(_textureId), paletteId(_paletteId) { }

		friend std::ostream &operator<<(std::ostream &stream, const DlcCloth &cloth)
		{
			stream << "DlcCloth{ "<< (int)cloth.dlc << (int) cloth.drawableId << ", " << (int) cloth.textureId << ", "
				   << (int) cloth.paletteId << " }";
			return stream;
		}
	};
}
