#include "coefficients.hpp"
#include "complex_number.hpp"
#include "constants.cpp"
#include "number.hpp"
#include "numbers.hpp"
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

Solution make_two_roots_solution( const Numbers& x1, const Numbers& x2 ) {
    if ( is_equal( x1, x2 ) )
        return make_solution( SolutionType::TWO_SAME_ROOTS, x1, x2 );

    return make_solution( SolutionType::TWO_ROOTS, x1, x2 );
}

Number compute_single_root( const Coefficients& coeffs ) {
    return div( neg( get_c( coeffs ) ), get_b( coeffs ) );
}

bool has_inf_roots( const Coefficients& nums ) {
    const Number& a = get_a( nums );
    const Number& b = get_b( nums );
    const Number& c = get_c( nums );

    return is_equal( a, SolverNumbers::ZERO ) &&
           is_equal( b, SolverNumbers::ZERO ) &&
           is_equal( c, SolverNumbers::ZERO );
}

bool has_no_roots( const Coefficients& nums ) {
    const Number& a = get_a( nums );
    const Number& b = get_b( nums );
    const Number& c = get_c( nums );

    return is_equal( a, SolverNumbers::ZERO ) &&
           is_equal( b, SolverNumbers::ZERO ) &&
           !is_equal( c, SolverNumbers::ZERO );
}

bool is_quadratic_equation( const Coefficients& nums ) {
    return !is_equal( get_a( nums ), SolverNumbers::ZERO );
}

bool has_error( const Coefficients& nums ) {
    const Error& error = get_error( nums );
    return !is_ok( error );
}

Solution solve_linear_equation( const Coefficients& coeffs ) {
    if ( has_no_roots( coeffs ) )
        return make_no_roots_solution();

    else if ( has_inf_roots( coeffs ) )
        return make_inf_roots_solution();

    Number x = compute_single_root( coeffs );
    return make_single_root_solution( x );
}

Number compute_discriminant( const Coefficients& nums ) {
    const Number& a = get_a( nums );
    const Number& b = get_b( nums );
    const Number& c = get_c( nums );
    Number sqr_b = mul( b, b );
    Number correctibe_term = mul( SolverNumbers::FOUR, mul( a, c ) );

    return sub( sqr_b, correctibe_term );
}

Numbers compute_second_root( const Coefficients& nums ) {
    Number neg_b = neg( get_b( nums ) );
    Number disc = compute_discriminant( nums );
    Number double_a = mul( SolverNumbers::TWO, get_a( nums ) );

    if ( is_lower_than( disc, SolverNumbers::ZERO ) ) {
        Number imaginary_part = neg( div( sqrt( neg( disc ) ), double_a ) );
        Number real_part = div( neg_b, double_a );

        return make_complex_number( real_part, imaginary_part );
    }

    return div( sub( neg_b, sqrt( disc ) ), double_a );
}

Numbers compute_first_root( const Coefficients& nums ) {
    Number neg_b = neg( get_b( nums ) );
    Number disc = compute_discriminant( nums );
    Number double_a = mul( SolverNumbers::TWO, get_a( nums ) );

    if ( is_lower_than( disc, SolverNumbers::ZERO ) ) {
        Number imaginary_part = div( sqrt( neg( disc ) ), double_a );
        Number real_part = div( neg_b, double_a );

        return make_complex_number( real_part, imaginary_part );
    }

    return div( add( neg_b, sqrt( disc ) ), double_a );
}

Solution solve_quadratic_equation( const Coefficients& nums ) {
    Numbers x1 = compute_first_root( nums );
    Numbers x2 = compute_second_root( nums );

    return make_two_roots_solution( x1, x2 );
}

Solution solve_equation( const Coefficients& coeffs ) {
    if ( has_error( coeffs ) )
        return make_error_solution( get_error( coeffs ) );

    if ( is_quadratic_equation( coeffs ) )
        return solve_quadratic_equation( coeffs );

    return solve_linear_equation( coeffs );
}
