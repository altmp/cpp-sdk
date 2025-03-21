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
		bool exists = false;

		void SetValue(uint64_t _value)
		{
			value = _value;
		}

		void Add(uint64_t _value)
		{
			value += _value;
		}

		void Inc()
		{
			++value;
		}

		void Begin()
		{
			lastBegin = Time();
		}

		// Deprecated old behavior, remove in future
		void End()
		{
			value = Time() - lastBegin;
		}

		void End2()
		{
			if (lastBegin == 0)
				return; // Warn?

			Add(Time() - lastBegin);
			lastBegin = 0;
		}

		void Destroy()
		{
			exists = false;
		}

		Metric() = default;
		explicit Metric(std::string_view _name): name(_name), value(0), exists(false) {}

	private:
		uint64_t lastBegin = 0;

		static inline uint64_t Time()
		{
			static uint64_t start = std::chrono::steady_clock::now().time_since_epoch().count();
			return std::chrono::steady_clock::now().time_since_epoch().count() - start;
		}
	};
}
