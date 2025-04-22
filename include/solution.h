#pragma once

#include <string>
#include "coefficient.h"
#include "coefficient_set.h"

enum SolutionType{
    TWO_ROOTS,
    ONE_ROOT,
    NO_ROOTS,
    INF_ROOTS,
};

struct Solution{
    const Coefficient x1;
    const Coefficient x2;
    const SolutionType type;
    const std::string error_msg;
};

Solution get_solution(const CoefficientSet &coeffs);

Coefficient get_x1(const Solution &solution);

Coefficient get_x2(const Solution &solution);

SolutionType get_solution_type(const Solution &solution);

bool has_error(const CoefficientSet &solution);

std::string get_error_msg(const CoefficientSet &solution);
