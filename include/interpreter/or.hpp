#pragma once

#include "expression.hpp"

class OrExpression : public NonTerminalExpression {
public:
    OrExpression( const Expression& left, const Expression& right );
    bool interpret( Context& context ) const override;

private:
    const Expression& left;
    const Expression& right;
};
