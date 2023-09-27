# Refs

> [!WARNING]
> This part of SDK is not used anymore, but Leon spent too much time writing it, so it's still here.

This article will explain what Refs are and how to use them.

## What are Refs

If you are familiar with modern C++ you probably know what **smart pointers** are, and how to use them.
A `Ref` is similiar to the popular `shared_ptr` container from the standard library. 
It stores a heap-allocated object and controls its lifetime and memory by using refcounting. 
If there are no more instances of the `Ref` exist, the stored object will be freed automatically. 

They are however different, as the `shared_ptr` stores the refcount on the `shared_ptr` container, while the
`Ref` in the SDK stores the refcount on the stored object inside the `Ref`. That is also why any object stored in a `Ref` must
inherit from [`alt::CRefCountable`](https://github.com/altmp/cpp-sdk/blob/master/CRefCountable.h).

## How to use Refs

To create a Ref you can simply use the `Ref` class. Once you create a ref with the pointer of your object you want to store,
make sure to NOT delete that pointer manually, the `Ref` is now responsible for managing the memory and lifetime of that object.

The `Ref` class uses a template argument to specify which type of object is stored inside of it.

The object stored inside the `Ref` can be accessed by using the `Get()` method. In most cases this is not necessary though,
as the `->` operator of the `Ref` is overloaded to access methods and properties of the object inside it without having to call `Get()`.

A simple example of how to use a `Ref`:
```c++
// To store our class in a Ref,
// we need to inherit from 'alt::CRefCountable'
class MyClass : public alt::CRefCountable
{
    int id;
public:
    MyClass(int _id) : id(_id) {}

    int GetID() { return id; }
};

// We create a ref storing the instance of our class
// The ref now takes care of managing the object's memory
// Once the ref and each of its copies has been destroyed,
// the memory for the object stored will be freed.
alt::Ref<MyClass> myRef(new MyClass(1));
```
```c++
// We receive a new copy of the ref here,
// so the ref count will be increased by 1,
// and the object can not be freed,
// as long as this copy exists.
int GetRefId(alt::Ref<MyClass> ref)
{
    // We use the overloaded '->' operator, 
    // to access the method on the stored object directly,
    // without needing to call 'Get()'
    return ref->GetID();
}

// We call this function that takes our ref and copies it,
// and then calls a method on it
int id = GetRefId(myRef);
```

The SDK uses `Refs` in many places where instances of objects are passed, usually you do not need to worry about the refcounting of the `Ref` etc.
You can safely store a copy of the `Ref` in your own `std::vector` or similiar, without having to think about the lifetime of the object.

> To see all available methods on `Refs`, refer to the [header file in the SDK](https://github.com/altmp/cpp-sdk/blob/master/Ref.h).
