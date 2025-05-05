#include <string>

#include "error.hpp"

namespace Messages {
    const std::string INVALID_INPUT = "Некорректный ввод";
    const std::string DIV_BY_ZERO = "Деление на ноль";
    const std::string ROOT_FROM_NEG = "Корень из отрицательного числа";
}

namespace Errors {
    const Error INVALID_INPUT =
        make_error( ErrorCode::INVALID_INPUT, Messages::INVALID_INPUT );
    const Error DIV_BY_ZERO =
        make_error( ErrorCode::CALCULATION_ERROR, Messages::DIV_BY_ZERO );
    const Error ROOT_FROM_NEG =
        make_error( ErrorCode::CALCULATION_ERROR, Messages::ROOT_FROM_NEG );
}
