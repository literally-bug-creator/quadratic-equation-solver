#pragma once

#include <string>

#include "constants.hpp"
#include "error.hpp"

struct Number {
    const double value;
    const Error error;

    Number( const double value, const Error& error ):
        value( value ), error( error ) {}
};

Number make_number( const double value, const Error& error = Errors::OK );

Number input_number();

const Error& get_error( const Number& number );

const bool operator==( const Number& left, const Number& right );

const bool operator!=( const Number& left, const Number& right );

const bool operator<( const Number& left, const Number& right );

const bool operator>( const Number& left, const Number& right );

const bool operator<=( const Number& left, const Number& right );

const bool operator>=( const Number& left, const Number& right );

const Number operator-( const Number& operand );

const Number operator+( const Number& augend, const Number& addend );

const Number operator-( const Number& minuend, const Number& subtrahend );

const Number operator*( const Number& multiplicand, const Number& multiplier );

const Number operator/( const Number& dividend, const Number& divisor );

const Number sqrt( const Number& radicand );

const std::string to_string( const Number& number );
