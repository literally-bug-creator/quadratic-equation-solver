#pragma once

#include "nan.hpp"
#include "sign.hpp"

class SignedNanExpression : NonTerminalExpression {
public:
    bool interpret( Context& context ) const override;

private:
    inline static SignExpression sign = SignExpression();
    inline static NanExpression inf = NanExpression();
};
