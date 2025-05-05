#include <string>

#include "error.hpp"

namespace CoefficientsMessages {
    const std::string INVALID_INPUT = "Некорректный ввод";
}

namespace CoefficientsErrors {
    const Error INVALID_INPUT = make_error(
        ErrorCode::INVALID_INPUT, CoefficientsMessages::INVALID_INPUT );
}
