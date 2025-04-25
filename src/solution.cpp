#include "../include/solution.h"

const std::string DISCRIMINANT_BELOW_ZERO_MSG = "Дискриминант меньше нуля.";


SolutionType get_solution_type(const Solution &solution){
    return solution.type;
}

Coefficient get_first_root(const Solution &solution){
    return solution.x1;
}

Coefficient get_second_root(const Solution &solution){
    return solution.x2;
}

std::string get_error_msg(const Solution &solution){
    return solution.error_msg;
}

bool is_valid(const Solution &solution){
    std::string error_msg = get_error_msg(solution);

    return error_msg == EMPTY_ERROR_MSG;
}

Solution get_invalid_solution(const std::string &error_msg){
    SolutionType type = NO_ROOTS;
    Coefficient x1 = get_invalid_coefficient();
    Coefficient x2 = get_invalid_coefficient();

    return Solution(type, x1, x2, error_msg);
}

bool is_quadratic_equation(const CoefficientSet &coeffs){
    Coefficient a = get_a(coeffs);
    Coefficient b = get_b(coeffs);
    Coefficient zero = get_zero();

    return is_not_equal(a, zero);
}

Coefficient get_discriminant(const Coefficient &a, const Coefficient &b, const Coefficient &c){
    Coefficient square_b = mul(b, b);
    Coefficient four = get_four();
    Coefficient semi_discriminant = mul(mul(four, a), c);
    Coefficient discriminant = sub(square_b, semi_discriminant);

    return discriminant;
}

Coefficient get_x1(const Coefficient &a, const Coefficient &b, const Coefficient &discriminant){
    Coefficient two = get_two();
    Coefficient neg_b = neg(b);
    Coefficient discriminant_root = square_root(discriminant);
    Coefficient two_mul_a = mul(a, two);
    Coefficient x1 = div(add(neg_b, discriminant_root), two_mul_a);

    return x1;
}

Coefficient get_x2(const Coefficient &a, const Coefficient &b, const Coefficient &discriminant){
    Coefficient two = get_two();
    Coefficient neg_b = neg(b);
    Coefficient discriminant_root = square_root(discriminant);
    Coefficient two_mul_a = mul(a, two);
    Coefficient x2 = div(sub(neg_b, discriminant_root), two_mul_a);

    return x2;
}

Solution get_quadratic_solution(const Coefficient &x1, const Coefficient &x2){
    return Solution(QUADRATIC, x1, x2, EMPTY_ERROR_MSG);
}

Solution solve_quadratic_equation(const CoefficientSet &coeffs){
    Coefficient a = get_a(coeffs);
    Coefficient b = get_b(coeffs);
    Coefficient c = get_c(coeffs);
    Coefficient discriminant = get_discriminant(a, b, c);
    Coefficient zero = get_zero();

    if (is_lower_than(discriminant, zero)){
        return get_invalid_solution(DISCRIMINANT_BELOW_ZERO_MSG);
    }

    Coefficient x1 = get_x1(a, b, discriminant);
    Coefficient x2 = get_x2(a, b, discriminant);

    return get_quadratic_solution(x1, x2);
}

bool is_linear_equation(const CoefficientSet &coeffs){
    Coefficient a = get_a(coeffs);
    Coefficient b = get_b(coeffs);
    Coefficient zero = get_zero();

    return is_equal(a, zero) && is_not_equal(b, zero);
}

Solution get_linear_solution(const Coefficient &x){
    Coefficient x2 = get_invalid_coefficient();
    return Solution(LINEAR, x, x2, EMPTY_ERROR_MSG);
}

Solution solve_linear_equation(const CoefficientSet &coeffs){
    Coefficient b = get_b(coeffs);
    Coefficient c = get_c(coeffs);
    Coefficient x = neg(div(c, b));

    return get_linear_solution(x);
}

bool is_no_solution(const CoefficientSet &coeffs){
    Coefficient c = get_c(coeffs);
    Coefficient zero = get_zero();

    return is_not_equal(c, zero);
}

Solution get_no_solution(){
    SolutionType type = NO_ROOTS;
    Coefficient x1 = get_invalid_coefficient();
    Coefficient x2 = get_invalid_coefficient();

    return Solution(type, x1, x2, EMPTY_ERROR_MSG);
}

Solution get_any_root_solution(){
    SolutionType type = ANY_ROOT;
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
