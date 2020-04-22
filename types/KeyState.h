#pragma once

namespace alt
{
  struct KeyState
	{
		KeyState(bool down, bool toggled)
			: down(down), toggled(toggled)
		{}

		bool IsDown() { return down; }
		bool IsToggled() { return toggled; }

	private:
		bool down, toggled;
	};
} // namespace alt
