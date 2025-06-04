#pragma once

#include "exponent.hpp"
#include "signed_integer.hpp"

class DotExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const Token token = make_token( '.' );
};

class FractionExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const DotExpression dot = DotExpression();
    const DigitsExpression digits = DigitsExpression();
};

class FloatExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const ExponentExpression exponent = ExponentExpression();
    const SignedIntegerExpression signed_int = SignedIntegerExpression();
    const FractionExpression fraction = FractionExpression();
};
