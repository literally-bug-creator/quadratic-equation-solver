#include "interpreter/signed_integer.hpp"

#include "interpreter/or.hpp"

bool SignedIntegerExpression::interpret( Context& context ) const {
    ContextImage dump = context.dump();

    sign.interpret( context );
    OrExpression or_exp = OrExpression( zero, digits );

    if ( !or_exp.interpret( context ) ) {
        context.restore( dump );
        return false;
    }

    return true;
}
