#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <random>

#include "../include/error.hpp"
#include "../include/number.hpp"
#include "../include/number_kit.hpp"
#include "../include/solution.hpp"

const int MIN_INT = 0;
const int MIN_NEG_INT = -10000;
const int MAX_INT = 100;
const int TESTS_AMOUNT = 10000;
const int ERROR_CODES_AMOUNT = 4;
const int SOLUTION_TYPES_AMOUNT = 4;

inline std::string random_string( size_t length ) {
    const std::string chars = "abcdefghijklmnopqrstuvwxyz"
                              "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "0123456789";

    std::random_device rd;
    std::mt19937 gen( rd() );
    std::uniform_int_distribution<> dist( 0, chars.size() - 1 );

    std::string result;
    result.reserve( length );
    for ( size_t i = 0; i < length; ++i ) {
        result += chars[dist( gen )];
    }

    return result;
}

inline int random_int( int min, int max ) {
    std::random_device rd;
    std::mt19937 gen( rd() );
    std::uniform_int_distribution<> dist( min, max );

    return dist( gen );
}

inline double random_double( double min, double max ) {
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::uniform_real_distribution<double> dist( min, max );
    return dist( gen );
}

inline ErrorCode random_error_code() {
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::uniform_int_distribution<int> dist( 0, ERROR_CODES_AMOUNT - 1 );
    return static_cast<ErrorCode>( dist( gen ) );
}

inline Error random_error() {
    std::string msg = random_string( MAX_INT );
    ErrorCode code = random_error_code();
    return make_error( code, msg );
}

inline Number random_number() {
    double value = random_double( MIN_NEG_INT, MAX_INT );
    return make_number( value );
}

inline Number random_number( int min, int max ) {
    double value = random_double( min, max );
    return make_number( value );
}

inline NumberKit random_number_kit() {
    Number a = random_number();
    Number b = random_number();
    Number c = random_number();

    return make_number_kit( a, b, c );
}

inline SolutionType random_solution_type() {
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::uniform_int_distribution<int> dist( 0, SOLUTION_TYPES_AMOUNT - 1 );
    return static_cast<SolutionType>( dist( gen ) );
}

inline Solution random_solution() {
    SolutionType type = random_solution_type();
    Number x1 = random_number();
    Number x2 = random_number();
    Error error = random_error();

    return make_solution( type, x1, x2, error );
}

inline Solution random_two_roots_solution() {
    Number a = random_number();
    Number c = random_number();
    double min_b = mul( mul( make_number( 4 ), a ), c ).value;
    double max_b = std::abs( min_b ) * 2;
    Number b = random_number( min_b, max_b );
    NumberKit kit = make_number_kit( a, b, c );

    return get_solution( kit );
}

inline Solution random_single_root_solution() {
    Number a = random_number();
    Number c = random_number();
    double b_value = sqrt( mul( mul( make_number( 4 ), a ), c ).value );
    Number b = make_number( b_value );
    NumberKit kit = make_number_kit( a, b, c );

    return get_solution( kit );
}

inline Solution random_linear_solution() {
    Number a = make_number( 0 );
    Number b = random_number();
    Number c = make_number( random_double( MIN_INT, MAX_INT ) + 1 );
    NumberKit kit = make_number_kit( a, b, c );

    return get_solution( kit );
}

inline Solution random_no_roots_solution() {
    Number a = random_number();
    Number c = random_number();
    double max_b = mul( mul( make_number( 4 ), a ), c ).value - 1;
    double min_b = max_b - random_double( MIN_INT, MAX_INT );
    Number b = random_number( min_b, max_b );
    NumberKit kit = make_number_kit( a, b, c );

    return get_solution( kit );
}
