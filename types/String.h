#pragma once

#include <cstdint>
#include <cstring>

#include <string>
#include <iostream>

#include "Types.h"

namespace alt
{
	class String
	{
	public:
		String(Size _size, char fill = '\0') :
			size(_size)
		{
			data = new char[size + 1];
			memset(data, fill, size);
			data[size] = '\0';
		}

		template<class Iter>
		String(Iter first, Iter last)
		{
			size = std::distance(first, last);

			data = new char[size + 1];
			
			for (Size i = 0; first != last; ++i)
				data[i] = *(first++);
				
			data[size] = '\0';
		}

		String(const char* _data, Size size) :
			String(_data, _data + size)
		{

		}

		String() :
			String(nullptr, 0)
		{

		}

		String(const char* _str) :
			String(_str, strlen(_str))
		{

		}

		template<Size Size>
		String(const char(&_data)[Size]) :
			String(_data, Size - 1)
		{

		}

		String(const std::string& _str) :
			String(_str.data(), _str.size())
		{

		}

		String(const String& that) :
			String(that.data, that.size)
		{

		}

		String(String&& that) :
			String()
		{
			String tmp;
			tmp.Swap(that);
			Swap(tmp);
		}

		~String() { delete[] data; }

		char& operator[](Size key) { return data[key]; }
		char operator[](Size key) const { return data[key]; }

		String& operator=(const String& that)
		{
			String tmp(that);
			Swap(tmp);
			return *this;
		}

		String& operator=(String&& that)
		{
			String tmp(that);
			Swap(tmp);
			return *this;
		}

		bool IsEmpty() const { return size == 0; }

		const char* GetData() const { return data; }
		char* GetData() { return data; }
		Size GetSize() const { return size; }

		bool operator==(String that) const { return size == that.size && memcmp(data, that.data, size) == 0; }
		bool operator!=(String that) const { return !(*this == that); }

		std::string ToString() const { return std::string(data, size); }
		const char* CStr() const { return data; }

		friend String operator+(const String& lhs, const String& rhs) { return Concat(lhs.CStr(), lhs.GetSize(), rhs.GetData(), rhs.GetSize()); }
		
		friend String operator+(const String& lhs, const char* rhs) { return Concat(lhs.CStr(), lhs.GetSize(), rhs, strlen(rhs)); }
		friend String operator+(const char* lhs, const String& rhs) { return Concat(lhs, strlen(lhs), rhs.GetData(), rhs.GetSize()); }

		friend String operator+(const String& lhs, char rhs) { return Concat(lhs.CStr(), lhs.GetSize(), &rhs, 1); }
		friend String operator+(char lhs, const String& rhs) { return Concat(&lhs, 1, rhs.GetData(), rhs.GetSize()); }

		friend std::ostream& operator<<(std::ostream& stream, String str) { return stream << str.CStr(); }

	private:
		char* data;
		Size size;

		void Swap(String& that)
		{
			std::swap(data, that.data);
			std::swap(size, that.size);
		}

		static String Concat(const char* lData, Size lSize, const char* rData, Size rSize)
		{
			String res(lSize + rSize);

			for (Size i = 0; i < lSize + rSize; ++i)
				res[i] = i < lSize ? lData[i] : rData[i - lSize];

			return res;
		}
	};

	inline String operator"" _s(const char* _str, std::size_t len) { return String{ _str, len }; }
}

namespace std
{
	template<>
	struct hash<alt::String>
	{
		size_t operator()(const alt::String& val) const
		{
			uint32_t hash, i;
			for (hash = i = 0; i < val.GetSize(); ++i)
			{
				hash += val[i];
				hash += (hash << 10);
				hash ^= (hash >> 6);
			}
			hash += (hash << 3);
			hash ^= (hash >> 11);
			hash += (hash << 15);

			return hash;
		}
	};
}
