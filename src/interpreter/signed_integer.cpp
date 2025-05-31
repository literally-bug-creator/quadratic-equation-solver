#include "interpreter/signed_integer.hpp"

#include "interpreter/logical.hpp"

bool ZeroExpression::interpret( Context& context ) const {
    if ( context.is_finished() ) return false;

    TokenSequenceView view = context.get_tokens( size( token ) );

    if ( view == token ) {
        context.next( size( token ) );
        return true;
    }

    return false;
}

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
