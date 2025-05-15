#include <catch2/catch_test_macros.hpp>

#include <cmath>
#include <string>

#include "../include/constants.hpp"
#include "../include/error.hpp"
#include "../include/number.hpp"
#include "tools.cpp"

const int RAND_TESTS_AMOUNT = 1000;
const int ZERO_INT = 0;
const Number ZERO_NUMBER = make_number( ZERO_INT );

TEST_CASE( "make_number(rand_value, rand_error)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double rand_value = random_double( MIN_INT, MAX_INT );
        Error rand_error = random_error();
        Number num = make_number( rand_value, rand_error );

        REQUIRE( num.value == rand_value );
        REQUIRE( num.error.code == rand_error.code );
        REQUIRE( num.error.message == rand_error.message );
    }
}

TEST_CASE( "get_error(number(rand_value, default_error))", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double value = random_double( MIN_INT, MAX_INT );
        Number number = make_number( value );

        Error number_error = get_error( number );

        REQUIRE( number_error.code == Errors::OK.code );
        REQUIRE( number_error.message == Errors::OK.message );
    }
}

TEST_CASE( "get_error(number(rand_value, rand_error))", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Error error = random_error();
        double value = random_double( MIN_INT, MAX_INT );
        Number number = make_number( value, error );

        Error number_error = get_error( number );

        REQUIRE( number_error.code == error.code );
        REQUIRE( number_error.message == error.message );
    }
}

TEST_CASE( "==(rand, rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number left = random_number();
        Number right = random_number();

        REQUIRE( ( left == right ) == ( left.value == right.value ) );
    }
}

TEST_CASE( "<(rand, rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number left = random_number();
        Number right = random_number();

        REQUIRE( ( left < right ) == ( left.value < right.value ) );
    }
}

TEST_CASE( ">(rand, rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number left = random_number();
        Number right = random_number();

        REQUIRE( ( left > right ) == ( left.value > right.value ) );
    }
}

TEST_CASE( "<=(rand, rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number left = random_number();
        Number right = random_number();

        REQUIRE( ( left <= right ) == ( left.value <= right.value ) );
    }
}

TEST_CASE( ">=(rand, rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number left = random_number();
        Number right = random_number();

        REQUIRE( ( left >= right ) == ( left.value >= right.value ) );
    }
}

TEST_CASE( "!=(rand, rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number left = random_number();
        Number right = random_number();

        REQUIRE( ( left != right ) == ( left.value != right.value ) );
    }
}

TEST_CASE( "neg(rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number number = random_number();
        Number neg_number = -number;

        REQUIRE( number.value == -neg_number.value );
    }
}

TEST_CASE( "add(rand, rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number left = random_number();
        Number right = random_number();
        double expected = left.value + right.value;

        Number sum = left + right;

        REQUIRE( sum.value == expected );
    }
}

TEST_CASE( "sub(rand, rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number left = random_number();
        Number right = random_number();
        double expected = left.value - right.value;

        Number diff = left - right;

        REQUIRE( diff.value == expected );
    }
}

TEST_CASE( "mul(rand, rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number left = random_number();
        Number right = random_number();
        double expected = left.value * right.value;

        Number prod = left * right;

        REQUIRE( prod.value == expected );
    }
}

TEST_CASE( "div(rand, 0)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number num = random_number();

        Number res = num / ZERO_NUMBER;

        REQUIRE( res.value == ZERO_NUMBER.value );
        REQUIRE( res.error.code == ErrorCode::CALCULATION_ERROR );
    }
}

TEST_CASE( "div(0, rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number num = random_number();

        Number res = ZERO_NUMBER / num;

        REQUIRE( res.value == ZERO_NUMBER.value );
        REQUIRE( res.error.code == Errors::OK.code );
    }
}

TEST_CASE( "div(rand, rand != 0)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number left = random_number();
        Number right = random_number_ne_zero();
        double expected = left.value / right.value;

        Number res = left / right;

        REQUIRE( res.value == expected );
        REQUIRE( res.error.code == ErrorCode::OK );
    }
}

TEST_CASE( "sqrt(rand < 0)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number num = random_number_lt_zero();

        Number res = sqrt( num );

        REQUIRE( res.value == ZERO_NUMBER.value );
        REQUIRE( res.error.code == ErrorCode::CALCULATION_ERROR );
    }
}

TEST_CASE( "sqrt(rand >= 0)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number num = random_number_ge_zero();

        Number res = sqrt( num );

        REQUIRE( res.value >= ZERO_NUMBER.value );
        REQUIRE( res.error.code == ErrorCode::OK );
    }
}

TEST_CASE( "to_string(rand)", "[number]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number num = random_number();
        std::string str = to_string( num );

        REQUIRE( str == std::to_string( num.value ) );
    }
}
