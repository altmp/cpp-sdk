#pragma once

namespace alt
{
	template <size_t _count>
	class bitset
	{
	private:
		uint8_t _bitset[(_count >> 3) + 1] = { 0 };

	public:
		void set(size_t pos, bool state)
		{
			if (state)
				_bitset[pos >> 3] |= (1UL << (pos & 7));
			else
				_bitset[pos >> 3] &= ~(1UL << (pos & 7));
		}

		bool test(size_t pos) const
		{
			return (_bitset[pos >> 3] >> (pos & 7)) & 1UL;
		}
	};
}