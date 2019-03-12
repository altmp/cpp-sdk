#pragma once

#include <cstdint>
#include <cstring>

#include <string>
#include <iostream>

#include "Types.h"
#include "String.h"

namespace alt
{
	class StringView
	{
		const char* data;
		Size size;

	public:
		StringView(const char* _data, Size _size) :
			data(_data),
			size(_size)
		{

		}

		StringView() :
			StringView(nullptr, 0)
		{

		}

		StringView(const char* _str) :
			StringView(_str, strlen(_str))
		{

		}

		template<Size Size>
		StringView(const char(&_data)[Size]) :
			StringView(_data, Size - 1)
		{

		}

		StringView(const std::string& _str) :
			StringView(_str.data(), _str.size())
		{

		}

		StringView(const String& _str) :
			StringView(_str.GetData(), _str.GetSize())
		{

		}

		StringView(std::string_view _str) :
			StringView(_str.data(), _str.size())
		{

		}

		bool IsEmpty() const { return size == 0; }

		const char* GetData() const { return data; }
		Size GetSize() const { return size; }

		char operator[](Size key) const { return data[key]; }

		bool operator==(StringView that) const { return size == that.size && memcmp(data, that.data, size) == 0; }
		bool operator!=(StringView that) const { return !(*this == that); }

		std::string ToString() const { return std::string(data, size); }
		operator String() const { return String{ data, size }; }
		const char* CStr() const { return data; }

		friend std::ostream& operator<<(std::ostream& stream, StringView view)
		{
			return stream << view.CStr();
		}
	};
}