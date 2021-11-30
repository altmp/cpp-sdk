#pragma once

#include <iostream>
#include <cstdint>
#include "./StringView.h"

namespace alt
{
	struct ConnectionInfo
	{
		std::string name;
		uint64_t socialId = 0;
		uint64_t hwidHash = 0;
		uint64_t hwidExHash = 0;
		std::string authToken;
		bool isDebug = 0;
		std::string branch;
		uint32_t build = 0;
		std::string cdnUrl;
		uint64_t passwordHash = 0;

		ConnectionInfo() = default;

		ConnectionInfo(std::string _name, uint64_t _socialId, uint64_t _hwidHash, uint64_t _hwidExHash,
			std::string _authToken, bool _isDebug, std::string _branch, uint32_t _build, std::string _cdnUrl, uint64_t _passwordHash) :
			name(_name), socialId(_socialId), hwidHash(_hwidHash), hwidExHash(_hwidExHash), authToken(_authToken), isDebug(_isDebug),
		branch(_branch), build(_build), cdnUrl(_cdnUrl), passwordHash(_passwordHash) { }

		friend std::ostream& operator<<(std::ostream& stream, const ConnectionInfo& connectionInfo)
		{
			stream << "ConnectionInfo{}";
			return stream;
		}
	};
}