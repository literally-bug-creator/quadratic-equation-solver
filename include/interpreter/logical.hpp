#pragma once

#include "expression.hpp"

class AndExpression : public NonTerminalExpression {
public:
    AndExpression( const Expression& left, const Expression& right );
    virtual bool interpret( Context& context ) const override;

private:
    const Expression& left;  // const Expression *left;
    const Expression& right; // const Expression *right;
};

class OrExpression : public NonTerminalExpression {
public:
    OrExpression( const Expression& left, const Expression& right );
    bool interpret( Context& context ) const override;

private:
    const Expression& left;  // const Expression *left;
    const Expression& right; // const Expression *left;
};
