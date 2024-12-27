#pragma once

#include <cstddef>

#include "stdafx.h"

namespace alt
{
	namespace system
	{
		/// \brief Interface system information
		/// \note Gets information about the system load
		class ISystemInfoAPI
		{
		public:
			ISystemInfoAPI() = default;
			virtual ~ISystemInfoAPI() noexcept = default;

			static ISystemInfoAPI& GetInstance() { return *Instance(); }

			static void SetInstance(ISystemInfoAPI* server) { Instance() = server; }

#ifdef ALT_CLIENT_API
			/// \brief Get CPU load
			/// \return Load percentage
			virtual double GetCPULoad() = 0;

			/// \brief Get video memory usage
			/// \return Size of used memory in MB
			virtual std::size_t GetVideoMemoryUsage() = 0;

			/// \brief Get RAM usage
			/// \return Size of used memory in MB
			virtual std::size_t GetRAMUsage() = 0;
#endif

		private:
			static ISystemInfoAPI*& Instance()
			{
				static ISystemInfoAPI* instance = nullptr;
				return instance;
			}

			ISystemInfoAPI(ISystemInfoAPI&& other) = delete;
			ISystemInfoAPI(const ISystemInfoAPI& other) = delete;
			ISystemInfoAPI& operator=(ISystemInfoAPI&& other) = delete;
			ISystemInfoAPI& operator=(const ISystemInfoAPI& other) = delete;
		};
	}  // namespace system
}  // namespace alt
