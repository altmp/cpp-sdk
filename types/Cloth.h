#pragma once

#include <iostream>
#include <cstdint>

namespace alt
{
	struct Cloth
	{
		uint16_t drawableId = 0;
		uint8_t textureId = 0;
		uint8_t paletteId = 0;

		Cloth() = default;

		Cloth(uint16_t _drawableId, uint8_t _textureId, uint8_t _paletteId) :
				drawableId(_drawableId), textureId(_textureId), paletteId(_paletteId) { }

		friend std::ostream &operator<<(std::ostream &stream, const Cloth &cloth)
		{
			stream << "Cloth{ " << (int) cloth.drawableId << ", " << (int) cloth.textureId << ", "
				   << (int) cloth.paletteId << " }";
			return stream;
		}
	};
}
