# MValues

This article will explain what MValues are and how to use them in your module.

## Table of Contents

1. [What are MValues](#what-are-mvalues)
2. [The different MValue types](#the-different-mvalue-types)
3. [How to create MValues](#how-to-create-mvalues)
4. [Refs](#refs)

## What are MValues

MValues are containers that store a value of some specific data type.
They are created so that a value can be exchanged between different programming languages without much hassle.

There is an MValue Type for every different data type one would need to exchange between resource and/or client and server.
For example there is an MValue for `Integers`, the MValue stores the C++ integer and then the MValue can be passed to e.g. an event.
The module then has to convert the C++ value stored in the MValue to the corresponding value in the programming language the module offers.

## The different MValue types

In total there are `13` different MValue types, each of these types is used to store some other type of data.

Here is a list of all different MValue types:

| Type         | Description                                                       |
| ------------ | ----------------------------------------------------------------- |
| `None`       | An implicit empty value, used for invalid values                  |
| `Nil`        | An explicit empty value, used for `null` in most languages        |
| `Bool`       | A boolean value (`true`/`false`)                                  |
| `Int`        | A whole number, can be either positive or negative                |
| `UInt`       | A whole number, can only be positive                              |
| `Double`     | A floating point number                                           |
| `String`     | A text value                                                      |  
| `List`       | A collection of multiple elements (aka. `array`)                  |
| `Dict`       | A dictionary with key-value pairs                                 |
| `BaseObject` | An alt:V base object (Objects like vehicles, players etc.)        |
| `Function`   | A function that can be called                                     |
| `Vector2`    | A two-dimensional vector                                          |
| `Vector3`    | A three-dimensional vector                                        |
| `RGBA`       | A R(ed), G(reen), B(lue), A(lpha) color                           |
| `ByteArray`  | An array of raw bytes                                             |

To verify all MValue types available see the [SDK source code](https://github.com/altmp/cpp-sdk/blob/master/types/MValue.h).

> All MValue number types are `64-bit` and floating-point numbers are `doubles`

## How to create MValues

The module can create MValues by using the methods provided by `alt::ICore`.
There is at least one method for every different MValue type, which returns that MValue type.

A small example on how to create an MValue and get the data stored in it can be found here:
```c++
// Create the MValue by using the method from the core
alt::MValueInt mvalue = alt::ICore::Instance().CreateMValueInt(4324);

// Get the data stored in the MValue
// All MValue types have a 'Value' method that returns it's stored method
int64_t value = mvalue.Value();

// You can also check the type of the MValue if its a generic MValue
alt::IMValue::Type type = mvalue.GetType();
if(type == alt::IMValue::Type::INT)
{
    // Now the MValue can be casted to the correct MValue class
    auto castedMvalue = static_cast<alt::MValueInt>(mvalue);
}
```

Another example can be found in the [article about event handling](handling-events.md#how-to-emit-events).

> All the methods to create MValues can be found [here](https://github.com/altmp/cpp-sdk/blob/dev/ICore.h#L61).

## Refs

Now you also know what an MValue is and how to use it.
The next article will explain [what a Ref is and how to use it](refs.md).
