#include "interpreter/exponent.hpp"

bool ExponentExpression::interpret( Context& context ) const {
    ContextImage dump = context.dump();

    if ( !exp.interpret( context ) ) { return false; }

    if ( !signed_int.interpret( context ) ) {
        context.restore( dump );
        return false;
    }

    return true;
}
