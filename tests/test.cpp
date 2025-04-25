#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Simple test", "[example]" ) { REQUIRE( 1 + 1 == 2 ); }

TEST_CASE( "Math test #1" ) { REQUIRE( 1 + 1 == 3 ); }

TEST_CASE( "Math test #2" ) { REQUIRE( 1 + 1 == 4 ); }

TEST_CASE( "Math test #3" ) { REQUIRE( 1 + 1 == 5 ); }
