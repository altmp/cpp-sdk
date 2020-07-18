#pragma once

#include <cstdint>

namespace alt
{
	// DO NOT CHANGE ORDER, ADD IN DECSENDING FASHION
	enum class PermissionState : uint8_t
	{
		Always,
		Once,
		Denied,
		Never,
		Failed
	};

	// DO NOT CHANGE ORDER, ADD IN DECSENDING FASHION (before All)
	enum class Permission : uint8_t
	{
		None,
		ScreenCapture,
		All
	};

	struct PermissionRequestData
	{
		using Callback = void(*)(PermissionState result, void* extra);
		Callback callback;
		void* extra;
		PermissionRequestData(Callback callback, void* extra = nullptr)
			: callback(callback), extra(extra) {}
	};
}
