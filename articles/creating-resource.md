# Creating your own resource class

This article will explain how to create your own resource class.

The custom resource class will be created for every resource that uses your module type.

## Table of Conents

1. [What is a resource](#what-is-a-resource)
2. [How to create your own resource class](#how-to-create-your-own-resource-class)
3. [Event handling](#event-handling)

## What is a resource

A resource is created for every resource loaded by the alt:V core. Every resource has some data attached to it like
the resource name, the resource path, etc.

The module is in charge of handling the start, stop, event, tick etc. events of every resource.

## How to create your own resource class

To create our own resource class, we need to extend from the `alt::IResource::Impl` interface, and implement its methods.

The interface has the following methods that can be implemented:

| Method               | Description                                                 |
| -------------------- | ----------------------------------------------------------- |
| `MakeClient`         | Reserved for assetpack resources, currently this has no use |
| `Start`              | Called when the resource is started                         |
| `Stop`               | Called when the resource is stopped                         |
| `OnEvent`            | Called every time an event has been fired                   |
| `OnTick`             | Called every tick                                           |
| `OnCreateBaseObject` | Called every time a base object has been created            |
| `OnRemoveBaseObject` | Called every time a base object has been removed            |

> Remember that resources can be started and stopped at runtime, so you should do a proper cleanup in the `Stop` method.
> And because of that you also should not start any resource logic in the constructor, use the `Start` method instead.

Your custom resource class should look something like this:
```c++
class MyResource : public alt::IResource::Impl
{
    // Save the runtime on our resource so we have direct access to it
    MyRuntime* runtime;
    // It is important to save the actual 'alt::Resource' class instance somewhere,
    // it's used for stuff like getting the resource name, resource path etc.
    // We receive this instance when the resource is created and we can pass it from the runtime
    // to our resource and save it here
    alt::IResource* resource;

public:
    // This is the same constructor used as in the previous article about script runtimes
    MyResource(MyRuntime* runtime, alt::IResource* resource) : runtime(runtime), resource(resource) 
    {
        // Don't start any logic in the constructor!
        // Start the resource in the 'Start' method
    }

    // Returns a boolean indicating whether the resource could be successfully loaded
    bool Start()
    {
        // Start some resource specific logic here e.g. instantiating a new context for the script of the resource
        return true;
    }

    // Returns a boolean indicating whether the resource could be successfully stopped
    bool Stop()
    {
        // Stop the resource specific logic e.g. destroying the context of the script of the resource
        return true;
    }

    // Returns a bool whether other resources should receive this event
    bool OnEvent(const alt::CEvent* ev)
    {
        // Proper event handling will be explained in another article
        return true;
    }

    void OnTick()
    {
        // This can be used to clean up stuff in chunks etc. to save performance
        // Also useful for handling timers
    }

    void OnCreateBaseObject(alt::Ref<alt::IBaseObject> object)
    {
        // Here you can e.g. add the base object to some list for validating if a base object still exists
    }

    void OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object)
    {
        // Here you can e.g. remove the base object from some aforementioned list
    }
}
```

> Your actual resource class will be much larger, you should use the class to store any resource specific data.

## Event Handling

Now that your module has a working script runtime and a working resource class, it is now already possible to create 
resources that use your module type.

In [the next article](handling-events.md) you will learn how to properly handle events, received with the `OnEvent` method.
