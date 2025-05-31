#pragma once

#include "interpreter/inf.hpp"
#include "interpreter/nan.hpp"
#include "interpreter/sign.hpp"

class ConstantExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const SignExpression sign = SignExpression();
    const InfExpression inf = InfExpression();
    const NanExpression nan = NanExpression();
};
