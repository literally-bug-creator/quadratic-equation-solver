#include <catch2/catch_test_macros.hpp>
#include "../include/coefficient.h"

TEST_CASE( "Simple test", "[example]" ) { REQUIRE( 1 + 1 == 2 ); }

TEST_CASE( "Simple test", "[example]" ) {
    Coefficient a = Coefficient(0.0);
    Coefficient b = Coefficient(0.0);
    REQUIRE( is_equal(add(a, b), b) );
}
