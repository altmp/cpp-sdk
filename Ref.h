#pragma once

#include <cstdint>
#include <atomic>

namespace alt
{
	class CRefCountable
	{
	public:
		virtual void AddRef() { ++refCount; }

		virtual void RemoveRef()
		{
			if (--refCount == 0)
				delete this;
		}

	protected:
		virtual ~CRefCountable() = default;

	private:
		std::atomic_uint64_t refCount = 0;
	};

	template<class T>
	class ConstRef
	{
	public:
		ConstRef() = default;

		ConstRef(T* _ptr) { Alloc(_ptr); }

		ConstRef(const ConstRef& other) :
			ConstRef(const_cast<T*>(other.ptr)) { }

		ConstRef(ConstRef&& other) noexcept
		{
			ptr = other.ptr;
			other.ptr = nullptr;
		}

		template<class U>
		ConstRef(const ConstRef<U>& other) :
			ConstRef(const_cast<U*>(other.ptr)) { }

		template<class U>
		ConstRef(ConstRef<U>&& other) noexcept
		{
			ptr = other.ptr;
			other.ptr = nullptr;
		}

		ConstRef(std::nullptr_t) :
			ConstRef(static_cast<T*>(nullptr)) { }

		~ConstRef() { Free(); }

		ConstRef& operator=(const ConstRef& that)
		{
			if (Get() != that.ptr)
			{
				Free();
				Alloc(const_cast<T*>(that.ptr));
			}

			return *this;
		}

		bool IsEmpty() const { return Get() == nullptr; }
		operator bool() const { return !IsEmpty(); }

		void Free()
		{
			if (ptr) ptr->RemoveRef();
			ptr = nullptr;
		}

		const T* Get() const { return ptr; }
		const T* operator->() const { return ptr; }
		const T& operator*() const { return *ptr; }

		template<class U>
		bool operator==(ConstRef<U> rhs) const { return Get() == rhs.Get(); }

		template<class U>
		bool operator==(U* rhs) const { return Get() == rhs; }

		template<class U>
		bool operator!=(ConstRef<U> rhs) const { return Get() != rhs.Get(); }

		template<class U>
		bool operator!=(U* rhs) const { return Get() != rhs; }

		template<class U>
		ConstRef<U> As() const { return ConstRef<U>(dynamic_cast<U*>(ptr)); }

	protected:
		template<class U> friend class ConstRef;

		T* ptr = nullptr;

		void Alloc(T* _ptr)
		{
			if (_ptr) _ptr->AddRef();
			ptr = _ptr;
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
		static Ref New(Args... args) { return Ref{ new T(args...) }; }

	private:
		template<class U> friend class Ref;
	};

	template<class T>
	class ConstAtomicRef
	{
	public:
		ConstAtomicRef() = default;

		ConstAtomicRef(T* _ptr) { Alloc(_ptr); }

		ConstAtomicRef(const ConstRef<T>& other) :
			ConstAtomicRef(const_cast<T*>(other.Get())) { }

		ConstAtomicRef(ConstRef<T>&& other)
		{
			ptr = other.ptr.exchange(nullptr);
		}

		template<class U>
		ConstAtomicRef(const ConstRef<U>& other) :
			ConstAtomicRef(const_cast<U*>(other.Get())) { }

		template<class U>
		ConstAtomicRef(ConstRef<U>&& other)
		{
			ptr = other.ptr.exchange(nullptr);
		}

		ConstAtomicRef(std::nullptr_t) :
			ConstAtomicRef(static_cast<T*>(nullptr)) { }

		~ConstAtomicRef() { Free(); }

		ConstAtomicRef& operator=(const ConstRef<T>& that)
		{
			T* otherPtr = const_cast<T*>(that.Get());

			if (Get() != otherPtr)
			{
				Free();
				Alloc(otherPtr);
			}

			return *this;
		}

		const T* Get() const { return ptr.load(); }
		ConstRef<T> Load() const { return ConstRef<T>{ Get() }; }
		bool IsEmpty() const { return Get() == nullptr; }
		operator bool() const { return !IsEmpty(); }

		void Free()
		{
			T* oldPtr = ptr.exchange(nullptr);
			if (oldPtr) oldPtr->RemoveRef();
		}

	protected:
		template<class U> friend class ConstAtomicRef;

		std::atomic<T*> ptr = nullptr;

		void Alloc(T* _ptr)
		{
			if (_ptr) _ptr->AddRef();
			ptr.store(_ptr);
		}
	};

	template<class T>
	class AtomicRef : public ConstAtomicRef<T>
	{
	public:
		AtomicRef() = default;

		AtomicRef(T* _ptr) : ConstAtomicRef<T>(_ptr) { }

		template<class U>
		AtomicRef(const Ref<U>& other) :
			ConstAtomicRef<T>(other) { }

		template<class U>
		AtomicRef(Ref<U>&& other) :
			ConstAtomicRef<T>(std::move(other)) { }

		AtomicRef(std::nullptr_t) :
			ConstAtomicRef<T>(nullptr) { }

		T* Get() const { return const_cast<T*>(ConstAtomicRef<T>::Get()); }
		Ref<T> Load() const { return Ref<T>{ Get() }; }

		AtomicRef& operator=(const Ref<T>& that)
		{
			ConstAtomicRef<T>::operator=(that);
			return *this;
		}

	private:
		template<class U> friend class AtomicRef;
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
