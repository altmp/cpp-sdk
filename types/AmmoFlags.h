#pragma once

namespace alt
{
	struct AmmoFlags
	{
		bool infiniteAmmo : 1;
		bool addSmokeOnExplosion : 1;
		bool fuse : 1;
		bool fixedAfterExplosion : 1;
	};
} // namespace alt
