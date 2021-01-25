#pragma once

#include <iostream>
#include <cstdint>

namespace alt
{
	struct Prop
	{
		uint16_t drawableId = 0;
		uint8_t textureId = 0;

		Prop() = default;

		Prop(uint16_t _drawableId, uint8_t _textureId) :
				drawableId(_drawableId), textureId(_textureId) { }

		friend std::ostream &operator<<(std::ostream &stream, const Prop &prop)
		{
			stream << "Prop{ " << (int)prop.drawableId << ", " << (int)prop.textureId << " }";
			return stream;
		}
	};
}
