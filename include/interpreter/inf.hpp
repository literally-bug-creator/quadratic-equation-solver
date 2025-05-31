#pragma once

#include "expression.hpp"

class InfExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const std::vector<Token> tokens = {
        make_token( 'i' ), make_token( 'n' ), make_token( 'f' ) };
    const TokenSequenceOwner inf = TokenSequenceOwner( tokens );
};
