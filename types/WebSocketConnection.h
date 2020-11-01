#pragma once

#include <cstdint>

namespace alt {

    using WebSocketStateCallback = void (*)(WebSocketConnection *WebSocketConnection, State oldState,
                                            State newState);
    using WebSocketMessageCallback = void (*)(WebSocketConnection *WebSocketConnection, uint8_t *data);

    class WebSocketConnection {
    public:
        enum class State : uint8_t {
            Connecting,
            Open,
            Closing,
            Closed
        };

        virtual ~WebSocketConnection() = default;

        State GetState() const = 0;

        void Open() const = 0;

        void Close(int code) const = 0;

        void Send(uint8_t *data) const = 0;

        void AddStateListener(WebSocketStateCallback cb) const = 0;

        void AddMessageListener(WebSocketMessageCallback cb) const = 0;
    }
}
