#pragma once

#include "equation_coefficients.hpp"
#include "number.hpp"

enum SolutionType { // TODO: Обдумать состояния
    TWO_ROOTS,
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

Solution make_solution(
    const SolutionType& type,
    const Number& first_root,
    const Number& second_root,
    const Error& error = Errors::DEFAULT_ERROR ); // Rethink error name

Solution get_solution( const EquationCoefficients& coeffs ); // TODO: Rename

const SolutionType& get_solution_type( const Solution& solution );

const Number& get_first_root( const Solution& solution );

const Number& get_second_root( const Solution& solution );

const Error& get_error( const Solution& solution );
