#include "interpreter/nan.hpp"

bool NanExpression::interpret( Context& context ) const {
    TokenSequenceView view = context.get_tokens( nan.size() );
    if ( view == nan ) {
        context.next( nan.size() );
        return true;
    }

    return false;
}
