#pragma once

#include "context.hpp"

class Expression {
public:
    virtual ~Expression() = default;
    virtual bool interpret( Context& context ) const = 0;
};

class NonTerminalExpression : public Expression {};

class TerminalExpression : public Expression {};
