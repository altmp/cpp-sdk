#pragma once

namespace alt
{
	template<typename Value, typename Error>
	struct Expected
	{
		Value value;
		Error error;
		bool success;

		Expected(Value _value, Error _error, bool _success) :
			value(_value), error(_error), success(_success) { }
	};
}
