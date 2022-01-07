#pragma once

#include <iostream>
#include <cstdint>

namespace alt
{
	struct RGBA
	{
		uint8_t r = 0;
		uint8_t g = 0;
		uint8_t b = 0;
		uint8_t a = 0;

		RGBA() = default;

		RGBA(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) :
			r(_r), g(_g), b(_b), a(_a) { }

		friend std::ostream& operator<<(std::ostream& stream, const RGBA& rgba)
		{
			stream << "RGBA{ " << (int)rgba.r << ", " << (int)rgba.g << ", " << (int)rgba.b << ", " << (int)rgba.a << " }";
			return stream;
		}

		//also works as fromBGRA
		RGBA toBGRA()
		{
			return RGBA(b, g, r, a);
		}

		RGBA toARGB()
		{
			return RGBA(a ,r, g, b);
		}

		uint32_t toInt()
		{
			uint32_t RGB = (r << 24);
			RGB = RGB | (g << 16);
			RGB = RGB | (b << 8);
			RGB = RGB | (a);
			return RGB;
		}
	};
}
