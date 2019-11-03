#pragma once

#include <cstdint>

// Checks types on conversion
#define ALT_REF_TYPE_CHECK(T, U) if (false) { *(static_cast<T* volatile*>(0)) = static_cast<U*>(0); }

namespace alt
{
	class CRefCountable
	{
	protected:
		virtual ~CRefCountable() = default;

	private:
		template<class T> friend class ConstRef;

		uint64_t refCount = 0;

		virtual uint64_t AddRef() { return ++refCount; }
		virtual uint64_t RemoveRef() { return --refCount; }
	};

	template<class T>
	class ConstRef
	{
	public:
		ConstRef() = default;

		ConstRef(const ConstRef& other) :
			ConstRef(const_cast<T*>(other.ptr)) { }

		ConstRef(ConstRef&& other)
		{
			ptr = other.ptr;
			other.ptr = nullptr;
		}

		template<class U>
		ConstRef(const ConstRef<U>& other) :
			ConstRef(const_cast<U*>(other.ptr)) { }

		template<class U>
		ConstRef(ConstRef<U>&& other)
		{
			ptr = other.ptr;
			other.ptr = nullptr;
		}

		~ConstRef() { Free(); }

		ConstRef& operator=(const ConstRef& that)
		{
			if (ptr != that.ptr)
			{
				Free();
				Alloc(const_cast<T*>(that.ptr));
			}

			return *this;
		}

		const T* Get() { return ptr; }
		const T* operator->() { return ptr; }

		template<class U>
		ConstRef<U> As() { return ConstRef<U>(dynamic_cast<U*>(ptr)); }

		template<class... Args>
		static ConstRef New(Args... args)
		{
			return ConstRef(new T(args...));
		}

	protected:
		template<class U> friend class ConstRef;

		T* ptr = nullptr;

		ConstRef(T* _ptr) { Alloc(_ptr); }

		void Free()
		{
			if (ptr && ptr->RemoveRef() == 0)
				delete ptr;

			ptr = nullptr;
		}

		void Alloc(T* _ptr)
		{
			ptr = _ptr;
			if (ptr) ptr->AddRef();
		}
	};

	template<class T>
	class Ref : public ConstRef<T>
	{
	public:
		Ref() = default;

		template<class U>
		Ref(const Ref<U>& other) :
			ConstRef<T>(other) { }

		template<class U>
		Ref(Ref<U>&& other) :
			ConstRef<T>(std::move(other)) { }

		T* Get() { return ptr; }
		T* operator->() { return ptr; }

		Ref& operator=(const Ref& that)
		{
			ConstRef<T>::operator=(that);
			return *this;
		}

		template<class U>
		Ref<U> As() { return Ref<U>(dynamic_cast<U*>(ptr)); }

		template<class... Args>
		static Ref New(Args... args) { return Ref(new T(args...)); }

	private:
		template<class U> friend class Ref;

		Ref(T* _ptr) : ConstRef<T>(_ptr) { }
	};
}
