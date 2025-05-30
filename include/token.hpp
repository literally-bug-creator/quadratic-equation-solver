#pragma once

struct Token {
    char value;
};

Token make_token( char c );
bool is_equal( const Token& left, const Token& right );
