#include "interpreter/minus.hpp"

bool MinusExpression::interpret( Context& context ) const {
    TokenSequenceView view = context.get_tokens( size( token ) );

    if ( view == token ) {
        context.next( size( token ) );
        return true;
    }

    return false;
}
