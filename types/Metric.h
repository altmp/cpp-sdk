#pragma once

#include <cstdint>
#include <string>

namespace alt
{
	struct Metric
	{
		enum Type: uint8_t
		{
			METRIC_TYPE_GAUGE,
			METRIC_TYPE_COUNTER,
			METRIC_TYPE_SIZE
		};

		std::string name {};
		uint64_t value = 0;

		void SetValue(uint64_t _value)
		{
			value = _value;
		}

		void Begin()
		{
			lastBegin = Time();
		}

		void End()
		{
			value = Time() - lastBegin;
		}

		Metric() = default;
		explicit Metric(std::string_view _name): name(_name), value(0) {}

	private:
		uint64_t lastBegin = 0;

		static inline uint64_t Time()
		{
			static uint64_t start = std::chrono::steady_clock::now().time_since_epoch().count();
			return std::chrono::steady_clock::now().time_since_epoch().count() - start;
		}
	};
}
