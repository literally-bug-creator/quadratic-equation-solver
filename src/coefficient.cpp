#include "../include/coefficient.h"
#include <cmath>
#include <string>
#include <iostream>

const double DEFAULT_VALUE = 0.0;
const double ZERO = 0.0;

const std::string DIV_BY_ZERO_MSG = "Низя делить на нуль!";
const std::string ROOT_FROM_NEG_VALUE_MSG = "Низя брать корень из отрицательного числа!";

Coefficient get_invalid_coefficient(){
    return Coefficient(DEFAULT_VALUE);
}

bool is_valid(const Coefficient &coeff){
    return coeff.error_msg != EMPTY_ERROR_MSG;
}

Coefficient add(const Coefficient &augend, const Coefficient &addend){
    double sum = augend.value + addend.value;
    return Coefficient(sum);
}

Coefficient sub(const Coefficient &minuend, const Coefficient &subtrahend){
    double difference = minuend.value - subtrahend.value;
    return Coefficient(difference);
}

Coefficient mul(const Coefficient &multiplicand, const Coefficient &multiplier){
    double product = multiplicand.value * multiplier.value;
    return Coefficient(product);
}

Coefficient div(const Coefficient &dividend, const Coefficient &divisor){
    if (divisor.value == ZERO){
        return Coefficient(DEFAULT_VALUE, DIV_BY_ZERO_MSG);
    }

    double quotient = dividend.value / divisor.value;
    return Coefficient(quotient);
}

Coefficient square_root(const Coefficient &radicand){
    if (radicand.value < ZERO){
        return Coefficient(DEFAULT_VALUE, ROOT_FROM_NEG_VALUE_MSG);
    }

    double root = sqrt(radicand.value);
    return Coefficient(root);
}

Coefficient get_coefficient(){
    double value;
    std::cin >> value;

    return Coefficient(value);
}
