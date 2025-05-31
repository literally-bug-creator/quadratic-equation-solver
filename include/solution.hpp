#pragma once
#include "number.hpp"
#include <vector>

enum SolutionType {
    TWO_ROOTS,
    TWO_SAME_ROOTS,
    SINGLE_ROOT,
    NO_ROOTS,
    INF_ROOTS
};

struct Solution {
    SolutionType type;
    Number x1;
    Number x2;
    Error error;
};

const Solution make_solution( const SolutionType& type,
                              const Number& first_root,
                              const Number& second_root,
                              const Error& error = Errors::OK );

const Error& get_error( const Solution& solution );

const SolutionType& get_solution_type( const Solution& solution );

std::vector<Number> get_roots( const Solution& solution );
