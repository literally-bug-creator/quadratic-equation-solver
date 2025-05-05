#include "constants.cpp"
#include "equation_coefficients.hpp"

bool has_error( const Number& number ) {
    Error error = get_error( number );

    return error.code != OK;
}

bool has_error( const Number& a, const Number& b, const Number& c ) {
    return has_error( a ) || has_error( b ) || has_error( c );
}

bool has_null( const Number& a, const Number& b, const Number& c ) {
    return is_null( a ) || is_null( b ) || is_null( c );
}

EquationCoefficients make_equation_coefficients( const Number& a,
                                                 const Number& b,
                                                 const Number& c,
                                                 const Error& error ) {
    return EquationCoefficients( a, b, c, error );
}

EquationCoefficients input_equation_coefficients( std::istream& in ) {
    Number a = input_number( in );
    Number b = input_number( in );
    Number c = input_number( in );

    if ( has_error( a, b, c ) || has_null( a, b, c ) ) { // TODO: Обдумать
        return make_equation_coefficients(
            a, b, c, EquationCoefficientsErrors::INVALID_INPUT );
    }

    return make_equation_coefficients(
        a, b, c ); // Показывать различия вариантов
}

Number get_a( const EquationCoefficients& nums ) { return nums.a; }

Number get_b( const EquationCoefficients& nums ) { return nums.b; }

Number get_c( const EquationCoefficients& nums ) { return nums.c; }

Error get_error( const EquationCoefficients& nums ) { return nums.error; }
