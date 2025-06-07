#pragma once

#include <string>

#include "big_number.hpp"
#include "error.hpp"

namespace Messages {
    const std::string OK = "";
}

namespace Errors {
    const Error OK = make_error( ErrorCode::OK, Messages::OK );
}

namespace Numeric {
    const big_number::BigNumber ZERO = big_number::make_big_number( "0" );
    const double FOUR = 4;
    const double TWO = 2;
}
