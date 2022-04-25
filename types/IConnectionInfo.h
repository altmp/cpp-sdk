#pragma once

#include "../CRefCountable.h"

#include <string>

namespace alt
{
	class IConnectionInfo : public virtual CRefCountable
	{
	protected:
		virtual ~IConnectionInfo() = default;

	public:
		virtual std::string GetName() const = 0;
		virtual uint64_t GetSocialId() const = 0;
		virtual uint64_t GetHwIdHash() const = 0;
		virtual uint64_t GetHwIdExHash() const = 0;
		virtual std::string GetAuthToken() const = 0;
		virtual bool GetIsDebug() const = 0;
		virtual std::string GetBranch() const = 0;
		virtual uint32_t GetBuild() const = 0;
		virtual std::string GetCdnUrl() const = 0;
		virtual uint64_t GetPasswordHash() const = 0;
		virtual std::string GetIp() const = 0;
		virtual std::string GetDiscordUserID() const = 0;

		virtual void Accept() = 0;
		virtual void Decline(const std::string& reason) = 0;
		virtual bool IsAccepted() const = 0;

		const std::type_info& GetTypeInfo() const override { return typeid(this); }
	};
}