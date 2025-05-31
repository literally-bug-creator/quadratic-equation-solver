#pragma once

#include "expression.hpp"

class PlusExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    inline static Token token = make_token( '+' );
};

class MinusExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    inline static Token token = make_token( '-' );
};

class SignExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const MinusExpression minus = MinusExpression();
    const PlusExpression plus = PlusExpression();
};
