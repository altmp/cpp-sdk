#pragma once

#include "../types/MValue.h"
#include "../types/MValueList.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CDataNodeReceivedEvent : public CEvent
	{
	public:
		CDataNodeReceivedEvent(StringView _name, StringView _logJson) :
			CEvent(Type::DATA_NODE_RECEIVED_EVENT),
			name(_name),
			json(_logJson)
		{

		}

		StringView GetName() const { return name; }
		StringView GetJson() const { return json; }

	private:
		String name;
		String json;
	};
}
