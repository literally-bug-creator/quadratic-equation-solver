#pragma once

#include "digits.hpp"
#include "sign.hpp"
#include "zero.hpp"

class SignedIntegerExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const SignExpression sign = SignExpression();
    const DigitsExpression digits = DigitsExpression();
    const ZeroExpression zero = ZeroExpression();
};
