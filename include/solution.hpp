#pragma once
#include "number.hpp"

enum SolutionType {
    TWO_ROOTS,
    TWO_SAME_ROOTS,
    SINGLE_ROOT,
    NO_ROOTS,
    INF_ROOTS
};

using Solution =
    std::pair<std::pair<SolutionType, Number>, std::pair<Number, Error>>;

const Solution make_solution( const SolutionType& type,
                              const Number& first_root,
                              const Number& second_root,
                              const Error& error = Errors::OK );

const Error get_error( const Solution& solution );

SolutionType get_solution_type( const Solution& solution );

const Number get_first_root( const Solution& solution );

const Number get_second_root( const Solution& solution );

bool has_two_roots( const Solution& solution );

bool has_two_same_roots( const Solution& solution );

bool has_single_root( const Solution& solution );

bool has_no_roots( const Solution& solution );

bool has_inf_roots( const Solution& solution );
