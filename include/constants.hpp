#pragma once

#include <string>

#include "error.hpp"

namespace Messages {
    const std::string DEFAULT_ERROR = "";
}

namespace Errors {
    const Error DEFAULT_ERROR = make_error( OK, Messages::DEFAULT_ERROR );
}

namespace Numeric {
    const double ZERO = 0;
    const double FOUR = 4;
    const double TWO = 2;
}
