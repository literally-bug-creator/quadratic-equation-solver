#include "constants.cpp"
#include "constants.hpp"
#include "equation_coefficients.hpp"
#include "error.hpp"

bool has_error( const Number& number ) {
    Error error = get_error( number );

    return !is_ok( error );
}

bool has_error( const Number& a, const Number& b, const Number& c ) {
    return has_error( a ) || has_error( b ) || has_error( c );
}

EquationCoefficients make_equation_coefficients( const Number& a,
                                                 const Number& b,
                                                 const Number& c,
                                                 const Error& error ) {
    return EquationCoefficients( a, b, c, error );
}

EquationCoefficients input_equation_coefficients() {
    Number a = input_number();
    Number b = input_number();
    Number c = input_number();

    if ( has_error( a, b, c ) ) {
        return make_equation_coefficients(
            a, b, c, EquationCoefficientsErrors::INVALID_INPUT );
    }

    return make_equation_coefficients( a, b, c, Errors::DEFAULT_ERROR );
}

const Number& get_a( const EquationCoefficients& nums ) { return nums.a; }

const Number& get_b( const EquationCoefficients& nums ) { return nums.b; }

const Number& get_c( const EquationCoefficients& nums ) { return nums.c; }

const Error& get_error( const EquationCoefficients& nums ) {
    return nums.error;
}
