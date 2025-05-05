#include <string>

#include "error.hpp"

namespace NumberMessages {
    const std::string INVALID_INPUT = "Некорректный ввод";
    const std::string DIV_BY_ZERO = "Деление на ноль";
    const std::string ROOT_FROM_NEG = "Корень из отрицательного числа";
}

namespace NumberErrors {
    const Error INVALID_INPUT =
        make_error( ErrorCode::INVALID_INPUT, NumberMessages::INVALID_INPUT );
    const Error DIV_BY_ZERO =
        make_error( ErrorCode::CALCULATION_ERROR, NumberMessages::DIV_BY_ZERO );
    const Error ROOT_FROM_NEG = make_error( ErrorCode::CALCULATION_ERROR,
                                            NumberMessages::ROOT_FROM_NEG );
}
