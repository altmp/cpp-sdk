#pragma once

#include <cstdint>

namespace alt
{
	// DO NOT CHANGE ORDER, ADD IN DECSENDING FASHION
	enum class PermissionState : uint8_t
	{
		// Permission is allowed by the user
		Allowed,
		// Permission is denied by the user
		Denied,
		// When a permission has not been specified by any of the resources
		Unspecified,
		// When an action requiring permission fails
		Failed
	};

	// DO NOT CHANGE ORDER, ADD IN DECSENDING FASHION (before All)
	enum class Permission : uint8_t
	{
		None,
		ScreenCapture,
		WebRTC,
		ClipboardAccess,
		All
	};
	static Permission GetPermissionFromString(StringView val)
	{
		if(val == "Screen Capture") return Permission::ScreenCapture;
		if(val == "WebRTC") return Permission::WebRTC;
		if(val == "Clipboard Access") return Permission::ClipboardAccess;
		return Permission::None;
	}
	static String GetStringFromPermission(Permission val)
	{
		if(val == Permission::ScreenCapture) return "Screen Capture";
		if(val == Permission::WebRTC) return "WebRTC";
		if(val == Permission::ClipboardAccess) return "Clipboard Access";
		return "None";
	}
}
