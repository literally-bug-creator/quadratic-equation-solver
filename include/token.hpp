#pragma once

#include <cstddef>

struct Token {
    char value;
};

Token make_token( char c );
size_t size( const Token& token );
bool is_equal( const Token& left, const Token& right );
