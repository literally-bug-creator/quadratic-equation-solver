#pragma once

#include "inf.hpp"
#include "sign.hpp"

class SignedInfExpression : NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    inline static SignExpression sign = SignExpression();
    inline static InfExpression inf = InfExpression();
};
