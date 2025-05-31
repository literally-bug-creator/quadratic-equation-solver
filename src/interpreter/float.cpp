#include "interpreter/float.hpp"

bool DotExpression::interpret( Context& context ) const {
    if ( context.is_finished() ) return false;

    TokenSequenceView view = context.get_tokens( size( token ) );

    if ( view == token ) {
        context.next( size( token ) );
        return true;
    }

    return false;
}

bool FractionExpression::interpret( Context& context ) const {
    ContextImage dump = context.dump();

    if ( !dot.interpret( context ) ) { return false; }

    if ( !digits.interpret( context ) ) {
        context.restore( dump );
        return false;
    }

    return true;
}

bool FloatExpression::interpret( Context& context ) const {
    if ( !signed_int.interpret( context ) ) { return false; }
    fraction.interpret( context );
    exponent.interpret( context );

    return true;
}
