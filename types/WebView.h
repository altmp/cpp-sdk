#pragma once

#include <optional>
#include <string>

namespace alt
{
	struct WebViewCookie
	{
		std::string url;
		std::string name;
		std::string value;

		bool httpOnly;
		bool secure;
		std::optional<long long> expires;
		std::optional<std::string> domain;
		std::optional<std::string> path;
		std::optional<std::string> sameSite;
		std::optional<std::string> priority;
	};

	using WebViewHeaders = std::unordered_map<std::string, std::string>;
}
