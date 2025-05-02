#pragma once

#include <istream>
#include <optional>

extern std::istream& INPUT_STREAM;

std::optional<double> read_value( std::istream& in );
