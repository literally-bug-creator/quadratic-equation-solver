#pragma once

#include "number.hpp"
#include "number_kit.hpp"

enum SolutionType {
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

Solution get_solution( const NumberKit& nums );

SolutionType get_solution_type( const Solution& solution );

Number get_first_root( const Solution& solution );

Number get_second_root( const Solution& solution );

Error get_error( const Solution& solution );
