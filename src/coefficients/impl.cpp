#include "coefficients.hpp"
#include "constants.cpp"
#include "constants.hpp"
#include "error.hpp"

bool has_error( const Number& number ) {
    Error error = get_error( number );

    return !is_ok( error );
}

bool has_error( const Number& a, const Number& b, const Number& c ) {
    return has_error( a ) || has_error( b ) || has_error( c );
}

Coefficients make_coefficients( const Number& a,
                                const Number& b,
                                const Number& c,
                                const Error& error ) {
    return Coefficients( a, b, c, error );
}

Coefficients input_coefficients() {
    Number a = input_number();
    Number b = input_number();
    Number c = input_number();

    if ( has_error( a, b, c ) ) {
        return make_coefficients( a, b, c, CoefficientsErrors::INVALID_INPUT );
    }

    return make_coefficients( a, b, c, Errors::DEFAULT_ERROR );
}

const Number& get_a( const Coefficients& nums ) { return nums.a; }

const Number& get_b( const Coefficients& nums ) { return nums.b; }

const Number& get_c( const Coefficients& nums ) { return nums.c; }

const Error& get_error( const Coefficients& nums ) { return nums.error; }
