#pragma once

#include "./String.h"

namespace alt
{
	struct DiscordOAuth2Token
	{
		String token;
		int64_t expires;
		String scopes;
	};

	using DiscordOAuth2Callback = void(*)(void* userData, bool success, DiscordOAuth2Token token);
}
