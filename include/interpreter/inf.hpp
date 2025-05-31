#pragma once

#include "expression.hpp"

class InfExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    inline static std::vector<Token> tokens = {
        make_token( 'i' ), make_token( 'n' ), make_token( 'f' ) };
    inline static TokenSequenceOwner inf = TokenSequenceOwner( tokens );
};
