#include "constants.cpp"
#include "solver.hpp"

Solution make_error_solution( const Error& error ) {
    return make_solution( SolutionType::NO_ROOTS,
                          SolverNumbers::ZERO,
                          SolverNumbers::ZERO,
                          error );
}

Solution make_inf_roots_solution() {
    return make_solution(
        SolutionType::INF_ROOTS, SolverNumbers::ZERO, SolverNumbers::ZERO );
}

Solution make_no_roots_solution() {
    return make_solution(
        SolutionType::NO_ROOTS, SolverNumbers::ZERO, SolverNumbers::ZERO );
}

Solution make_single_root_solution( const Number& root ) {
    return make_solution(
        SolutionType::SINGLE_ROOT, root, SolverNumbers::ZERO );
}

Solution make_two_roots_solution( const Number& x1, const Number& x2 ) {
    if ( is_equal( x1, x2 ) ) {
        return make_solution( SolutionType::TWO_SAME_ROOTS, x1, x2 );
    }

    return make_solution( SolutionType::TWO_ROOTS, x1, x2 );
}

Number compute_single_root( const Coefficients& coeffs ) {
    Number b = get_b( coeffs );
    Number neg_c = neg( get_c( coeffs ) );

    return div( neg_c, b );
}

bool has_inf_roots( const Coefficients& nums ) {
    Number a = get_a( nums );
    Number b = get_b( nums );
    Number c = get_c( nums );

    return is_equal( a, SolverNumbers::ZERO ) &&
           is_equal( b, SolverNumbers::ZERO ) &&
           is_equal( c, SolverNumbers::ZERO );
}

bool has_no_roots( const Coefficients& nums ) {
    Number a = get_a( nums );
    Number b = get_b( nums );
    Number c = get_c( nums );

    return is_equal( a, SolverNumbers::ZERO ) &&
           is_equal( b, SolverNumbers::ZERO ) &&
           !is_equal( c, SolverNumbers::ZERO );
}

bool is_quadratic_equation( const Coefficients& nums ) {
    return !is_equal( get_a( nums ), SolverNumbers::ZERO );
}

bool has_error( const Coefficients& nums ) {
    Error error = get_error( nums );
    return !is_ok( error );
}

Solution solve_linear_equation( const Coefficients& coeffs ) {
    if ( has_no_roots( coeffs ) ) {
        return make_no_roots_solution();
    }

    else if ( has_inf_roots( coeffs ) ) {
        return make_inf_roots_solution();
    }

    Number x = compute_single_root( coeffs );
    return make_single_root_solution( x );
}

Number compute_discriminant( const Coefficients& nums ) {
    Number a = get_a( nums );
    Number b = get_b( nums );
    Number c = get_c( nums );
    Number square_b = mul( b, b );
    Number semi_disc = mul( SolverNumbers::FOUR, mul( a, c ) );

    return sub( square_b, semi_disc );
}

Number compute_second_root( const Coefficients& nums ) {
    Number a = get_a( nums );
    Number neg_b = neg( get_b( nums ) );
    Number disc = compute_discriminant( nums );
    Number disc_root = sqrt( disc );
    Number two_a = mul( SolverNumbers::TWO, a );

    return div( sub( neg_b, disc_root ), two_a );
}

Number compute_first_root( const Coefficients& nums ) {
    Number neg_b = neg( get_b( nums ) );
    Number disc = compute_discriminant( nums );
    Number disc_root = sqrt( disc );
    Number two_a = mul( SolverNumbers::TWO, get_a( nums ) );

    return div( add( neg_b, disc_root ), two_a );
}

Solution solve_quadratic_equation( const Coefficients& nums ) {
    if ( is_lower_than( compute_discriminant( nums ), SolverNumbers::ZERO ) ) {
        return make_error_solution( SolverErrors::DISCRIMINANT_BELOW_ZERO );
    }

    Number x1 = compute_first_root( nums );
    Number x2 = compute_second_root( nums );

    return make_two_roots_solution( x1, x2 );
}

Solution solve_equation( const Coefficients& coeffs ) {
    if ( has_error( coeffs ) ) {
        return make_error_solution( get_error( coeffs ) );
    }

    if ( is_quadratic_equation( coeffs ) ) {
        return solve_quadratic_equation( coeffs );
    }

    return solve_linear_equation( coeffs );
}
