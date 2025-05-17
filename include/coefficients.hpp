#pragma once

#include "constants.hpp"
#include "number.hpp"

using Coefficients =
    std::pair<std::pair<Number, Number>, std::pair<Number, Error>>;

Coefficients input_coefficients();

Coefficients make_coefficients( const Number& a,
                                const Number& b,
                                const Number& c,
                                const Error& error = Errors::OK );

const Number get_a( const Coefficients& coeffs );

const Number get_b( const Coefficients& coeffs );

const Number get_c( const Coefficients& coeffs );

const Error get_error( const Coefficients& coeffs );
