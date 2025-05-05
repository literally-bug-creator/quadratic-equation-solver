#pragma once

#include "constants.hpp"
#include "number.hpp"

struct EquationCoefficients {
    const Number a;
    const Number b;
    const Number c;
    const Error error;

    EquationCoefficients( const Number& a,
                          const Number& b,
                          const Number& c,
                          const Error& error ):
        a( a ), b( b ), c( c ), error( error ) {}
};

EquationCoefficients make_equation_coefficients(
    const Number& a,
    const Number& b,
    const Number& c,
    const Error& error = Errors::DEFAULT_ERROR ); // TODO: Rethink error name

EquationCoefficients input_equation_coefficients( std::istream& in );

Number
get_a( const EquationCoefficients& nums ); // Погуглить про константный геттер

Number get_b( const EquationCoefficients& nums );

Number get_c( const EquationCoefficients& nums );

Error get_error( const EquationCoefficients& nums );
