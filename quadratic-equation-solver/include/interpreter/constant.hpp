#pragma once

#include "sign.hpp"

class InfExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const std::vector<Token> tokens = {
        make_token( 'i' ), make_token( 'n' ), make_token( 'f' ) };
    const TokenSequenceOwner inf = TokenSequenceOwner( tokens );
};

class NanExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const std::vector<Token> tokens = {
        make_token( 'n' ), make_token( 'a' ), make_token( 'n' ) };
    const TokenSequenceOwner nan = TokenSequenceOwner( tokens );
};

class ConstantExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const SignExpression sign = SignExpression();
    const InfExpression inf = InfExpression();
    const NanExpression nan = NanExpression();
};
