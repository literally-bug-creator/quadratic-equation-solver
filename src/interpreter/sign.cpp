#include "interpreter/sign.hpp"

#include "interpreter/logical.hpp"

bool PlusExpression::interpret( Context& context ) const {
    if ( context.is_finished() ) return false;

    TokenSequenceView view = context.get_tokens( size( token ) );

    if ( view == token ) {
        context.next( size( token ) );
        return true;
    }

    return false;
}

bool MinusExpression::interpret( Context& context ) const {
    if ( context.is_finished() ) return false;

    TokenSequenceView view = context.get_tokens( size( token ) );

    if ( view == token ) {
        context.next( size( token ) );
        return true;
    }

    return false;
}

bool SignExpression::interpret( Context& context ) const {
    OrExpression or_exp = OrExpression( minus, plus );
    return or_exp.interpret( context );
}
