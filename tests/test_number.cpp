#include <catch2/catch_test_macros.hpp>

#include <cmath>
#include <error.h>
#include <iomanip>
#include <sstream>
#include <string>

#include "../src/number.cpp"
#include "tools.cpp"


TEST_CASE( "make_number(rand_value, rand_error, not_null) in cycle",
           "[public]" ) {
    for ( int i = 0; i < DEFAULT_MAX_INT; i++ ) {
        double rand_value = random_double( DEFAULT_MIN_INT, DEFAULT_MAX_INT );
        Error rand_error = random_error();
        Number num = make_number( rand_value, rand_error, false );

        REQUIRE( num.is_null == false );
        REQUIRE( num.value == rand_value );
        REQUIRE( num.error.code == rand_error.code );
        REQUIRE( num.error.message == rand_error.message );
    }
}

TEST_CASE( "make_number(rand_value, rand_error, is_null) in cycle",
           "[public]" ) {
    for ( int i = 0; i < DEFAULT_MAX_INT; i++ ) {
        double rand_value = random_double( DEFAULT_MIN_INT, DEFAULT_MAX_INT );
        Error rand_error = random_error();
        Number num = make_number( rand_value, rand_error, true );

        REQUIRE( num.is_null == true );
        REQUIRE( num.value == rand_value );
        REQUIRE( num.error.code == rand_error.code );
        REQUIRE( num.error.message == rand_error.message );
    }
}

TEST_CASE( "is_null(0)", "[public]" ) {
    Number number = make_number( 0 );

    REQUIRE( !is_null( number ) );
}

TEST_CASE( "is_null(-5)", "[public]" ) {
    Number number = make_number( -5 );

    REQUIRE( !is_null( number ) );
}

TEST_CASE( "is_null(4)", "[public]" ) {
    Number number = make_number( 4 );

    REQUIRE( !is_null( number ) );
}

TEST_CASE( "is_null(4, ok, true)", "[public]" ) {
    Number number = make_number( 4, DEFAULT_ERROR, true );

    REQUIRE( is_null( number ) );
}

TEST_CASE( "is_null(4, rand_error) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Error error = random_error();
        Number number = make_number( 4, error );

        REQUIRE( !is_null( number ) );
    }
}

TEST_CASE( "is_null(4, rand_error, true) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Error error = random_error();
        Number number = make_number( 4, error, true );

        REQUIRE( is_null( number ) );
    }
}

TEST_CASE( "is_null(-4, rand_error) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Error error = random_error();
        Number number = make_number( -4, error );

        REQUIRE( !is_null( number ) );
    }
}

TEST_CASE( "is_null(rand_value) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        double value = random_double(DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT);
        Number number = make_number( value );

        REQUIRE( !is_null( number ) );
    }
}

TEST_CASE( "is_null(rand_value, ok, true) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        double value = random_double(DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT);
        Number number = make_number( value, DEFAULT_ERROR, true );

        REQUIRE( is_null( number ) );
    }
}

TEST_CASE( "is_null(rand_value, rand_error) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Error error = random_error();
        double value = random_double(DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT);
        Number number = make_number( value, error );

        REQUIRE( !is_null( number ) );
    }
}

TEST_CASE( "is_null(rand_value, rand_error, true) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Error error = random_error();
        double value = random_double(DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT);
        Number number = make_number( value, error, true );

        REQUIRE( is_null( number ) );
    }
}

TEST_CASE( "get_error(rand_value) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        double value = random_double(DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT);
        Number number = make_number( value );

        Error number_error = get_error(number);

        REQUIRE( number_error.code == DEFAULT_ERROR.code );
        REQUIRE( number_error.message == DEFAULT_ERROR.message );
    }
}

TEST_CASE( "get_error(rand_value, rand_error) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Error error = random_error();
        double value = random_double(DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT);
        Number number = make_number( value, error );

        Error number_error = get_error(number);

        REQUIRE( number_error.code == error.code );
        REQUIRE( number_error.message == error.message );
    }
}

TEST_CASE( "get_error(rand_value, rand_error, true) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Error error = random_error();
        double value = random_double(DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT);
        Number number = make_number( value, error, true );

        Error number_error = get_error(number);

        REQUIRE( number_error.code == error.code );
        REQUIRE( number_error.message == error.message );
    }
}

TEST_CASE( "is_equal(0, 0)", "[public]" ) {
    Number left = make_number( 0 );
    Number right = make_number( 0 );

    REQUIRE( is_equal( left, right ) );
}

TEST_CASE( "is_equal(rand, rand) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double left_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        double right_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        Number left = make_number( left_value );
        Number right = make_number( right_value );
        bool is_values_equal = left_value == right_value;

        REQUIRE( is_equal( left, right ) == is_values_equal );
    }
}

TEST_CASE( "is_lower_than(0, 0)", "[public]" ) {
    Number left = make_number( 0 );
    Number right = make_number( 0 );

    REQUIRE( !is_lower_than( left, right ) );
}

