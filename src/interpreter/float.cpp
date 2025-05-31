#include "interpreter/float.hpp"

bool FloatExpression::interpret( Context& context ) const {
    if ( !signed_int.interpret( context ) ) { return false; }

    fraction.interpret( context );
    exponent.interpret( context );

    return true;
}
