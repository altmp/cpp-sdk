#pragma once

#include <string>
#include <memory>

namespace alt
{
	class IConnectionInfo : public std::enable_shared_from_this<IConnectionInfo>
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

		virtual void Accept(bool sendNames) = 0;
		virtual void Decline(const std::string& reason) = 0;
		virtual bool IsAccepted() const = 0;

        template <typename Derived>
        std::shared_ptr<Derived> SharedAs()
        {
			try
			{
				Derived* derived = dynamic_cast<Derived*>(this);
				if (!derived)
				{
					static std::shared_ptr<Derived> empty;
					return empty;
				}
				std::shared_ptr<IConnectionInfo> shared = derived->shared_from_this();
				return std::dynamic_pointer_cast<Derived>(shared);
			}
			catch (std::bad_weak_ptr&)
			{
				static std::shared_ptr<Derived> empty;
				return empty;
			}
        }

        template <typename Derived>
        Derived* As()
        {
            return dynamic_cast<Derived*>(this);
        }
	};
}