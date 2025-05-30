#include "token.hpp"

Token make_token( char c ) { return Token{ .value = c }; }

char get_value( const Token& token ) { return token.value; }

bool is_equal( const Token& left, const Token& right ) {
    return get_value( left ) == get_value( right );
}
