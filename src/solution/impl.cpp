#include "coefficients.hpp"
#include "constants.cpp"
#include "error.hpp"
#include "number.hpp"
#include "solution.hpp"

bool has_error( const Coefficients& nums ) {
    Error error = get_error( nums );
    return !is_ok( error );
}

bool is_quadratic_equation( const Coefficients& nums ) {
    return !is_equal( get_a( nums ), SolutionNumbers::ZERO );
}

Number get_discriminant( const Coefficients& nums ) {
    Number a = get_a( nums );
    Number b = get_b( nums );
    Number c = get_c( nums );
    Number square_b = mul( b, b );
    Number semi_disc = mul( mul( SolutionNumbers::FOUR, a ), c );

    return sub( square_b, semi_disc );
}

Number get_first_root( const Coefficients& nums ) {
    Number neg_b = neg( get_b( nums ) );
    Number disc = get_discriminant( nums );
    Number disc_root = sqrt( disc );
    Number two_a = mul( SolutionNumbers::TWO, get_a( nums ) );

    return div( add( neg_b, disc_root ), two_a );
}

Number get_second_root( const Coefficients& nums ) {
    Number a = get_a( nums );
    Number neg_b = neg( get_b( nums ) );
    Number disc = get_discriminant( nums );
    Number disc_root = sqrt( disc );
    Number two_a = mul( SolutionNumbers::TWO, a );

    return div( sub( neg_b, disc_root ), two_a );
}

bool has_no_roots( const Coefficients& nums ) {
    Number a = get_a( nums );
    Number b = get_b( nums );
    Number c = get_c( nums );

    return is_equal( a, SolutionNumbers::ZERO ) &&
           is_equal( b, SolutionNumbers::ZERO ) &&
           !is_equal( c, SolutionNumbers::ZERO );
}

bool has_inf_roots( const Coefficients& nums ) {
    Number a = get_a( nums );
    Number b = get_b( nums );
    Number c = get_c( nums );

    return is_equal( a, SolutionNumbers::ZERO ) &&
           is_equal( b, SolutionNumbers::ZERO ) &&
           is_equal( c, SolutionNumbers::ZERO );
}

Solution solve_quadratic_equation( const Coefficients& nums ) {
    if ( is_lower_than( get_discriminant( nums ), SolutionNumbers::ZERO ) ) {
        return make_solution( SolutionType::NO_ROOTS,
                              SolutionNumbers::ZERO,
                              SolutionNumbers::ZERO,
                              SolutionErrors::DISCRIMINANT_BELOW_ZERO );
    }

    Number x1 = get_first_root( nums );
    Number x2 = get_second_root( nums );

    if ( is_equal( x1, x2 ) ) {
        return make_solution(
            SolutionType::SINGLE_ROOT, x1, SolutionNumbers::ZERO );
    }

    return make_solution( SolutionType::TWO_ROOTS, x1, x2 );
}

Number get_single_root( const Coefficients& nums ) {
    Number b = get_b( nums );
    Number neg_c = neg( get_c( nums ) );

    return div( neg_c, b );
}

Solution solve_linear_equation( const Coefficients& nums ) {
    if ( has_no_roots( nums ) ) {
        return make_solution( SolutionType::NO_ROOTS,
                              SolutionNumbers::ZERO,
                              SolutionNumbers::ZERO );
    }

    else if ( has_inf_roots( nums ) ) {
        return make_solution( SolutionType::INF_ROOTS,
                              SolutionNumbers::ZERO,
                              SolutionNumbers::ZERO );
    }

    return make_solution( SolutionType::SINGLE_ROOT,
                          get_single_root( nums ),
                          SolutionNumbers::ZERO );
}

Solution make_solution( const SolutionType& type,
                        const Number& first_root,
                        const Number& second_root,
                        const Error& error ) {
    return Solution( type, first_root, second_root, error );
}

Solution solve_equation( const Coefficients& coeffs ) {
    if ( has_error( coeffs ) ) {
        return make_solution( SolutionType::NO_ROOTS,
                              SolutionNumbers::ZERO,
                              SolutionNumbers::ZERO,
                              SolutionErrors::INVALID_NUMBER_KIT );
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
