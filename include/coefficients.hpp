#pragma once

#include "number.hpp"

struct Coefficients {
    Number a;
    Number b;
    Number c;
    Error error;
};

Coefficients make_coefficients( const Number& a,
                                const Number& b,
                                const Number& c,
                                const Error& error = Errors::OK );

Coefficients input_coefficients();

const Number& get_a( const Coefficients& coeffs );

const Number& get_b( const Coefficients& coeffs );

const Number& get_c( const Coefficients& coeffs );

const Error& get_error( const Coefficients& coeffs );
