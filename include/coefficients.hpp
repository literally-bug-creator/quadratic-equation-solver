#pragma once

#include "constants.hpp"
#include "number.hpp"

struct Coefficients {
    const Number a;
    const Number b;
    const Number c;
    const Error error;

    Coefficients( const Number& a,
                  const Number& b,
                  const Number& c,
                  const Error& error ):
        a( a ), b( b ), c( c ), error( error ) {}
};

Coefficients make_coefficients(
    const Number& a,
    const Number& b,
    const Number& c,
    const Error& error = Errors::DEFAULT_ERROR ); // TODO: Rethink error name

Coefficients input_coefficients();

const Number& get_a( const Coefficients& nums );

const Number& get_b( const Coefficients& nums );

const Number& get_c( const Coefficients& nums );

const Error& get_error( const Coefficients& nums );
