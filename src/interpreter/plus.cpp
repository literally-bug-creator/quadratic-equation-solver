#include "interpreter/plus.hpp"

bool PlusExpression::interpret( Context& context ) const {
    TokenSequenceView view = context.get_tokens( size( token ) );

    if ( view == token ) {
        context.next( size( token ) );
        return true;
    }

    return false;
}
