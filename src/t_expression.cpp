#pragma once

#include <vector>

#include "t_expression.hpp"

TerminalExpression::TerminalExpression( std::vector<Token> valid_tokens ):
    valid_tokens( valid_tokens ) {};

bool TerminalExpression::interpret( const Context& context ) const {
    for ( const Token& token : valid_tokens ) {
        TokenSequenceView actual = context.get_tokens( size( token ) );
        if ( actual == token ) return true;
    }
    return false;
}
