#include "interpreter/fraction.hpp"

bool FractionExpression::interpret( Context& context ) const {
    ContextImage dump = context.dump();

    if ( !dot.interpret( context ) ) { return false; }

    if ( !digits.interpret( context ) ) {
        context.restore( dump );
        return false;
    }

    return true;
}
