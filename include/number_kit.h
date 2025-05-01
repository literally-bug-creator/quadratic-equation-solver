#pragma once

#include "number.h"

struct NumberKit {
    const Number a;
    const Number b;
    const Number c;
    const Error error;

    NumberKit( const Number& a,
               const Number& b,
               const Number& c,
               const Error& error ):
        a( a ), b( b ), c( c ), error( error ) {}
};

NumberKit make_number_kit( const Number& a,
                           const Number& b,
                           const Number& c,
                           const Error& error = DEFAULT_ERROR );

NumberKit input_number_kit( std::istream& in );

Number get_a( const NumberKit& nums );

Number get_b( const NumberKit& nums );

Number get_c( const NumberKit& nums );

Error get_error( const NumberKit& nums );
