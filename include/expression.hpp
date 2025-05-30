#pragma once

#include "context.hpp"

class AbstractExpression {
public:
    virtual ~AbstractExpression() = default;
    virtual bool interpret( const Context& context ) const = 0;
};

class NonTerminalExpression : public AbstractExpression {};

class TerminalExpression : public AbstractExpression {
public:
    TerminalExpression( std::vector<Token> valid_tokens );
    virtual bool interpret( const Context& context ) const override;

private:
    std::vector<Token> valid_tokens;
};
