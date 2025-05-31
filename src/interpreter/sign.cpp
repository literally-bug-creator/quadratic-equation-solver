#include "interpreter/sign.hpp"

#include "interpreter/or.hpp"

bool SignExpression::interpret( Context& context ) const {
    OrExpression or_exp = OrExpression( minus, plus );
    return or_exp.interpret( context );
}
