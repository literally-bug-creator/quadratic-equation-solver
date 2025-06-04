#include "interpreter/constant.hpp"

#include "interpreter/logical.hpp"

bool InfExpression::interpret( Context& context ) const {
    if ( context.is_finished() ) return false;
    if ( context.get_tokens_amount() < inf.size() ) return false;

    TokenSequenceView view = context.get_tokens( inf.size() );
    if ( view == inf ) {
        context.next( inf.size() );
        return true;
    }

    return false;
}

bool NanExpression::interpret( Context& context ) const {
    if ( context.is_finished() ) return false;
    if ( context.get_tokens_amount() < nan.size() ) return false;

    TokenSequenceView view = context.get_tokens( nan.size() );
    if ( view == nan ) {
        context.next( nan.size() );
        return true;
    }

    return false;
}

bool ConstantExpression::interpret( Context& context ) const {
    ContextImage dump = context.dump();

    sign.interpret( context );
    OrExpression or_exp = OrExpression( inf, nan );

    if ( !or_exp.interpret( context ) ) {
        context.restore( dump );
        return false;
    }

    return true;
}
