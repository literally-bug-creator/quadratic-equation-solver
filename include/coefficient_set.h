#pragma once

#include <string>

#include "coefficient.h"

struct CoefficientSet {
    const Coefficient a;
    const Coefficient b;
    const Coefficient c;
    const std::string error_msg;

    CoefficientSet( const Coefficient& a,
                    const Coefficient& b,
                    const Coefficient& c,
                    const std::string& error_msg = EMPTY_ERROR_MSG ):
        a( a ), b( b ), c( c ), error_msg( error_msg ) {}
};

CoefficientSet input_coefficient_set();

Coefficient get_a( const CoefficientSet& coeffs );

Coefficient get_b( const CoefficientSet& coeffs );

Coefficient get_c( const CoefficientSet& coeffs );

std::string get_error_msg( const CoefficientSet& coeffs );

bool is_valid( const CoefficientSet& coeffs );
