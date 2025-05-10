#include "coefficients.hpp"
#include "constants.cpp"
#include "constants.hpp"
#include "error.hpp"
#include "number.hpp"
#include "solution.hpp"

Solution make_solution( const SolutionType& type,
                        const Number& first_root,
                        const Number& second_root,
                        const Error& error = Errors::OK ) {
    return Solution( type, first_root, second_root, error );
}

Solution make_error_solution( const Error& error ) {
    return make_solution( SolutionType::NO_ROOTS,
                          SolutionNumbers::ZERO,
                          SolutionNumbers::ZERO,
                          error );
}

Solution make_inf_roots_solution() {
    return make_solution(
        SolutionType::INF_ROOTS, SolutionNumbers::ZERO, SolutionNumbers::ZERO );
}

Solution make_no_roots_solution() {
    return make_solution(
        SolutionType::NO_ROOTS, SolutionNumbers::ZERO, SolutionNumbers::ZERO );
}

Solution make_single_root_solution( const Number& root ) {
    return make_solution(
        SolutionType::SINGLE_ROOT, root, SolutionNumbers::ZERO );
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

    return is_equal( a, SolutionNumbers::ZERO ) &&
           is_equal( b, SolutionNumbers::ZERO ) &&
           is_equal( c, SolutionNumbers::ZERO );
}

bool has_no_roots( const Coefficients& nums ) {
    Number a = get_a( nums );
    Number b = get_b( nums );
    Number c = get_c( nums );

    return is_equal( a, SolutionNumbers::ZERO ) &&
           is_equal( b, SolutionNumbers::ZERO ) &&
           !is_equal( c, SolutionNumbers::ZERO );
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
    Number semi_disc = mul( SolutionNumbers::FOUR, mul( a, c ) );

    return sub( square_b, semi_disc );
}

Number compute_second_root( const Coefficients& nums ) {
    Number a = get_a( nums );
    Number neg_b = neg( get_b( nums ) );
    Number disc = compute_discriminant( nums );
    Number disc_root = sqrt( disc );
    Number two_a = mul( SolutionNumbers::TWO, a );

    return div( sub( neg_b, disc_root ), two_a );
}

Number compute_first_root( const Coefficients& nums ) {
    Number neg_b = neg( get_b( nums ) );
    Number disc = compute_discriminant( nums );
    Number disc_root = sqrt( disc );
    Number two_a = mul( SolutionNumbers::TWO, get_a( nums ) );

    return div( add( neg_b, disc_root ), two_a );
}

Solution solve_quadratic_equation( const Coefficients& nums ) {
    if ( is_lower_than( compute_discriminant( nums ),
                        SolutionNumbers::ZERO ) ) {
        return make_error_solution( SolutionErrors::DISCRIMINANT_BELOW_ZERO );
    }

    Number x1 = compute_first_root( nums );
    Number x2 = compute_second_root( nums );

    return make_two_roots_solution( x1, x2 );
}

bool is_quadratic_equation( const Coefficients& nums ) {
    return !is_equal( get_a( nums ), SolutionNumbers::ZERO );
}

bool has_error( const Coefficients& nums ) {
    Error error = get_error( nums );
    return !is_ok( error );
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

const SolutionType& get_solution_type( const Solution& solution ) {
    return solution.type;
}

const Number& get_first_root( const Solution& solution ) { return solution.x1; }

const Number& get_second_root( const Solution& solution ) {
    return solution.x2;
}

const Error& get_error( const Solution& solution ) { return solution.error; }

bool has_two_roots( const Solution& solution ) {
    return get_solution_type( solution ) == SolutionType::TWO_ROOTS; // change to `is_equal`
}

bool has_two_same_roots( const Solution& solution ) {
    return get_solution_type( solution ) == SolutionType::TWO_SAME_ROOTS;  // change to `is_equal`
}

bool has_single_root( const Solution& solution ) {
    return get_solution_type( solution ) == SolutionType::SINGLE_ROOT;  // change to `is_equal`
}

bool has_no_roots( const Solution& solution ) {
    return get_solution_type( solution ) == SolutionType::NO_ROOTS;  // change to `is_equal`
}

bool has_inf_roots( const Solution& solution ) {
    return get_solution_type( solution ) == SolutionType::INF_ROOTS; // change to `is_equal`
}
