#pragma once

#include "digit.hpp"

class DigitsExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const DigitExpression digit = DigitExpression();
};
