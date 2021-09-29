#pragma once

namespace alt
{
    class IAudioFilter
    {
    public:
        struct pcm16
        {
            int16_t left;
            int16_t right;
        };

        struct pcmSample
        {
            union
            {
                pcm16 channels;
                int32_t sample;
            };
        };

    protected:
        virtual ~IAudioFilter() = default;

    public:
        virtual void SetParam(const std::string& key, int32_t value) {}
        virtual void SetParam(const std::string& key, float value) {}
        virtual void SetParam(const std::string& key, bool value) {}

        virtual void GetParam(const std::string& key, int32_t& value) {}
        virtual void GetParam(const std::string& key, float& value) {}
        virtual void GetParam(const std::string& key, bool& value) {}

        virtual void Process(pcmSample* data, uint32_t size) = 0;
    };
}