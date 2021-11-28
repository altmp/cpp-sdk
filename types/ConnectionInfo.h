#pragma once

#include <iostream>
#include <cstdint>
#include "./StringView.h"

namespace alt
{
	struct ConnectionInfo
	{
		StringView name = 0;
		uint64_t socialId = 0;
		uint64_t hwidHash = 0;
		uint64_t hwidExHash = 0;
		StringView authToken = 0;
		bool isDebug = 0;
		StringView branch = 0;
		uint32_t build = 0;
		StringView cdnUrl = 0;
		uint64_t passwordHash = 0;

		ConnectionInfo() = default;

		ConnectionInfo(String _name, uint64_t _socialId, uint64_t _hwidHash, uint64_t _hwidExHash,
			String _authToken, bool _isDebug, StringView _branch, uint32_t _build, StringView _cdnUrl, uint64_t _passwordHash) :
			name(_name), socialId(_socialId), hwidHash(_hwidHash), hwidExHash(_hwidExHash) { }

		friend std::ostream& operator<<(std::ostream& stream, const ConnectionInfo& connectionInfo)
		{
			stream << "ConnectionInfo{}";
			return stream;
		}
	};
}