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
    const big_number::BigNumber TWO = big_number::make_big_number( "2" );
    const big_number::BigNumber FOUR = big_number::make_big_number( "4" );
}
