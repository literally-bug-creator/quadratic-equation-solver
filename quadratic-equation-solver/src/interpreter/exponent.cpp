#include "interpreter/exponent.hpp"

bool ExpExpression::interpret( Context& context ) const {
    if ( context.is_finished() ) return false;

    TokenSequenceView view = context.get_tokens( size( token ) );

    if ( view == token ) {
        context.next( size( token ) );
        return true;
    }

    return false;
}

bool ExponentExpression::interpret( Context& context ) const {
    ContextImage dump = context.dump();

    if ( !exp.interpret( context ) ) { return false; }

    if ( !signed_int.interpret( context ) ) {
        context.restore( dump );
        return false;
    }

    return true;
}
