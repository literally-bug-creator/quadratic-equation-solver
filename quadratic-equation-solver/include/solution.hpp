#pragma once

#include <vector>

#include "numbers.hpp"

enum SolutionType {
    TWO_ROOTS,
    TWO_SAME_ROOTS,
    SINGLE_ROOT,
    NO_ROOTS,
    INF_ROOTS
};

struct Solution {
    SolutionType type;
    Numbers x1;
    Numbers x2;
    Error error;
};

const Solution make_solution( const SolutionType& type,
                              const Numbers& first_root,
                              const Numbers& second_root,
                              const Error& error = Errors::OK );

const Error& get_error( const Solution& solution );

const SolutionType& get_solution_type( const Solution& solution );

std::vector<Numbers> get_roots( const Solution& solution );
