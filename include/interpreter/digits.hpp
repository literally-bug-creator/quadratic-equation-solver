#pragma once

#include "expression.hpp"

class DigitExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const std::vector<Token> tokens = { make_token( '0' ),
                                        make_token( '1' ),
                                        make_token( '2' ),
                                        make_token( '3' ),
                                        make_token( '4' ),
                                        make_token( '5' ),
                                        make_token( '6' ),
                                        make_token( '7' ),
                                        make_token( '8' ),
                                        make_token( '9' ) };
};

class DigitsExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const DigitExpression digit = DigitExpression();
};
