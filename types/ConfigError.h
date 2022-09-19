#pragma once

#include <cstdint>
#include <string>

namespace alt
{
	struct ConfigError
	{
		std::string error;
		uint64_t position;
		uint64_t line;
		uint64_t column;

		ConfigError(std::string _error, uint64_t _position, uint64_t _line, uint64_t _column) :
			error(_error), position(_position), line(_line), column(_column) { }
	};
}
