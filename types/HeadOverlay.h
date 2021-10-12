#pragma once

#include <iostream>
#include <cstdint>

namespace alt
{
	struct HeadOverlay
	{
		uint8_t index = 0;
		float opacity = 0;
		uint8_t colorType;
		uint8_t colorIndex = 0;
		uint8_t secondColorIndex = 0;

		HeadOverlay() = default;

		HeadOverlay(uint8_t _index, float _opacity, uint8_t _colorType, uint8_t _colorIndex, uint8_t _secondColorIndex) :
			index(_index), opacity(_opacity), colorType(_colorType), colorIndex(_colorIndex), secondColorIndex(_secondColorIndex){ }

		friend std::ostream &operator<<(std::ostream &stream, const HeadOverlay &headOverlay)
		{
			stream << "HeadOverlay{ "<< headOverlay.index << headOverlay.opacity << ", " << headOverlay.colorType << ", "
				   << headOverlay.colorIndex << headOverlay.secondColorIndex << ", " << " }";
			return stream;
		}
	};
}
