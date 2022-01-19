#pragma once

#include <iostream>
#include <cstdint>
#include "./StringView.h"
#include "../CRefCountable.h"

namespace alt
{
	class ConnectionInfo : public CRefCountable
	{
	public:
		ConnectionInfo(Ref<IPlayer> _player, std::string _name, uint64_t _socialId, uint64_t _hwidHash, uint64_t _hwidExHash,
			std::string _authToken, bool _isDebug, std::string _branch, uint32_t _build, std::string _cdnUrl, uint64_t _passwordHash) :
			name(_name), socialId(_socialId), hwidHash(_hwidHash), hwidExHash(_hwidExHash), authToken(_authToken), isDebug(_isDebug),
			branch(_branch), build(_build), cdnUrl(_cdnUrl), passwordHash(_passwordHash), player(_player) 
		{
		}


		Ref<IPlayer> GetPlayer() const
		{
			return player;
		}

		std::string GetName() const
		{
			return name;
		}

		uint64_t GetSocialId() const
		{
			return socialId;
		}

		uint64_t GetHwIdHash() const
		{
			return hwidHash;
		}

		uint64_t GetHwIdExHash() const
		{
			return hwidExHash;
		}

		std::string GetAuthToken() const
		{
			return authToken;
		}

		bool GetIsDebug() const
		{
			return isDebug;
		}

		std::string GetBranch() const
		{
			return branch;
		}

		uint32_t GetBuild() const
		{
			return build;
		}

		std::string GetCdnUrl() const
		{
			return cdnUrl;
		}

		uint64_t GetPasswordHash() const
		{
			return passwordHash;
		}

		const std::type_info& GetTypeInfo() const override { return typeid(this); }

		friend std::ostream& operator<<(std::ostream& stream, const ConnectionInfo& connectionInfo)
		{
			stream << "ConnectionInfo{}";
			return stream;
		}

	private:
		Ref<IPlayer> player;
		std::string name;
		uint64_t socialId;
		uint64_t hwidHash;
		uint64_t hwidExHash;
		std::string authToken;
		bool isDebug;
		std::string branch;
		uint32_t build;
		std::string cdnUrl;
		uint64_t passwordHash;
	};
}