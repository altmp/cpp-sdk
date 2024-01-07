#pragma once

namespace alt
{
	struct SyncInfo
	{
		uint8_t active;
		uint32_t receivedTick;
		uint32_t fullyReceivedTick;
		uint32_t sendTick;
		uint32_t ackedSendTick;
		uint16_t propertyCount;
		uint8_t componentCount;
		// array size of propertyCount
		uint32_t* propertiesUpdateTick;
		// array size of componentCount - 1, if (componentCount == 0) => nullptr
		uint32_t* componentPropertyIndex;
	};
} // namespace alt
