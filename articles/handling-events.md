# Handling events

In this article you will learn how to handle and emit events with the module SDK.

## What is an event

An event is an action that has happened on the client/server and is not caused by the developer directly.
E.g. when a player is spawned no event is dispatched, because the developer has full control over spawning the player, and because of that
no event is needed. On the other hand when e.g. a player gets damaged, the player damage event gets dispatched, so the developer can act
upon that action.

Events are automatically dispatched by the alt:V core and need to be handled and forwarded to the scripting language by the module.

## How to handle events

There are two ways to handle events. They can be either handled globally, or they are handled by each resource individually.
It is recommended the module handles the events per resource.

Both approaches will be covered here.

### Handling events globally

Events can be handled globally by using the [`alt::ICore::SubscribeEvent`](https://github.com/altmp/cpp-sdk/blob/master/ICore.h#L85) method.
This method accepts three parameters, first is the event type that should be handled, second is the callback for the event
and third is the custom user data passed to the callback. The user data is optional and can be left as a `nullptr`.

Here is an example on how to handle the player connect event globally:
```c++
alt::ICore::Instance().SubscribeEvent(alt::CEvent::Type::PLAYER_CONNECT, [](const alt::CEvent* ev, void* userData) {
    // Cast the event to the correct event class to access the event data
    auto event = static_cast<const alt::CPlayerConnectEvent*>(ev);

    // Gets the player that connected to the server
    alt::Ref<alt::IPlayer*> player = event->GetTarget();
    // Gets the connect reason
    alt::StringView reason = event->GetReason();

    // Log the player name and connect reason to the console
    std::stringstream stream;
    stream << "Player " << player->GetName().CStr() << " connected. Reason: " << reason.CStr();
    alt::ICore::Instance().LogInfo(stream.str());

    // In a real module we would obviously do something more useful with the data from this event,
    // like forwarding it to the scripting language.

    return true;
});
```

This method can also catch *all* incoming events by using the `alt::CEvent::Type::ALL` event type.

> It is recommended to handle events per resource, handling events globally should mostly be used for debugging purposes.

### Handling events per resource

The module can also choose to handle events per resource individually instead of in a single global event handler.
This can be done by using the `OnEvent` method of your [own resource class](creating-resource.md).
When using this approach, you have to use the `GetType` method of the received event, to determine the type of the event
and to cast it to its corresponding event class.

An example for this can be seen here:
```c++
bool MyResource::OnEvent(const alt::CEvent* ev)
{
    // Get the type of the event
    auto type = ev->GetType();
    // Do something if the event is the player connect event
    if(type == alt::CEvent::Type::PLAYER_CONNECT)
    {
        // Cast the event to the correct event class to access the event data
        auto event = static_cast<const alt::CPlayerConnectEvent*>(ev);

        // Gets the player that connected to the server
        alt::Ref<alt::IPlayer*> player = event->GetTarget();
        // Gets the connect reason
        alt::StringView reason = event->GetReason();

        // Log the player name and connect reason to the console
        std::stringstream stream;
        stream << "Player " << player->GetName().CStr() << " connected. Reason: " << reason.CStr();
        alt::ICore::Instance().LogInfo(stream.str());

        // In a real module we would obviously do something more useful with the data from this event,
        // like forwarding it to the scripting language.
    }
}
```

It is recommended to not handle every event in this method directly for clarity.
There should be some sort of wrapper for events in your module.
An example for this can be found in the [JS module](https://github.com/altmp/altv-js-module/blob/10c39827fea32d6092d69364b3d6ec3b46540ba2/shared/V8Helpers.h#L108) 
or the [AngelScript module](https://github.com/LeonMrBonnie/altv-angelscript-module/blob/dev/src/helpers/events.h).

> A list of event types can be found [here](https://github.com/altmp/cpp-sdk/blob/master/events/CEvent.h#L10).

### Canceling events

There are two ways of cancelling an event, either you can cancel an event to discard it's data to not sync it to other clients except than the player
who sent that data (E.g. in the explosion event), or you cancel an event to remove it from the event queue so that other event handlers (global or per resource)
will not receive that event.

The first way can be achieved by calling the `Cancel` method on the received event, and the second way can be done by returning `false` from the event callback.

## How to emit events

It is possible to emit custom events (`alt::CEvent::Type::SERVER_SCRIPT_EVENT` or `alt::CEvent::Type::CLIENT_SCRIPT_EVENT`) from the module.
These events can be emitted by using 
[`alt::ICore::TriggerLocalEvent`](https://github.com/altmp/cpp-sdk/blob/14d63e7b7bf1135c43664144aed07a061eac26ca/ICore.h#L106s),
[`alt::ICore::TriggerLocalEventOnMain`](https://github.com/altmp/cpp-sdk/blob/14d63e7b7bf1135c43664144aed07a061eac26ca/ICore.h#L107) and 
[`alt::ICore::TriggerClientEvent`](https://github.com/altmp/cpp-sdk/blob/14d63e7b7bf1135c43664144aed07a061eac26ca/ICore.h#L297) respectively.

These methods take the custom event name and the event arguments as parameters. The event arguments have to be in the form
of [MValues](#what-are-mvalues).
An example on how to emit an custom event can be found here:
```c++
// Create an instance of an MValueArgs array to store our event arguments.
// We can also use an `alt::Array<alt::MValueConst>` instead, they are the same.
// But we use MValueArgs here for code clarity.
alt::MValueArgs args;

// Push an integer to the arguments
auto arg = alt::ICore::Instance().CreateMValueInt(523);
args.Push(arg);

// Push a bool to the arguments
auto arg2 = alt::ICore::Instance().CreateMValueBool(true);
args.Push(arg2);

// Emit the event
alt::ICore::Instance().TriggerLocalEvent("MyCustomEvent", args);
```

> All methods to create MValues can be found [here](https://github.com/altmp/cpp-sdk/blob/14d63e7b7bf1135c43664144aed07a061eac26ca/ICore.h#L68-L84).

## What are MValues

The [next article](mvalues.md) will explain what MValues are and how to use them.
