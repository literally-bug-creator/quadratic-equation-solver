#include <error.h>

#include "constants.hpp"
#include "number.hpp"

namespace SolutionNumbers {
    const Number ZERO = make_number( Numeric::ZERO );
    const Number NUL =
        make_number( Numeric::ZERO, Errors::DEFAULT_ERROR, true );
    const Number FOUR = make_number( Numeric::FOUR );
    const Number TWO = make_number( Numeric::TWO );
}

namespace SolutionMessages {
    const std::string INVALID_NUMBER_KIT = "Некорректный набор чисел";
    const std::string DISCRIMINANT_BELOW_ZERO = "Дискриминант меньше нуля!";
}

namespace SolutionErrors {
    const Error INVALID_NUMBER_KIT = make_error(
        ErrorCode::SOLUTION_ERROR, SolutionMessages::INVALID_NUMBER_KIT );

    const Error DISCRIMINANT_BELOW_ZERO = make_error(
        ErrorCode::SOLUTION_ERROR, SolutionMessages::DISCRIMINANT_BELOW_ZERO );
}
