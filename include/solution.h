#pragma once

#include <string>
#include "coefficient.h"
#include "coefficient_set.h"

enum SolutionType{
    QUADRATIC,
    LINEAR,
    NO_ROOTS,
    ANY_ROOT,
};

struct Solution{
    const SolutionType type;
    const Coefficient x1;
    const Coefficient x2;
    const std::string error_msg;

    Solution(
        const SolutionType &type,
        const Coefficient &x1,
        const Coefficient &x2,
        const std::string &error_msg = EMPTY_ERROR_MSG
    ): type(type), x1(x1), x2(x2), error_msg(error_msg) {}
};

SolutionType get_solution_type(const Solution &solution);

Coefficient get_first_root(const Solution &solution);

Coefficient get_second_root(const Solution &solution);

std::string get_error_msg(const Solution &solution);

bool is_valid(const Solution &solution);

Solution get_solution(const CoefficientSet &coeffs);
