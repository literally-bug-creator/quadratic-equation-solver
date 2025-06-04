#pragma once

#include "digits.hpp"
#include "sign.hpp"

class ZeroExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const Token token = make_token( '0' );
};

class SignedIntegerExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const SignExpression sign = SignExpression();
    const DigitsExpression digits = DigitsExpression();
    const ZeroExpression zero = ZeroExpression();
};
