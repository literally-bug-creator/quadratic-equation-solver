#pragma once

#include <string>

#include "error.hpp"

namespace Messages {
    const std::string OK = "";
}

namespace Errors {
    const Error OK = make_error( ErrorCode::OK, Messages::OK );
}

namespace Numeric {
    const double ZERO = 0;
    const double FOUR = 4;
    const double TWO = 2;
}
