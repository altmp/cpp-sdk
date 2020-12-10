#pragma once

namespace alt
{
	template <size_t _count>
	class bitset
	{
	private:
#pragma pack(push, 1)
		struct _bit
		{
			bool b : 1;
		};
#pragma pack(pop)

		_bit _bitset[_count] = { 0 };

	public:
		void set(size_t pos, bool state)
		{
			_bitset[pos].b = state;
		}

		bool test(size_t pos) const
		{
			return _bitset[pos].b;
		}
	};
}