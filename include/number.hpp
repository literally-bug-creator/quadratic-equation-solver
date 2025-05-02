#pragma once

#include <string>

#include "constants.hpp"
#include "error.hpp"

struct Number {
    const double value;
    const Error error;
    const bool is_null;

    Number( const double value, const Error& error, const bool is_null ):
        value( value ), error( error ), is_null( is_null ) {}
};

Number make_number( const double value,
                    const Error& error = Errors::DEFAULT_ERROR,
                    const bool is_null = false );

Number input_number( std::istream& in );

Error get_error( const Number& number );

bool is_null( const Number& number );

bool is_equal( const Number& left, const Number& right );

bool is_lower_than( const Number& left, const Number& right );

Number neg( const Number& operand );

Number add( const Number& augend, const Number& addend );

Number sub( const Number& minuend, const Number& subtrahend );

Number mul( const Number& multiplicand, const Number& multiplier );

Number div( const Number& dividend, const Number& divisor );

Number sqrt( const Number& radicand );

std::string to_string( const Number& number );
