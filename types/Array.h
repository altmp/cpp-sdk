#pragma once

#include <cstring>

#include "Types.h"

namespace alt
{
	template<class T>
	class Array
	{
	public:
		Array() = default;

		template<class It>
		Array(It begin, It end)
		{
			Size _size = std::distance(begin, end);

			Realloc(_size);

			auto from = begin;
			auto to = data;

			for (; from != end; ++from, ++to)
				*to = *from;

			size = _size;
		}

		Array(const T* _data, Size _size) :
			Array(_data, _data + _size)
		{

		}

		Array(Size _size, const T& fill = T())
		{
			Realloc(_size);

			for (Size i = 0; i < _size; ++i)
				data[i] = fill;

			size = _size;
		}

		Array(const Array& that) :
			Array(that.data, that.size)
		{

		}

		Array(Array&& that)
		{
			std::swap(data, that.data);
			std::swap(size, that.size);
			std::swap(capacity, that.capacity);
		}

		~Array() { delete[] data; }

		Array& operator=(const Array& that)
		{
			Realloc(that.size);

			for (Size i = 0; i < that.size; ++i)
				data[i] = that.data[i];

			size = that.size;
			return *this;
		}

		Array& operator=(Array&& that)
		{
			data = that.data;
			size = that.size;
			capacity = that.capacity;

			that.data = nullptr;
			that.size = 0;
			that.capacity = 0;

			return *this;
		}

		void Push(const T& el)
		{
			Realloc(size + 1);
			data[size] = el;
			++size;
		}

		Size GetSize() const { return size; }
		Size GetCapacity() const { return capacity; }

		T& operator[](Size key) { return data[key]; }
		const T& operator[](Size key) const { return data[key]; }

		T* begin() { return data; }
		const T* begin() const { return data; }
		T* end() { return data + size; }
		const T* end() const { return data + size; }

	private:
		T* data = nullptr;
		Size size = 0;
		Size capacity = 0;

		void Realloc(Size least)
		{
			if (capacity >= least)
				return;

			if (capacity == 0)
				capacity = 1;

			while (capacity < least)
				capacity <<= 1;

			T* newData = new T[capacity];

			for (Size i = 0; i < size; ++i)
				newData[i] = data[i];

			delete[] data;
			data = newData;
		}
	};
}
