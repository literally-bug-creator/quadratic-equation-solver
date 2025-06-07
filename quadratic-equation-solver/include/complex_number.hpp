#pragma once

#include <string>

#include "constants.hpp"
#include "error.hpp"
#include "number.hpp"

struct ComplexNumber {
    Number real_part;
    Number imaginary_part;
    Error error;
};

ComplexNumber make_complex_number( Number real_part,
                                   Number imaginary_part,
                                   const Error& error = Errors::OK );

const Error& get_error( const ComplexNumber& number );

bool is_equal( const ComplexNumber& left, const ComplexNumber& right );

std::string to_string( const ComplexNumber& number );
