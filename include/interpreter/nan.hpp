#pragma once

#include "expression.hpp"

class NanExpression : public TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    inline static std::vector<Token> tokens = {
        make_token( 'n' ), make_token( 'a' ), make_token( 'n' ) };
    inline static TokenSequenceOwner nan = TokenSequenceOwner( tokens );
};
