#pragma once

#include <cstdint>
#include <atomic>

namespace alt
{
	class CRefCountable
	{
	public:
		virtual uint64_t GetRefCount() const { return refCount; }

		virtual void AddRef() const { ++refCount; }

		virtual void RemoveRef() const
		{
			if (--refCount == 0)
				delete this;
		}

	protected:
		virtual ~CRefCountable() = default;

	private:
		mutable std::atomic_uint64_t refCount{ 0 };
	};
}
