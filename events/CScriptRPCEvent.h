#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CScriptRPCEvent : public CEvent
	{
	public:
        enum class State {
			NOT_ANSWERED,
			WILL_BE_ANSWERED,
			ANSWERED
        };

#ifdef ALT_SERVER_API
        CScriptRPCEvent(const std::shared_ptr<IPlayer>& _target, const std::string& _name, const MValueArgs&_args, uint16_t _answerID) :
			CEvent(Type::SCRIPT_RPC_EVENT),
			target(_target),
			name(_name),
			args(_args),
            answerID(_answerID)
		{

		}
#else
        CScriptRPCEvent(const std::string& _name, const MValueArgs&_args, uint16_t _answerID) :
			CEvent(Type::SCRIPT_RPC_EVENT),
			name(_name),
			args(_args),
            answerID(_answerID)
		{

		}
#endif

#ifdef ALT_SERVER_API
		IPlayer* GetTarget() const { return target.get(); }
#endif
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

		bool Answer(MValue _answer)
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

		MValue GetAnswer() const { return answer; }

		std::string GetAnswerError() const { return answerError; }

	private:
		State state = State::NOT_ANSWERED;
#ifdef ALT_SERVER_API
		std::shared_ptr<IPlayer> target;
#endif
		std::string name;
		MValueArgs args;
		uint16_t answerID;
		MValue answer;
		std::string answerError;
	};
}
