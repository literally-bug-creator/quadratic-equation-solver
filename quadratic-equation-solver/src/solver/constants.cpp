#include "constants.hpp"

#include "error.hpp"
#include "number.hpp"

namespace SolverNumbers {
    const Number ZERO = make_number( Numeric::ZERO );
    const Number FOUR = make_number( Numeric::FOUR );
    const Number TWO = make_number( Numeric::TWO );
}

namespace SolverMessages {
    const std::string DISCRIMINANT_BELOW_ZERO = "Дискриминант меньше нуля!";
}

namespace SolverErrors {
    const Error DISCRIMINANT_BELOW_ZERO = make_error(
        ErrorCode::SOLUTION_ERROR, SolverMessages::DISCRIMINANT_BELOW_ZERO );
}
