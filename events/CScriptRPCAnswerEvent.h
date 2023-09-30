#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
    class IPlayer;
#ifdef ALT_CLIENT_API
	class CScriptRPCAnswerEvent : public CEvent
	{
	public:
        CScriptRPCAnswerEvent(uint16_t _answerID, const MValue& _answer, const std::string& _error) :
			CEvent(Type::SCRIPT_RPC_ANSWER_EVENT),
			answerID(_answerID),
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
#else
    class CScriptRPCAnswerEvent : public CEvent
    {
    public:
        CScriptRPCAnswerEvent(const std::shared_ptr<IPlayer>& _target, uint16_t _answerID, const MValue& _answer, const std::string& _error) :
                CEvent(Type::SCRIPT_RPC_ANSWER_EVENT),
                target(_target),
                answerID(_answerID),
                answer(_answer),
                answerError(_error)
        {

        }

        IPlayer* GetTarget() const { return target.get(); }
        uint16_t GetAnswerID() const { return answerID; }
        MValue GetAnswer() const { return answer; }
        std::string GetAnswerError() const { return answerError; }

    private:
        std::shared_ptr<IPlayer> target;
        uint16_t answerID;
        MValue answer;
        std::string answerError;
    };
#endif
}
