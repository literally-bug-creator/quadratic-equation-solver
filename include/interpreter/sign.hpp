#pragma once

#include "expression.hpp"
#include "token.hpp"

class SignExpression : NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    inline static TerminalExpression plus =
        TerminalExpression( std::vector<Token>{ make_token( '+' ) } );
    inline static TerminalExpression minus =
        TerminalExpression( std::vector<Token>{ make_token( '-' ) } );
};
