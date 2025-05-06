#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <array>
#include <random>

#include "../include/constants.hpp"
#include "../include/error.hpp"
#include "../include/number.hpp"

const int MIN_INT = -10000;
const int ZERO = 0;
const int MAX_INT = 10000;
const int ERROR_CODES_AMOUNT = 4;

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
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::uniform_int_distribution<> dist( min, max );
    return dist( gen );
}

inline double random_double( double min, double max ) {
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::uniform_real_distribution<> dist( min, max );
    return dist( gen );
}

inline std::array<ErrorCode, ERROR_CODES_AMOUNT> get_all_error_codes() {
    return { ErrorCode::OK,
             ErrorCode::INVALID_INPUT,
             ErrorCode::CALCULATION_ERROR,
             ErrorCode::SOLUTION_ERROR };
}

inline ErrorCode random_error_code() {
    ErrorCode code =
        get_all_error_codes()[random_int( ZERO, ERROR_CODES_AMOUNT - 1 )];
    return code;
}

inline Error random_error() {
    ErrorCode code = random_error_code();
    std::string msg = random_string( random_int( ZERO, MAX_INT ) );
    return make_error( code, msg );
}

inline Number random_number() {
    Error error = random_error();
    double value = random_double( MIN_INT, MAX_INT );

    return make_number( value, error );
}

inline Number random_number_lt_zero() {
    Error error = random_error();
    double value = random_double( MIN_INT, ZERO - 1 );

    return make_number( value, error );
}

inline Number random_number_ge_zero() {
    Error error = random_error();
    double value = random_double( ZERO, MAX_INT );

    return make_number( value, error );
}

inline Number random_number_ne_zero() {
    Error error = random_error();
    double value = random_double( MIN_INT, MAX_INT );

    if (value == 0){
        value += 1;
    }

    return make_number( value, error );
}
