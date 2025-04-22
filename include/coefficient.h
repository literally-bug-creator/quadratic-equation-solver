#pragma once

struct Coefficient{
    const float value;
};

Coefficient get_invalid_coefficient();

Coefficient get_coefficient();

bool is_valid(const Coefficient &coeff);

Coefficient add(const Coefficient &augend, const Coefficient &addend);

Coefficient sub(const Coefficient &minuend, const Coefficient &subtrahend);

Coefficient mul(const Coefficient &multiplicand, const Coefficient &multiplier);

Coefficient div(const Coefficient &dividend, const Coefficient &divisor);

Coefficient square_root(const Coefficient &radicand);
