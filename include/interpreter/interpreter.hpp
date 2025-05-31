#include <string>

#include "constant.hpp"
#include "float.hpp"

class Interpreter {
public:
    bool interpret( const std::string& str ) const;

private:
    const ConstantExpression const_exp = ConstantExpression();
    const FloatExpression float_exp = FloatExpression();
};
