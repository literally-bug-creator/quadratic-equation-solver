#include "interpreter/and.hpp"

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
