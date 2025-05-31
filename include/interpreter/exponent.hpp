#pragma once

#include "exp.hpp"
#include "signed_integer.hpp"

class ExponentExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const ExpExpression exp = ExpExpression();
    const SignedIntegerExpression signed_int = SignedIntegerExpression();
};
