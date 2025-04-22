#pragma once

#include <string>
#include "coefficient.h"

struct CoefficientSet{
    const Coefficient a;
    const Coefficient b;
    const Coefficient c;
    const std::string error_msg;
};

CoefficientSet get_coefficient_set();

Coefficient get_a(const CoefficientSet &coeffs);

Coefficient get_b(const CoefficientSet &coeffs);

Coefficient get_c(const CoefficientSet &coeffs);

bool has_error(const CoefficientSet &coeffs);

std::string get_error_msg(const CoefficientSet &coeffs);
