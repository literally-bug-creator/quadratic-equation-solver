#pragma once

#include "expression.hpp"
#include "minus.hpp"
#include "plus.hpp"

class SignExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const MinusExpression minus = MinusExpression();
    const PlusExpression plus = PlusExpression();
};
