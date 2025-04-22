#pragma once

#include <string>

const std::string EMPTY_ERROR_MSG = "";

struct Coefficient{
    const double value;
    const std::string error_msg;

    Coefficient(const double number, const std::string &error_msg = EMPTY_ERROR_MSG) : value(number), error_msg(error_msg) {}
};

Coefficient get_invalid_coefficient();

bool is_valid(const Coefficient &coeff);

Coefficient add(const Coefficient &augend, const Coefficient &addend);

Coefficient sub(const Coefficient &minuend, const Coefficient &subtrahend);

Coefficient mul(const Coefficient &multiplicand, const Coefficient &multiplier);

Coefficient div(const Coefficient &dividend, const Coefficient &divisor);

Coefficient square_root(const Coefficient &radicand);

Coefficient get_coefficient();
