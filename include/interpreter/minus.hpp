#pragma once

#include "expression.hpp"

class MinusExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    inline static Token token = make_token( '-' );
};
