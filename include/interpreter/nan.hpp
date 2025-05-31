#pragma once

#include "expression.hpp"
#include "token.hpp"
#include "token_sequence.hpp"

class NanExpression : TerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    TokenSequenceOwner nan;
};
