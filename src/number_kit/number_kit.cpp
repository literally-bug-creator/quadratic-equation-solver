#include "number_kit.hpp"

#include "number_kit_constants.cpp"

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

NumberKit make_number_kit( const Number& a,
                           const Number& b,
                           const Number& c,
                           const Error& error ) {
    return NumberKit( a, b, c, error );
}

NumberKit input_number_kit( std::istream& in ) {
    Number a = input_number( in );
    Number b = input_number( in );
    Number c = input_number( in );

    if ( has_error( a, b, c ) || has_null( a, b, c ) ) { // TODO: Обдумать
        return make_number_kit( a, b, c, NumberKitErrors::INVALID_INPUT );
    }

    return make_number_kit( a, b, c ); // Показывать различия вариантов
}

Number get_a( const NumberKit& nums ) { return nums.a; }

Number get_b( const NumberKit& nums ) { return nums.b; }

Number get_c( const NumberKit& nums ) { return nums.c; }

Error get_error( const NumberKit& nums ) { return nums.error; }
