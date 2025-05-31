#include "interpreter/inf.hpp"

bool InfExpression::interpret( Context& context ) const {
    TokenSequenceView view = context.get_tokens( inf.size() );
    if ( view == inf ) {
        context.next( inf.size() );
        return true;
    }

    return false;
}
