#include "../include/solution.h"
#include <bits/types/error_t.h>
#include <string>


std::string get_error_msg(const Solution &solution){
    return solution.error_msg;
}

bool is_valid(const Solution &solution){
    std::string error_msg = get_error_msg(solution);

    return error_msg == EMPTY_ERROR_MSG;
}

SolutionType get_solution_type(const Solution &solution){
    return solution.type;
}

Coefficient get_x1(const Solution &solution){
    return solution.x1;
}

Coefficient get_x2(const Solution &solution){
    return solution.x2;
}

bool is_linear_equation(const CoefficientSet &coeffs){

}

bool is_quadratic_equation(const CoefficientSet &coeffs){

}

bool is_no_solution(const CoefficientSet &coeffs){
    Coefficient c = get_c(coeffs);
    Coefficient zero = get_zero();

    return !is_equal(c, zero);
}

Solution solve_linear_equation(const CoefficientSet &coeffs){

}

Solution solve_quadratic_equation(const CoefficientSet &coeffs){

}

Solution get_invalid_solution(const std::string &error_msg){
    SolutionType type = NO_ROOTS;
    Coefficient x1 = get_invalid_coefficient();
    Coefficient x2 = get_invalid_coefficient();

    return Solution(type, x1, x2, error_msg);
}

Solution get_any_root_solution(){
    SolutionType type = ANY_ROOT;
    Coefficient x1 = get_invalid_coefficient();
    Coefficient x2 = get_invalid_coefficient();

    return Solution(type, x1, x2, EMPTY_ERROR_MSG);
}

Solution get_no_solution(){
    SolutionType type = NO_ROOTS;
    Coefficient x1 = get_invalid_coefficient();
    Coefficient x2 = get_invalid_coefficient();

    return Solution(type, x1, x2, EMPTY_ERROR_MSG);
}

Solution get_solution(const CoefficientSet &coeffs){
    if (!is_valid(coeffs)){
        std::string error_msg = get_error_msg(coeffs);
        return get_invalid_solution(error_msg);
    }

    if (is_quadratic_equation(coeffs)){
        return solve_quadratic_equation(coeffs);
    }

    if (is_linear_equation(coeffs)){
        return solve_linear_equation(coeffs);
    }

    if (is_no_solution(coeffs)){
        return get_no_solution();
    }

    return get_any_root_solution();
}
