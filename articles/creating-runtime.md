# Creating your own script runtime class

This article will explain how to create your own script runtime class.

The script runtime class is the main class used by the alt:V core to communicate with your module.

## What is a script runtime

The script runtime is the main class of your module. It implements the behaviour for creating resources for your module
and should manage the script language runtime (e.g. your Python runtime) of your module.

Your own script runtime needs to be instantiated and then registered to be available, as shown in the [last article](first-steps.md).

> The script runtime is a singleton. There will always only be once instance of the class for its whole lifetime.

## How to create your own script runtime

Now lets get to the practical part. First of all you need to define your class that extends the `alt::IScriptRuntime` interface. 
(This class can be found in `IScriptRuntime.h`)

This interface has two methods that need to be implemented by your own class:

| Method         | Description                                           |
| -------------- | ----------------------------------------------------- |
| `CreateImpl`   | Creates a new resource for your module and returns it |
| `DestroyImpl`  | Destroys an existing resource for your module         |

There are also a few other methods that can be overriden, but it is not neccessary to do so:

| Method         | Description                                                                     |
| -------------- | ------------------------------------------------------------------------------- |
| `OnTick`       | Called every tick (on serverside every 50ms)                                    |
| `OnDispose`    | Called when the script runtime gets destroyed (server shutdown)                 |
| `RequiresMain` | Returns whether your module requires `main` to be present in the `resource.cfg` |

You also need to implement a constructor for you class.

Your script runtime class should look something like this:
```c++
// Create our own script runtime class
class MyRuntime : public alt::IScriptRuntime
{
    static MyRuntime* instance = nullptr;

public:
    MyRuntime()
    {
        // Save the instance on the static property
        instance = this;
        // Here we should instantiate the runtime for our scripting language etc.
    }

    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override
    {
        // Create a new heap allocated instance of our resource class and return it
        return new MyResource(this, resource);
    }
    void DestroyImpl(alt::IResource::Impl* impl) override
    {
        // Cast the received resource to our own resource class
        MyResource* resource = dynamic_cast<MyResource*>(impl);
        // Delete the resource
        if(resource != nullptr) delete resource;
    }

    // Create a static method on our class to retrieve the instance of the runtime
    static MyRuntime* GetInstance()
    {
        return instance;
    }
}
```

> Typically, your own class will be much larger, you should use this class to store and handle everything related to the module.

## Creating your own resource

This was it for now regarding the script runtime. Next, you should create your own class for resources. 
You will learn about this in the [next article](creating-resource.md).
