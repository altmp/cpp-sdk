#pragma once

#include <string>

#include "../objects/IBaseObject.h"

namespace alt
{
	class IConnectionInfo : public virtual IBaseObject
	{
	protected:
		virtual ~IConnectionInfo() = default;

	public:
		virtual uint32_t GetID() const = 0;
		virtual std::string GetName() const = 0;
		virtual uint64_t GetSocialId() const = 0;
		virtual std::string GetSocialName() const = 0;
		virtual uint64_t GetHwIdHash() const = 0;
		virtual uint64_t GetHwIdExHash() const = 0;
		virtual std::string GetAuthToken() const = 0;
		virtual bool GetIsDebug() const = 0;
		virtual std::string GetBranch() const = 0;
		virtual uint32_t GetBuild() const = 0;
		virtual std::string GetCdnUrl() const = 0;
		virtual uint64_t GetPasswordHash() const = 0;
		virtual std::string GetIp() const = 0;
		virtual int64_t GetDiscordUserID() const = 0;
		virtual std::string GetCloudAuthHash() const = 0;

		virtual void Accept(bool sendNames) = 0;
		virtual void Decline(const std::string& reason) = 0;
		virtual bool IsAccepted() const = 0;
	};
}