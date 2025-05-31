#include "interpreter/logical.hpp"

AndExpression::AndExpression( const Expression& left, const Expression& right ):
    left( left ), right( right ) {};

bool AndExpression::interpret( Context& context ) const {
    ContextImage dump = context.dump();

    if ( left.interpret( context ) && right.interpret( context ) ) {
        return true;
    }

    context.restore( dump );
    return false;
}

OrExpression::OrExpression( const Expression& left, const Expression& right ):
    left( left ), right( right ) {};

bool OrExpression::interpret( Context& context ) const {
    return left.interpret( context ) || right.interpret( context );
}
