#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
#ifdef ALT_SERVER_API
	class IPlayer;

	class CClientScriptRPCEvent : public CEvent
	{
	public:
        enum class State {
			NOT_ANSWERED,
			WILL_BE_ANSWERED,
			ANSWERED
        };

        CClientScriptRPCEvent(const std::shared_ptr<IPlayer>& _target, const std::string& _name, const MValueArgs&_args, uint16_t _answerID) :
			CEvent(Type::CLIENT_SCRIPT_RPC_EVENT),
			target(_target),
			name(_name),
			args(_args),
            answerID(_answerID)
		{

		}

		IPlayer* GetTarget() const { return target.get(); }
		const std::string& GetName() const { return name; }
		const MValueArgs& GetArgs() const { return args; }
		uint16_t GetAnswerID() const { return answerID; }

		bool WillAnswer()
		{
			if (state != State::NOT_ANSWERED)
			{
				return false;
			}
			state = State::WILL_BE_ANSWERED;
			return true;
		}

		bool Answer(MValueArgs _answer)
		{
			if (state == State::ANSWERED)
			{
				return false;
			}
			state = State::ANSWERED;
			answer = _answer;
			return true;
		}

		bool AnswerWithError(const std::string& _error)
		{
			if (state == State::ANSWERED)
			{
				return false;
			}
			state = State::ANSWERED;
			answerError = _error;
			return true;
		}

		State GetState() const { return state; }

		MValueArgs GetAnswer() const { return answer; }

		std::string GetAnswerError() const { return answerError; }

	private:
		State state = State::NOT_ANSWERED;
		std::shared_ptr<IPlayer> target;
		std::string name;
		MValueArgs args;
		uint16_t answerID;
		MValueArgs answer;
		std::string answerError;
	};
#endif
}
