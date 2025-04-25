#pragma once

#include <string>

struct Coefficient;

Coefficient input_coefficient();

std::string get_error_msg(const Coefficient &coeff);

bool is_valid(const Coefficient &coeff);

std::string to_string(const Coefficient &coeff);

bool is_equal(const Coefficient &left, const Coefficient &right);

bool is_not_equal(const Coefficient &left, const Coefficient &right);

bool is_lower_than(const Coefficient &left, const Coefficient &right);

Coefficient neg(const Coefficient &operand);

Coefficient add(const Coefficient &augend, const Coefficient &addend);

Coefficient sub(const Coefficient &minuend, const Coefficient &subtrahend);

Coefficient mul(const Coefficient &multiplicand, const Coefficient &multiplier);

Coefficient div(const Coefficient &dividend, const Coefficient &divisor);

Coefficient square(const Coefficient &operand);

Coefficient square_root(const Coefficient &radicand);

Coefficient get_invalid_coefficient();

Coefficient get_zero();

Coefficient get_two();

Coefficient get_four();
