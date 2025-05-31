#pragma once

#include "exponent.hpp"
#include "fraction.hpp"
#include "signed_integer.hpp"

class FloatExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const ExponentExpression exponent = ExponentExpression();
    const SignedIntegerExpression signed_int = SignedIntegerExpression();
    const FractionExpression fraction = FractionExpression();
};
