#include <string>

#include "error.hpp"

namespace EquationCoefficientsMessages {
    const std::string INVALID_INPUT = "Некорректный ввод";
}

namespace EquationCoefficientsErrors {
    const Error INVALID_INPUT = make_error(
        ErrorCode::INVALID_INPUT, EquationCoefficientsMessages::INVALID_INPUT );
}
