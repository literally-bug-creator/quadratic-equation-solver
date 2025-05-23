#pragma once

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

Coefficients input_coefficients();

const Number& get_a( const Coefficients& coeffs );

const Number& get_b( const Coefficients& coeffs );

const Number& get_c( const Coefficients& coeffs );

const Error& get_error( const Coefficients& coeffs );
