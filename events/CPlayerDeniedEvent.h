#pragma once

#include "CEvent.h"

namespace alt
{
	class CPlayerDeniedEvent : public CEvent
	{
	public:
		enum Reason: uint8_t
		{
			WRONG_VERSION,
			WRONG_BRANCH,
			DEBUG_NOT_ALLOWED,
			WRONG_PASSWORD,
			WRONG_CDN_URL
		};
		
		CPlayerDeniedEvent(Reason _reason, const std::string& _name, const std::string& _ip, uint64_t _passwordHash, bool _isDebug, const std::string& _branch, uint32_t _majorVersion, const std::string& _cdnUrl, int64_t _discordId) :
			CEvent(Type::PLAYER_DENIED), reason(_reason), name(_name), ip(_ip), passwordHash(_passwordHash), isDebug(_isDebug), branch(_branch), majorVersion(_majorVersion), cdnUrl(_cdnUrl), discordId(_discordId)
		{
		}

		Reason GetReason() const { return reason; }
		const std::string& GetName() const { return name; }
		const std::string& GetIp() const { return ip; }
		uint64_t GetPasswordHash() const { return passwordHash; }
		bool IsDebug() const { return isDebug; }
		const std::string& GetBranch() const { return branch; }
		uint32_t GetMajorVersion() const { return majorVersion; }
		const std::string& GetCdnUrl() const { return cdnUrl; }
		int64_t GetDiscordId() const { return discordId; }

	private:
		Reason reason;
		std::string name;
		std::string ip;
		uint64_t passwordHash;
		bool isDebug;
		std::string branch;
		uint32_t majorVersion;
		std::string cdnUrl;
		int64_t discordId;
	};
}
