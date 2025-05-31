#pragma once

#include "expression.hpp"
#include "token.hpp"

class InfExpression : NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    inline static TerminalExpression i_exp =
        TerminalExpression( std::vector<Token>{ make_token( 'i' ) } );
    inline static TerminalExpression n_exp =
        TerminalExpression( std::vector<Token>{ make_token( 'n' ) } );
    inline static TerminalExpression f_exp =
        TerminalExpression( std::vector<Token>{ make_token( 'f' ) } );
};
