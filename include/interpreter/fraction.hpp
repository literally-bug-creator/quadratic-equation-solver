#pragma once

#include "digits.hpp"
#include "dot.hpp"

class FractionExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const DotExpression dot = DotExpression();
    const DigitsExpression digits = DigitsExpression();
};
