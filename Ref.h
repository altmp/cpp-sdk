#pragma once

#include <cstdint>
#include <atomic>
#include <unordered_map>

#include "CRefCountable.h"

namespace alt
{
	template<class MyStore>
	class RefBase : public MyStore
	{
	public:
		using ValueType = typename MyStore::ValueType;

		RefBase() = default;
		RefBase(ValueType* _ptr) { this->Assign(_ptr); }

		RefBase(const RefBase& other) :
			RefBase(const_cast<ValueType*>(other.Get())) { }

		RefBase(RefBase&& other) noexcept
		{
			this->Move(std::move(other));
		}

		template<class UStore>
		RefBase(const RefBase<UStore>& other) :
			RefBase(const_cast<typename UStore::ValueType*>(other.Get())) { }

		template<class UStore>
		RefBase(RefBase<UStore>&& other) noexcept
		{
			this->template Move<typename UStore::ValueType>(std::move(other));
		}

		RefBase(std::nullptr_t) :
			RefBase(static_cast<ValueType*>(nullptr)) { }

		~RefBase()
		{
			this->Free();
		}

		RefBase& operator=(const RefBase& that)
		{
			if (this->Get() != that.Get())
			{
				this->Free();
				this->Assign(const_cast<ValueType*>(that.Get()));
			}

			return *this;
		}

		bool IsEmpty() const { return this->Get() == nullptr; }
		operator bool() const { return !IsEmpty(); }

		ValueType* operator->() const { return this->Get(); }
		ValueType& operator*() const { return *this->Get(); }

		template<class UStore>
		bool operator==(RefBase<UStore> rhs) const { return this->Get() == rhs.Get(); }

		template<class U>
		bool operator==(U* rhs) const { return this->Get() == rhs; }

		template<class UStore>
		bool operator!=(RefBase<UStore> rhs) const { return this->Get() != rhs.Get(); }

		template<class U>
		bool operator!=(U* rhs) const { return this->Get() != rhs; }

		template<class... Args>
		static RefBase New(const Args&... args)
		{
			return RefBase(new ValueType(args...));
		}
	};

	template<class T>
	class RefStore
	{
	public:
		using ValueType = T;

		template<class U>
		using OtherType = RefStore<U>;

		void Assign(T* _ptr)
		{
			if (_ptr) _ptr->AddRef();
			ptr = _ptr;
		}

		void Free()
		{
			if (ptr)
			{
				ptr->RemoveRef();
				ptr = nullptr;
			}
		}

		template<class U>
		void Move(RefStore<U>&& other)
		{
			Free();

			ptr = other.ptr;
			other.ptr = nullptr;
		}

		inline T* Get() const { return ptr; }

		template<class U>
		std::enable_if_t<!std::is_const_v<T>, RefBase<RefStore<U>>>
		As() const { return RefBase<RefStore<U>>(dynamic_cast<U*>(Get())); }

		template<class U>
		std::enable_if_t<std::is_const_v<T>, RefBase<RefStore<const U>>>
		As() const { return RefBase<RefStore<const U>>(dynamic_cast<const U*>(Get())); }

	private:
		template<class U> friend class RefStore;

		T* ptr = nullptr;
	};

	template<class T> using Ref = RefBase<RefStore<T>>;
	template<class T> using ConstRef = RefBase<RefStore<const T>>;

	template<class T>
	class AtomicRefStore
	{
	public:
		using ValueType = T;

		void Assign(T* _ptr)
		{
			if (_ptr) _ptr->AddRef();
			ptr = _ptr;
		}

		void Free()
		{
			if (ptr)
			{
				T* oldPtr = ptr.exchange(nullptr);
				if (oldPtr) oldPtr->RemoveRef();
			}
		}

		template<class U>
		void Move(AtomicRefStore<U>&& other)
		{
			Free();

			ptr = other.ptr.exchange(nullptr);
		}

		inline T* Get() const { return ptr; }

		Ref<T> Load() const { return Ref<T>(ptr); }

	private:
		template<class U> friend class AtomicRefStore;

		std::atomic<T*> ptr = nullptr;
	};

	template<class T> using AtomicRef = RefBase<AtomicRefStore<T>>;
	template<class T> using ConstAtomicRef = RefBase<AtomicRefStore<const T>>;
}

namespace std
{
	template<class T>
	struct hash<alt::RefBase<T>>
	{
		hash<typename T::ValueType*> _hash;
		hash() = default;

		size_t operator()(const alt::RefBase<T>& ref) const
		{
			return _hash(ref.Get());
		}
	};
}
