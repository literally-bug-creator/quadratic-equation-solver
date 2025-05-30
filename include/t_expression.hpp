#pragma once

#include <vector>

#include "aexpression.hpp"

class TerminalExpression : public AbstractExpression {
public:
    TerminalExpression( std::vector<Token> valid_tokens );
    virtual bool interpret( const Context& context ) const override;

private:
    std::vector<Token> valid_tokens;
};
