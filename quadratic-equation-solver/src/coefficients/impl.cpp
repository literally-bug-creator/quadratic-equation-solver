#include "coefficients.hpp"
#include "constants.cpp"
#include "constants.hpp"
#include "error.hpp"
#include "number.hpp"

bool has_error( const Number& number ) {
    const Error& error = get_error( number );
    return !is_ok( error );
}

Error get_error_or_ok( const Number& a, const Number& b, const Number& c ) {
    if ( has_error( a ) )
        return get_error( a );

    else if ( has_error( b ) )
        return get_error( b );

    else if ( has_error( c ) )
        return get_error( c );

    return Errors::OK;
}

Coefficients make_coefficients( const Number& a,
                                const Number& b,
                                const Number& c,
                                const Error& error ) {
    return Coefficients{ a, b, c, error };
}

Coefficients input_coefficients() {
    Number a = input_number();
    Number b = input_number();
    Number c = input_number();

    return make_coefficients( a, b, c, get_error_or_ok( a, b, c ) );
}

const Number& get_a( const Coefficients& coeffs ) { return coeffs.a; }

const Number& get_b( const Coefficients& coeffs ) { return coeffs.b; }

const Number& get_c( const Coefficients& coeffs ) { return coeffs.c; }

const Error& get_error( const Coefficients& coeffs ) { return coeffs.error; }
