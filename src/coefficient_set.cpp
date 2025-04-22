#include "../include/coefficient_set.h"
#include <string>

const std::string NEW_LINE = "\n";

std::string get_error_msg(const CoefficientSet &coeffs){
    return coeffs.error_msg;
}

bool is_valid(const CoefficientSet &coeffs){
    std::string error_msg = get_error_msg(coeffs);
    return error_msg == EMPTY_ERROR_MSG;
}

Coefficient get_a(const CoefficientSet &coeffs){
    return coeffs.a;
}

Coefficient get_b(const CoefficientSet &coeffs){
    return coeffs.b;
}

Coefficient get_c(const CoefficientSet &coeffs){
    return coeffs.c;
}

bool is_coefficients_valid(const Coefficient &a, const Coefficient &b, const Coefficient &c){
    bool is_a_valid = is_valid(a);
    bool is_b_valid = is_valid(b);
    bool is_c_valid = is_valid(c);

    return is_a_valid && is_b_valid && is_c_valid;
}

std::string unite_error_msgs(const std::string &a_msg, const std::string &b_msg, const std::string &c_msg){
    std::string msg = EMPTY_ERROR_MSG;

    if (a_msg != EMPTY_ERROR_MSG) msg += a_msg + NEW_LINE;
    if (b_msg != EMPTY_ERROR_MSG) msg += b_msg + NEW_LINE;
    if (c_msg != EMPTY_ERROR_MSG) msg += c_msg;

    return msg;
}

std::string collect_error_msg(const Coefficient &a, const Coefficient &b, const Coefficient &c){
    std::string a_error_msg = get_error_msg(a);
    std::string b_error_msg = get_error_msg(b);
    std::string c_error_msg = get_error_msg(c);
    std::string msgs = unite_error_msgs(a_error_msg, b_error_msg, c_error_msg);

    return msgs;
}

CoefficientSet get_coefficient_set(){
    Coefficient a = get_coefficient();
    Coefficient b = get_coefficient();
    Coefficient c = get_coefficient();
    std::string error_msg = collect_error_msg(a, b, c);

    return CoefficientSet(a, b, c, error_msg);
}
