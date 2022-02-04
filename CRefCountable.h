#pragma once

#include <cstdint>
#include <atomic>
#include <mutex>
#include <unordered_set>

namespace alt
{
	class IWeakRef
	{
	public:
		virtual void OnDestroy() = 0;
	};

	class CRefCountable
	{
	public:
		virtual uint64_t GetRefCount() const { return refCount; }

		virtual void AddRef() const { ++refCount; }

		virtual bool AddRefIfExists() const 
		{
			for (;;) 
			{
				uint_fast64_t cur = refCount;
				if (cur == 0) 
				{
					return false;
				}
				if (refCount.compare_exchange_strong(cur, cur + 1))
				{
					break;
				}
			}
			return true;
		}

		virtual void RemoveRef() const
		{
			if (--refCount == 0)
			{
				{
					std::unique_lock lock{ weakRefsMutex };
					for (auto ref : weakRefs)
						ref->OnDestroy();
				}

				delete this;
			}
		}

		virtual void AddWeakRef(IWeakRef* ref) const
		{
			std::unique_lock lock{ weakRefsMutex };
			weakRefs.insert(ref);
		}

		virtual void RemoveWeakRef(IWeakRef* ref) const
		{
			std::unique_lock lock{ weakRefsMutex };
			weakRefs.erase(ref);
		}

		virtual const std::type_info& GetTypeInfo() const = 0;

	protected:
		virtual ~CRefCountable() = default;

	private:
		mutable std::atomic_uint64_t refCount{ 0 };
		mutable std::mutex weakRefsMutex;
		mutable std::unordered_set<IWeakRef*> weakRefs;
	};
}
