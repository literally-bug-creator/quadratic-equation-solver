#include <catch2/catch_test_macros.hpp>

#include "../include/error.hpp"
#include "tools.cpp"

TEST_CASE( "make_error(OK, empty)", "[public]" ) {
    Error error = make_error( OK, "" );

    REQUIRE( error.code == OK );
    REQUIRE( error.message.empty() );
}

TEST_CASE( "make_error(INVALID_INPUT, empty)", "[public]" ) {
    Error error = make_error( INVALID_INPUT, "" );

    REQUIRE( error.code == INVALID_INPUT );
    REQUIRE( error.message.empty() );
}

TEST_CASE( "make_error(CALCULATION_ERROR, empty)", "[public]" ) {
    Error error = make_error( CALCULATION_ERROR, "" );

    REQUIRE( error.code == CALCULATION_ERROR );
    REQUIRE( error.message.empty() );
}

TEST_CASE( "make_error(SOLUTION_ERROR, empty)", "[public]" ) {
    Error error = make_error( SOLUTION_ERROR, "" );

    REQUIRE( error.code == SOLUTION_ERROR );
    REQUIRE( error.message.empty() );
}

TEST_CASE( "make_error(RAND, RAND) in cycle", "[public]" ) {
    for ( int _ = 0; _ < TESTS_AMOUNT; _++ ) {
        int msg_length = random_int( MIN_INT, MAX_INT );
        std::string msg = random_string( msg_length );
        ErrorCode code = random_error_code();
        Error error = make_error( code, msg );

        REQUIRE( error.code == code );
        REQUIRE( error.message == msg );
    }
}

TEST_CASE( "get_error_code(random_error) in cycle", "[public]" ) {
    for ( int _ = 0; _ < TESTS_AMOUNT; _++ ) {
        int msg_length = random_int( MIN_INT, MAX_INT );
        std::string msg = random_string( msg_length );
        ErrorCode code = random_error_code();
        Error error = make_error( code, msg );

        REQUIRE( get_error_code( error ) == code );
    }
}

TEST_CASE( "get_error_message(error_with_empty_msg)", "[public]" ) {
    ErrorCode code = random_error_code();
    Error error = make_error( code, "" );

    REQUIRE( get_error_message( error ).empty() );
}

TEST_CASE( "get_error_message(random_error) in cycle", "[public]" ) {
    for ( int _ = 0; _ < TESTS_AMOUNT; _++ ) {
        int msg_length = random_int( MIN_INT, MAX_INT );
        std::string msg = random_string( msg_length );
        ErrorCode code = random_error_code();
        Error error = make_error( code, msg );

        REQUIRE( get_error_message( error ) == msg );
    }
}
