#include "interpreter/or.hpp"

OrExpression::OrExpression( const Expression& left, const Expression& right ):
    left( left ), right( right ) {};

bool OrExpression::interpret( Context& context ) const {
    return left.interpret( context ) || right.interpret( context );
}
