#include <optional>
#include <string>

#include "big_number.hpp"
#include "constants.cpp"
#include "input.hpp"
#include "interpreter.hpp"

std::optional<big_number::BigNumber> read_value() {
    std::string str;
    if ( !( INPUT_STREAM >> str ) ) {
        return std::optional<big_number::BigNumber>{};
    }

    number_interpreter::Interpreter interpreter =
        number_interpreter::Interpreter();

    if ( !interpreter.interpret( str ) )
        return std::optional<big_number::BigNumber>{};

    return big_number::make_big_number( str );
}
