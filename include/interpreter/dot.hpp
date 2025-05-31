#pragma once

#include "expression.hpp"
#include "token.hpp"

class DotExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const Token token = make_token( '.' );
};
