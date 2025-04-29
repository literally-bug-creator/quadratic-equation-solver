#include "../include/number_kit.h"

namespace {
    const std::string INVALID_INPUT_MSG = "Некорректный ввод";

    const Error INVALID_INPUT_ERROR =
        make_error( INVALID_INPUT, INVALID_INPUT_MSG );

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
}

NumberKit make_number_kit( const Number& a,
                           const Number& b,
                           const Number& c,
                           const Error& error ) {
    return NumberKit( a, b, c, error );
}

NumberKit input_number_kit() {
    Number a = input_number();
    Number b = input_number();
    Number c = input_number();

    if ( has_error( a, b, c ) || has_null( a, b, c ) ) { // Обдумать
        return make_number_kit( a, b, c, INVALID_INPUT_ERROR );
    }

    return make_number_kit( a, b, c );
}

Number get_a( const NumberKit& nums ) { return nums.a; }

Number get_b( const NumberKit& nums ) { return nums.b; }

Number get_c( const NumberKit& nums ) { return nums.c; }

Error get_error( const NumberKit& nums ) { return nums.error; }
