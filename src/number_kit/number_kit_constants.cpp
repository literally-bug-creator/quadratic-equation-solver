#include <string>

#include "error.hpp"

namespace NumberKitMessages {
    const std::string INVALID_INPUT = "Некорректный ввод";
}

namespace NumberKitErrors {
    const Error INVALID_INPUT = make_error( ErrorCode::INVALID_INPUT,
                                            NumberKitMessages::INVALID_INPUT );
}
