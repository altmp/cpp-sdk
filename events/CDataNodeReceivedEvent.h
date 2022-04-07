#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CDataNodeReceivedEvent : public CEvent
	{
	public:
		CDataNodeReceivedEvent(const std::string& _name, const std::string& _logJson) :
			CEvent(Type::DATA_NODE_RECEIVED_EVENT),
			name(_name),
			json(_logJson)
		{

		}

		const std::string& GetName() const { return name; }
		const std::string& GetJson() const { return json; }

	private:
		std::string name;
		std::string json;
	};
}
