#include "interpreter/constant.hpp"

#include "interpreter/context.hpp"
#include "interpreter/or.hpp"

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
