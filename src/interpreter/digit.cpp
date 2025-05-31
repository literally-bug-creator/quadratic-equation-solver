#include "interpreter/digit.hpp"

bool DigitExpression::interpret( Context& context ) const {
    TokenSequenceView view = context.get_tokens( 1 );

    for ( auto& token : tokens ) {
        if ( view == token ) {
            context.next( size( token ) );
            return true;
        }
    }

    return false;
}
