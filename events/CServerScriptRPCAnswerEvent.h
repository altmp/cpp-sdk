#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
#ifdef ALT_CLIENT_API
    class IPlayer;

	class CServerScriptRPCAnswerEvent : public CEvent
	{
	public:
        CServerScriptRPCAnswerEvent(uint16_t _answerID, const MValue& _answer, const std::string& _error) :
			CEvent(Type::SERVER_SCRIPT_RPC_ANSWER_EVENT),
			answer(_answer),
			answerError(_error)
		{

		}

		uint16_t GetAnswerID() const { return answerID; }
		MValue GetAnswer() const { return answer; }
		std::string GetAnswerError() const { return answerError; }

	private:
		uint16_t answerID;
		MValue answer;
		std::string answerError;
	};
#endif
}
