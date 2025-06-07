#include <gtest/gtest.h>

#include "big_number.hpp"
#include "coefficients.hpp"
#include "number.hpp"
#include "solution.hpp"
#include "solver.hpp"

const int TESTS_AMOUNT = 10000;

TEST( TestEquationSolver, SingleRoot ) {
    big_number::BigNumber first_v = big_number::make_big_number( "0" );
    big_number::BigNumber second_v = big_number::make_big_number( "2" );
    big_number::BigNumber third_v = big_number::make_big_number( "4" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber root_v = big_number::make_big_number( "-2" );
    Number root = make_number( root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::SINGLE_ROOT );
    EXPECT_EQ( is_equal( get_roots( solution )[0], root ), true );
}

TEST( TestEquationSolver, InfRoots ) {
    big_number::BigNumber first_v = big_number::make_big_number( "0" );
    big_number::BigNumber second_v = big_number::make_big_number( "0" );
    big_number::BigNumber third_v = big_number::make_big_number( "0" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber root_v = big_number::make_big_number( "0" );
    Number root = make_number( root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::INF_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], root ), true );
}

TEST( TestEquationSolver, NoRoots ) {
    big_number::BigNumber first_v = big_number::make_big_number( "0" );
    big_number::BigNumber second_v = big_number::make_big_number( "0" );
    big_number::BigNumber third_v = big_number::make_big_number( "5" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber root_v = big_number::make_big_number( "0" );
    Number root = make_number( root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::NO_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], root ), true );
}

TEST( TestEquationSolver, NoRoots2 ) {
    big_number::BigNumber first_v = big_number::make_big_number( "0" );
    big_number::BigNumber second_v = big_number::make_big_number( "0" );
    big_number::BigNumber third_v = big_number::make_big_number( "9" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber root_v = big_number::make_big_number( "0" );
    Number root = make_number( root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::NO_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], root ), true );
}

TEST( TestEquationSolver, TwoRoots ) {
    big_number::BigNumber first_v = big_number::make_big_number( "1" );
    big_number::BigNumber second_v = big_number::make_big_number( "-5" );
    big_number::BigNumber third_v = big_number::make_big_number( "6" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "3" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "2" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], first_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], second_root ), true );
}

TEST( TestEquationSolver, TwoRoots2 ) {
    big_number::BigNumber first_v = big_number::make_big_number( "1" );
    big_number::BigNumber second_v = big_number::make_big_number( "0" );
    big_number::BigNumber third_v = big_number::make_big_number( "-4" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "2" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "-2" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], first_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], second_root ), true );
}

TEST( TestEquationSolver, TwoRoots3 ) {
    big_number::BigNumber first_v = big_number::make_big_number( "1" );
    big_number::BigNumber second_v = big_number::make_big_number( "5" );
    big_number::BigNumber third_v = big_number::make_big_number( "6" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "-2" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "-3" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], first_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], second_root ), true );
}

TEST( TestEquationSolver, TwoRoots4 ) {
    big_number::BigNumber first_v = big_number::make_big_number( "2" );
    big_number::BigNumber second_v = big_number::make_big_number( "-3" );
    big_number::BigNumber third_v = big_number::make_big_number( "1" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "1" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "0.5" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], first_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], second_root ), true );
}

TEST( TestEquationSolver, TwoRoots5 ) {
    big_number::BigNumber first_v = big_number::make_big_number( "-1" );
    big_number::BigNumber second_v = big_number::make_big_number( "3" );
    big_number::BigNumber third_v = big_number::make_big_number( "4" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "4" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "-1" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], second_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], first_root ), true );
}

TEST( TestEquationSolver, TwoRoots6 ) {
    big_number::BigNumber first_v = big_number::make_big_number( "-2" );
    big_number::BigNumber second_v = big_number::make_big_number( "-3" );
    big_number::BigNumber third_v = big_number::make_big_number( "-1" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "-0.5" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "-1" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], second_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], first_root ), true );
}

TEST( TestEquationSolver, TwoSameRoots ) {
    big_number::BigNumber first_v = big_number::make_big_number( "1" );
    big_number::BigNumber second_v = big_number::make_big_number( "-4" );
    big_number::BigNumber third_v = big_number::make_big_number( "4" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "2" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "2" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_SAME_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], second_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], first_root ), true );
}

TEST( TestEquationSolver, TwoSameRoots2 ) {
    big_number::BigNumber first_v = big_number::make_big_number( "1" );
    big_number::BigNumber second_v = big_number::make_big_number( "0" );
    big_number::BigNumber third_v = big_number::make_big_number( "0" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "0" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "0" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_SAME_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], second_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], first_root ), true );
}

TEST( TestEquationSolver, TwoSameRoots3 ) {
    big_number::BigNumber first_v = big_number::make_big_number( "1" );
    big_number::BigNumber second_v = big_number::make_big_number( "6" );
    big_number::BigNumber third_v = big_number::make_big_number( "9" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "-3" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "-3" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_SAME_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], second_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], first_root ), true );
}

TEST( TestEquationSolver, TwoSameRoots4 ) {
    big_number::BigNumber first_v = big_number::make_big_number( "4" );
    big_number::BigNumber second_v = big_number::make_big_number( "-4" );
    big_number::BigNumber third_v = big_number::make_big_number( "1" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "0.5" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "0.5" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_SAME_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], second_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], first_root ), true );
}

TEST( TestEquationSolver, TwoSameRoots5 ) {
    big_number::BigNumber first_v = big_number::make_big_number( "0.001" );
    big_number::BigNumber second_v = big_number::make_big_number( "0.002" );
    big_number::BigNumber third_v = big_number::make_big_number( "0.001" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "-1" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "-1" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_SAME_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], second_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], first_root ), true );
}

TEST( TestEquationSolver, BEqualZero ) {
    big_number::BigNumber first_v = big_number::make_big_number( "4" );
    big_number::BigNumber second_v = big_number::make_big_number( "0" );
    big_number::BigNumber third_v = big_number::make_big_number( "-16" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "2" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "-2" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], first_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], second_root ), true );
}

TEST( TestEquationSolver, CEqualZero ) {
    big_number::BigNumber first_v = big_number::make_big_number( "2" );
    big_number::BigNumber second_v = big_number::make_big_number( "8" );
    big_number::BigNumber third_v = big_number::make_big_number( "0" );
    Number first = make_number( first_v );
    Number second = make_number( second_v );
    Number third = make_number( third_v );
    Coefficients coeffs = make_coefficients( first, second, third );
    big_number::BigNumber first_root_v = big_number::make_big_number( "0" );
    big_number::BigNumber second_root_v = big_number::make_big_number( "-4" );

    Number first_root = make_number( first_root_v );
    Number second_root = make_number( second_root_v );

    Solution solution = solve_equation( coeffs );

    EXPECT_EQ( get_solution_type( solution ), SolutionType::TWO_ROOTS );
    EXPECT_EQ( is_equal( get_roots( solution )[0], first_root ), true );
    EXPECT_EQ( is_equal( get_roots( solution )[1], second_root ), true );
}
