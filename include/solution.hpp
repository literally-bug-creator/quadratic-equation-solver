#pragma once

#include "coefficients.hpp"
#include "number.hpp"

enum SolutionType {
    TWO_ROOTS,
    TWO_SAME_ROOTS,
    SINGLE_ROOT,
    NO_ROOTS,
    INF_ROOTS
};

struct Solution {
    const SolutionType type;
    const Number x1;
    const Number x2;
    const Error error;

    Solution( const SolutionType& type,
              const Number& x1,
              const Number& x2,
              const Error& error ):
        type( type ), x1( x1 ), x2( x2 ), error( error ) {}
};

const Error& get_error( const Solution& solution );

const SolutionType& get_solution_type( const Solution& solution );

const Number& get_first_root( const Solution& solution );

const Number& get_second_root( const Solution& solution );

bool has_two_roots( const Solution& solution );

bool has_two_same_roots( const Solution& solution );

bool has_single_root( const Solution& solution );

bool has_no_roots( const Solution& solution );

bool has_inf_roots( const Solution& solution );

Solution solve_equation( const Coefficients& coeffs ); // Вынести решение в отдельную сущность
