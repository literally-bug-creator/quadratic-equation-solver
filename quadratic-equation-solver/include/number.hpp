#pragma once

#include <string>

#include "big_number.hpp"
#include "constants.hpp"
#include "error.hpp"

struct Number {
    big_number::BigNumber value;
    Error error;
};

Number make_number( big_number::BigNumber value,
                    const Error& error = Errors::OK );

Number input_number();

const Error& get_error( const Number& number );

bool is_equal( const Number& left, const Number& right );

bool is_lower_than( const Number& left, const Number& right );

Number neg( const Number& operand );

Number add( const Number& augend, const Number& addend );

Number sub( const Number& minuend, const Number& subtrahend );

Number mul( const Number& multiplicand, const Number& multiplier );

Number div( const Number& dividend, const Number& divisor );

Number sqrt( const Number& radicand );

std::string to_string( const Number& number );
