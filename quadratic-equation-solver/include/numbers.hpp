#pragma once

#include <variant>

#include "complex_number.hpp"
#include "number.hpp"

using Numbers = std::variant<Number, ComplexNumber>;

const Error& get_error( const Numbers& number );

bool is_equal( const Numbers& left, const Numbers& right );

bool is_lower_than( const Numbers& left, const Numbers& right );

std::string to_string( const Numbers& number );
