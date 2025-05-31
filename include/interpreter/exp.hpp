#pragma once

#include "expression.hpp"
#include "token.hpp"

class ExpExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const Token token = make_token( 'e' );
};
