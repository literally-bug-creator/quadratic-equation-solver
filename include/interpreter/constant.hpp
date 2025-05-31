#pragma once

#include "inf.hpp"
#include "nan.hpp"
#include "sign.hpp"

class ConstantExpression : public NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    const SignExpression sign = SignExpression();
    const InfExpression inf = InfExpression();
    const NanExpression nan = NanExpression();
};