TEST_CASE( "is_lower_than(-5, -1)", "[public]" ) {
    Number left = make_number( -5 );
    Number right = make_number( -1 );

    REQUIRE( is_lower_than( left, right ) );
}

TEST_CASE( "is_lower_than(-1, -5)", "[public]" ) {
    Number left = make_number( -1 );
    Number right = make_number( -5 );

    REQUIRE( !is_lower_than( left, right ) );
}

TEST_CASE( "is_lower_than(rand, rand) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double left_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        double right_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        Number left = make_number( left_value );
        Number right = make_number( right_value );
        bool is_left_lower_than_right = left_value < right_value;

        REQUIRE( is_lower_than( left, right ) == is_left_lower_than_right );
    }
}

TEST_CASE( "neg(rand) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double value = random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        Number number = make_number( value );
        Number neg_number = neg( number );

        REQUIRE( !neg_number.is_null );
        REQUIRE( neg_number.error.code == OK );
        REQUIRE( neg_number.value == -value );
    }
}

TEST_CASE( "add(rand, rand) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double left_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        double right_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        Number left_number = make_number( left_value );
        Number right_number = make_number( right_value );
        Number number_sum = add( left_number, right_number );
        double value_sum = left_value + right_value;

        REQUIRE( !number_sum.is_null );
        REQUIRE( number_sum.error.code == OK );
        REQUIRE( number_sum.value == value_sum );
    }
}

TEST_CASE( "sub(rand, rand) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double left_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        double right_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        Number left_number = make_number( left_value );
        Number right_number = make_number( right_value );
        Number number_sub = sub( left_number, right_number );
        double value_sub = left_value - right_value;

        REQUIRE( !number_sub.is_null );
        REQUIRE( number_sub.error.code == OK );
        REQUIRE( number_sub.value == value_sub );
    }
}

TEST_CASE( "mul(rand, rand) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double left_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        double right_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        Number left_number = make_number( left_value );
        Number right_number = make_number( right_value );
        Number number_mul = mul( left_number, right_number );
        double value_mul = left_value * right_value;

        REQUIRE( !number_mul.is_null );
        REQUIRE( number_mul.error.code == OK );
        REQUIRE( number_mul.value == value_mul );
    }
}

TEST_CASE( "div(rand, 0) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double left_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );

        Number left_number = make_number( left_value );
        Number right_number = make_number( 0 );
        Number number_div = div( left_number, right_number );

        REQUIRE( number_div.is_null );
        REQUIRE( number_div.error.code == CALCULATION_ERROR );
    }
}

TEST_CASE( "div(0, rand) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double right_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );

        Number left_number = make_number( 0 );
        Number right_number = make_number( right_value );
        Number number_div = div( left_number, right_number );

        REQUIRE( !number_div.is_null );
        REQUIRE( number_div.value == double( 0 ) );
        REQUIRE( number_div.error.code != CALCULATION_ERROR );
    }
}

TEST_CASE( "div(rand, rand != 0) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double left_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        double right_value =
            random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );

        if ( right_value == 0 ) { continue; }

        Number left_number = make_number( left_value );
        Number right_number = make_number( right_value );
        Number number_div = div( left_number, right_number );
        double value_div = left_value / right_value;

        REQUIRE( !number_div.is_null );
        REQUIRE( number_div.value == value_div );
        REQUIRE( number_div.error.code == OK );
    }
}

TEST_CASE( "sqrt(rand < 0) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double value = random_double( DEFAULT_MIN_NEG_INT, 0 );

        Number number = make_number( value );
        Number number_root = sqrt( number );

        REQUIRE( number_root.is_null );
        REQUIRE( number_root.error.code == CALCULATION_ERROR );
    }
}

TEST_CASE( "sqrt(rand >= 0) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double value = random_double( 0, DEFAULT_MAX_INT );
        Number number = make_number( value );
        Number number_root = sqrt( number );
        double value_root = sqrt( value );

        REQUIRE( !number_root.is_null );
        REQUIRE( number_root.error.code == OK );
        REQUIRE( number_root.value == value_root );
    }
}

TEST_CASE( "to_string(rand) in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double value = random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        Number number = make_number( value );

        REQUIRE( !number.is_null );
        REQUIRE( to_string( number ) == std::to_string( value ) );
        REQUIRE( number.error.code == OK );
    }
}

TEST_CASE( "input_number(letter)", "[public]" ) {
    std::string value = "abcdefg";
    std::istringstream input( value );
    Number number = input_number( input );

    REQUIRE( number.is_null );
    REQUIRE( number.value == 0 );
    REQUIRE( number.error.code == INVALID_INPUT );
}

TEST_CASE( "input_number() in cycle", "[public]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        double value = random_double( DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT );
        std::ostringstream oss;
        oss << std::setprecision( std::numeric_limits<double>::max_digits10 )
            << value;
        std::istringstream input( oss.str() );
        Number number = input_number( input );

        REQUIRE( !number.is_null );
        REQUIRE( number.value == value );
        REQUIRE( number.error.code == OK );
    }
}
