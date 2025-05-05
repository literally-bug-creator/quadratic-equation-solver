#include <optional>

#include "input.hpp"

std::optional<double> read_value( std::istream& in ) {
    double value;
    if ( in >> value ) { return value; }

    return std::optional<double>{};
}
