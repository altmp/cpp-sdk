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
        CServerScriptRPCAnswerEvent(const std::shared_ptr<IPlayer>& _target, uint16_t _answerID, const MValueArgs& _answer, const std::string& _error) :
			CEvent(Type::SERVER_SCRIPT_RPC_ANSWER_EVENT),
			target(_target),
			answer(_answer),
			answerError(_error)
		{

		}

		IPlayer* GetTarget() const { return target.get(); }
		uint16_t GetAnswerID() const { return answerID; }
		MValueArgs GetAnswer() const { return answer; }
		std::string GetAnswerError() const { return answerError; }

	private:
		std::shared_ptr<IPlayer> target;
		uint16_t answerID;
		MValueArgs answer;
		std::string answerError;
	};
#endif
}
