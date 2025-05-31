#include "interpreter/digits.hpp"

bool DigitsExpression::interpret( Context& context ) const {
    if ( !digit.interpret( context ) ) { return false; }

    while ( !context.is_finished() ) {
        if ( !digit.interpret( context ) ) { break; }
    }

    return true;
}
