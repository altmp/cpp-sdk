#pragma once

#include <cstdint>

namespace alt
{
	// DO NOT CHANGE ORDER, ADD IN DECSENDING FASHION
	enum class PermissionState : uint8_t
	{
		// Permission is allowed by the user
		ALLOWED,
		// Permission is denied by the user
		DENIED,
		// When a permission has not been specified by any of the resources
		UNSPECIFIED,
		// When an action requiring permission fails
		FAILED
	};

	// DO NOT CHANGE ORDER, ADD IN DECSENDING FASHION (before All)
	enum class Permission : uint8_t
	{
		NONE,
		SCREEN_CAPTURE,
		WEBRTC,
		CLIPBOARD_ACCESS,
		EXTENDED_VOICE_API,
		All
	};
	static Permission GetPermissionFromString(const std::string& val)
	{
		if(val == "Screen Capture") return Permission::SCREEN_CAPTURE;
		if(val == "WebRTC") return Permission::WEBRTC;
		if(val == "Clipboard Access") return Permission::CLIPBOARD_ACCESS;
		if(val == "Extended Voice API") return Permission::EXTENDED_VOICE_API;
		return Permission::NONE;
	}
	static std::string GetStringFromPermission(Permission val)
	{
		if(val == Permission::SCREEN_CAPTURE) return "Screen Capture";
		if(val == Permission::WEBRTC) return "WebRTC";
		if(val == Permission::CLIPBOARD_ACCESS) return "Clipboard Access";
		if(val == Permission::EXTENDED_VOICE_API) return "Extended Voice API";
		return "None";
	}
}
