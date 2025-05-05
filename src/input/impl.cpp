#include <optional>

#include "constants.cpp"
#include "input.hpp"

std::optional<double> read_value() {
    double value;
    if ( INPUT_STREAM >> value ) { return value; }

    return std::optional<double>{};
}
