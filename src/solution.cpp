#include "../include/solution.h"

#include "../include/number.h"

namespace {
    const double ZERO_DOUBLE = 0;
    const double FOUR_DOUBLE = 4;
    const double TWO_DOUBLE = 4;
    const Number ZERO_NUMBER = make_number( ZERO_DOUBLE );
    const Number NULL_NUMBER = make_number( ZERO_DOUBLE, DEFAULT_ERROR, true );
    const Number FOUR_NUMBER = make_number( FOUR_DOUBLE );
    const Number TWO_NUMBER = make_number( TWO_DOUBLE );

    const std::string INVALID_NUMBER_KIT_MSG = "Некорректный набор чисел";

    const Error INVALID_NUMBER_KIT_ERROR =
        make_error( SOLUTION_ERROR, INVALID_NUMBER_KIT_MSG );

    bool has_null( const NumberKit& nums ) {
        Number a = get_a( nums );
        Number b = get_b( nums );
        Number c = get_c( nums );

        return is_null( a ) || is_null( b ) || is_null( c );
    }

    bool has_error( const NumberKit& nums ) {
        Error error = get_error( nums );

        return error.code != OK;
    }

    bool is_valid( const NumberKit& nums ) {
        return has_error( nums ) || has_null( nums );
    }

    bool is_quadratic_equation( const NumberKit& nums ) {
        if ( !is_valid( nums ) ) { return false; }

        return !is_equal( get_a( nums ), ZERO_NUMBER );
    }

    Number get_discriminant( const NumberKit& nums ) {
        Number a = get_a( nums );
        Number b = get_b( nums );
        Number c = get_c( nums );
        Number square_b = mul( b, b );
        Number semi_disc = mul( mul( FOUR_NUMBER, a ), c );

        return sub( square_b, semi_disc );
    }

    Number get_first_root( const NumberKit& nums, const Number& discriminant ) {
        Number a = get_a( nums );
        Number neg_b = neg( get_b( nums ) );
        Number neg_disc = neg( discriminant );
        Number two_a = mul( TWO_NUMBER, a );

        return div( add( neg_b, neg_disc ), two_a );
    }

    Number get_second_root( const NumberKit& nums,
                            const Number& discriminant ) {
        Number a = get_a( nums );
        Number neg_b = neg( get_b( nums ) );
        Number neg_disc = neg( discriminant );
        Number two_a = mul( TWO_NUMBER, a );

        return div( sub( neg_b, neg_disc ), two_a );
    }

    Solution make_solution( const SolutionType& type,
                            const Number& first_root,
                            const Number& second_root,
                            const Error& error ) {
        return Solution( type, first_root, second_root, error );
    }

    Solution solve_quadratic_equation( const NumberKit& nums ) {
        Number discriminant = get_discriminant( nums );

        Number x1 = get_first_root( nums, discriminant );
        Number x2 = get_second_root( nums, discriminant );

        return make_solution(
            TWO_ROOTS, x1, x2 ); // Подумать над валидацией корней
    }

    bool is_linear_equation( const NumberKit& nums ) {
        if ( !is_valid( nums ) ) { return false; }

        return is_equal( get_a( nums ), ZERO_NUMBER );
    }
}

Solution get_solution( const NumberKit& nums ) {
    if ( is_quadratic_equation( nums ) ) {
        return solve_quadratic_equation( nums );
    }

    else if ( is_linear_equation( nums ) ) {
        return solve_linear_equation( nums );
    }

    return make_solution(
        NO_SOLUTION, NULL_NUMBER, NULL_NUMBER, INVALID_NUMBER_KIT_ERROR );
}

SolutionType get_solution_type( const Solution& solution ) {
    return solution.type;
}

Number get_first_root( const Solution& solution ) { return solution.x1; }

Number get_second_root( const Solution& solution ) { return solution.x2; }

Error get_error( const Solution& solution ) { return solution.error; }
