#pragma once

#include "../types/StringView.h"
#include "../types/MValueList.h"

#include "CEvent.h"

class CWebView;

namespace alt
{
	class CWebViewEvent : public CEvent
	{
	public:
		CWebViewEvent(CWebView* _target, StringView _name, MValueList _args) :
			CEvent(Type::WEB_VIEW_EVENT),
			target(_target),
			name(_name),
			args(_args)
		{

		}

		CWebView* GetTarget() const { return target; }
		StringView GetName() const { return name; }
		MValueList GetArgs() const { return args; }

	private:
		CWebView* target;
		String name;
		MValueList args;
	};
}
