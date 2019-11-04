#pragma once

#include <cstdint>
#include <atomic>

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

		std::atomic_uint64_t refCount = 0;

		virtual uint64_t AddRef() { return ++refCount; }
		virtual uint64_t RemoveRef() { return --refCount; }
	};

	template<class T>
	class ConstRef
	{
	public:
		ConstRef() = default;

		ConstRef(T* _ptr) { Alloc(_ptr); }

		ConstRef(const ConstRef& other) :
			ConstRef(const_cast<T*>(other.Get())) { }

		ConstRef(ConstRef&& other)
		{
			ptr = other.ptr.exchange(nullptr);
		}

		template<class U>
		ConstRef(const ConstRef<U>& other) :
			ConstRef(const_cast<U*>(other.Get())) { }

		template<class U>
		ConstRef(ConstRef<U>&& other)
		{
			ptr = other.ptr.exchange(nullptr);
		}

		ConstRef(std::nullptr_t) :
			ConstRef(static_cast<T*>(nullptr)) { }

		~ConstRef() { Free(); }

		ConstRef& operator=(const ConstRef& that)
		{
			T* otherPtr = const_cast<T*>(that.Get());

			if (Get() != otherPtr)
			{
				Free();
				Alloc(otherPtr);
			}

			return *this;
		}

		bool IsEmpty() const { return Get() == nullptr; }
		operator bool() const { return !IsEmpty(); }

		void Free()
		{
			T* oldPtr = ptr.exchange(nullptr);

			if (oldPtr && oldPtr->RemoveRef() == 0)
				delete oldPtr;

			oldPtr = nullptr;
		}

		const T* Get() const { return ptr.load(); }
		const T* operator->() const { return Get(); }
		const T& operator*() const { return *Get(); }

		template<class U>
		bool operator==(ConstRef<U> rhs) const { return Get() == rhs.Get(); }

		template<class U>
		bool operator==(U* rhs) const { return Get() == rhs; }

		template<class U>
		bool operator!=(ConstRef<U> rhs) const { return Get() != rhs.Get(); }

		template<class U>
		bool operator!=(U* rhs) const { return Get() != rhs; }

		template<class U>
		ConstRef<U> As() const { return ConstRef<U>(dynamic_cast<U*>(const_cast<T*>(Get()))); }

		template<class... Args>
		static ConstRef New(Args... args)
		{
			return ConstRef(new T(args...));
		}

	protected:
		template<class U> friend class ConstRef;

		std::atomic<T*> ptr = nullptr;

		void Alloc(T* _ptr)
		{
			if (_ptr) _ptr->AddRef();
			ptr.store(_ptr);
		}
	};

	template<class T>
	class Ref : public ConstRef<T>
	{
	public:
		Ref() = default;

		Ref(T * _ptr) : ConstRef<T>(_ptr) { }

		template<class U>
		Ref(const Ref<U>& other) :
			ConstRef<T>(other) { }

		template<class U>
		Ref(Ref<U>&& other) :
			ConstRef<T>(std::move(other)) { }

		Ref(std::nullptr_t) :
			ConstRef<T>(nullptr) { }

		T* Get() const { return const_cast<T*>(ConstRef<T>::Get()); }
		T* operator->() const { return Get(); }

		Ref& operator=(const Ref& that)
		{
			ConstRef<T>::operator=(that);
			return *this;
		}

		template<class U>
		Ref<U> As() const { return Ref<U>(dynamic_cast<U*>(Get())); }

		template<class... Args>
		static Ref New(Args... args) { return Ref(new T(args...)); }

	private:
		template<class U> friend class Ref;
	};
}

namespace std
{
	template<class T>
	struct hash<alt::ConstRef<T>>
	{
		hash<const T*> _hash;
		hash() = default;

		size_t operator()(const alt::ConstRef<T>& ref) const
		{
			return _hash(ref.Get());
		}
	};

	template<class T>
	struct hash<alt::Ref<T>> : public hash<alt::ConstRef<T>> { };
}
