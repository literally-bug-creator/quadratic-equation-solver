#include "interpreter/exp.hpp"

bool ExpExpression::interpret( Context& context ) const {
    if ( context.is_finished() ) return false;

    TokenSequenceView view = context.get_tokens( size( token ) );

    if ( view == token ) {
        context.next( size( token ) );
        return true;
    }

    return false;
}
