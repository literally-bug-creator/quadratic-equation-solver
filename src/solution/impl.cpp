#include "constants.cpp"
#include "equation_coefficients.hpp"
#include "error.hpp"
#include "number.hpp"
#include "solution.hpp"

bool has_null( const EquationCoefficients& coeffs ) {
    Number a = get_a( coeffs );
    Number b = get_b( coeffs );
    Number c = get_c( coeffs );

    return is_null( a ) || is_null( b ) || is_null( c );
}

bool has_error( const EquationCoefficients& nums ) {
    Error error = get_error( nums );
    ErrorCode code = get_error_code( error );

    return code != ErrorCode::OK;
}

bool is_valid( const EquationCoefficients& nums ) {
    return !( has_error( nums ) || has_null( nums ) );
}

bool is_quadratic_equation( const EquationCoefficients& nums ) {
    return !is_equal( get_a( nums ), SolutionNumbers::ZERO );
}

Number get_discriminant( const EquationCoefficients& nums ) {
    Number a = get_a( nums );
    Number b = get_b( nums );
    Number c = get_c( nums );
    Number square_b = mul( b, b );
    Number semi_disc = mul( mul( SolutionNumbers::FOUR, a ), c );

    return sub( square_b, semi_disc );
}

Number get_first_root( const EquationCoefficients& nums ) {
    Number neg_b = neg( get_b( nums ) );
    Number disc = get_discriminant( nums );
    Number disc_root = sqrt( disc );
    Number two_a = mul( SolutionNumbers::TWO, get_a( nums ) );

    return div( add( neg_b, disc_root ), two_a );
}

Number get_second_root( const EquationCoefficients& nums ) {
    Number a = get_a( nums );
    Number neg_b = neg( get_b( nums ) );
    Number disc = get_discriminant( nums );
    Number disc_root = sqrt( disc );
    Number two_a = mul( SolutionNumbers::TWO, a );

    return div( sub( neg_b, disc_root ), two_a );
}

bool has_no_roots( const EquationCoefficients& nums ) {
    Number a = get_a( nums );
    Number b = get_b( nums );
    Number c = get_c( nums );

    return is_equal( a, SolutionNumbers::ZERO ) &&
           is_equal( b, SolutionNumbers::ZERO ) &&
           !is_equal( c, SolutionNumbers::ZERO );
}

bool has_inf_roots( const EquationCoefficients& nums ) {
    Number a = get_a( nums );
    Number b = get_b( nums );
    Number c = get_c( nums );

    return is_equal( a, SolutionNumbers::ZERO ) &&
           is_equal( b, SolutionNumbers::ZERO ) &&
           is_equal( c, SolutionNumbers::ZERO );
}

Solution solve_quadratic_equation( const EquationCoefficients& nums ) {
    if ( is_lower_than( get_discriminant( nums ), SolutionNumbers::ZERO ) ) {
        return make_solution( NO_ROOTS,
                              SolutionNumbers::NUL,
                              SolutionNumbers::NUL,
                              SolutionErrors::DISCRIMINANT_BELOW_ZERO );
    }

    Number x1 = get_first_root( nums );
    Number x2 = get_second_root( nums );

    if ( is_equal( x1, x2 ) ) {
        return make_solution(
            SolutionType::SINGLE_ROOT, x1, SolutionNumbers::NUL );
    }

    return make_solution( SolutionType::TWO_ROOTS, x1, x2 );
}

Number get_single_root( const EquationCoefficients& nums ) {
    Number b = get_b( nums );
    Number neg_c = neg( get_c( nums ) );

    return div( neg_c, b );
}

Solution solve_linear_equation( const EquationCoefficients& nums ) {
    if ( has_no_roots( nums ) ) {
        return make_solution( SolutionType::NO_ROOTS,
                              SolutionNumbers::NUL,
                              SolutionNumbers::NUL );
    }

    else if ( has_inf_roots( nums ) ) {
        return make_solution( SolutionType::INF_ROOTS,
                              SolutionNumbers::NUL,
                              SolutionNumbers::NUL );
    }

    return make_solution( SolutionType::SINGLE_ROOT,
                          get_single_root( nums ),
                          SolutionNumbers::NUL );
}

Solution make_solution( const SolutionType& type,
                        const Number& first_root,
                        const Number& second_root,
                        const Error& error ) {
    return Solution( type, first_root, second_root, error );
}

Solution get_solution( const EquationCoefficients& nums ) {
    if ( !is_valid( nums ) ) {
        return make_solution( SolutionType::NO_ROOTS,
                              SolutionNumbers::NUL,
                              SolutionNumbers::NUL,
                              SolutionErrors::INVALID_NUMBER_KIT );
    }

    if ( is_quadratic_equation( nums ) ) {
        return solve_quadratic_equation( nums );
    }

    return solve_linear_equation( nums );
}

SolutionType get_solution_type( const Solution& solution ) {
    return solution.type;
}

Number get_first_root( const Solution& solution ) { return solution.x1; }

Number get_second_root( const Solution& solution ) { return solution.x2; }

Error get_error( const Solution& solution ) { return solution.error; }
