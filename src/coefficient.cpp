#include "../include/coefficient.h"
#include <cmath>
#include <iostream>

const double DEFAULT_VALUE = 0;
const double ZERO = 0;
const double TWO = 2;
const double FOUR = 4;

const std::string EMPTY_ERROR_MSG = "";
const std::string DIV_BY_ZERO_MSG = "Низя делить на нуль!";
const std::string ROOT_FROM_NEG_VALUE_MSG = "Низя брать корень из отрицательного числа!";

struct Coefficient{
    const double value;
    const std::string error_msg;

    Coefficient(
        const double number,
        const std::string &error_msg = EMPTY_ERROR_MSG
    ) : value(number), error_msg(error_msg) {}
};

Coefficient input_coefficient(){
    double value;
    std::cin >> value;

    return Coefficient(value);
}

std::string get_error_msg(const Coefficient &coeff){
    return coeff.error_msg;
}

bool is_valid(const Coefficient &coeff){
    std::string error_msg = get_error_msg(coeff);
    return error_msg == EMPTY_ERROR_MSG;
}

std::string to_string(const Coefficient &coeff){
    return std::to_string(coeff.value);
}

bool is_equal(const Coefficient &left, const Coefficient &right){
    return left.value == right.value;
}

bool is_not_equal(const Coefficient &left, const Coefficient &right){
    return left.value != right.value;
}

bool is_lower_than(const Coefficient &left, const Coefficient &right){
    return left.value < right.value;
}

Coefficient neg(const Coefficient &operand){
    double neg_value = -operand.value;
    return Coefficient(neg_value);
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

Coefficient get_invalid_coefficient(){
    return Coefficient(DEFAULT_VALUE);
}

Coefficient get_zero(){
    return Coefficient(ZERO);
}

Coefficient get_two(){
    return Coefficient(TWO);
}

Coefficient get_four(){
    return Coefficient(FOUR);
}
