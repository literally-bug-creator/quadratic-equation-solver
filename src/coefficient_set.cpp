#include "../include/coefficient_set.h"
#include <string>

const std::string NEW_LINE = "\n";


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

CoefficientSet input_coefficient_set(){
    Coefficient a = input_coefficient();
    Coefficient b = input_coefficient();
    Coefficient c = input_coefficient();
    std::string error_msg = collect_error_msg(a, b, c);

    return CoefficientSet(a, b, c, error_msg);
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

std::string get_error_msg(const CoefficientSet &coeffs){
    return coeffs.error_msg;
}

bool is_valid(const CoefficientSet &coeffs){
    std::string error_msg = get_error_msg(coeffs);
    return error_msg == EMPTY_ERROR_MSG;
}
