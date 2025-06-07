#include "numbers.hpp"

#include <variant>

#include "error.hpp"
#include "number.hpp"

const Error& get_error( const Numbers& number ) {
    return std::visit(
        []( const auto& value ) -> const Error& { return get_error( value ); },
        number );
}

bool is_equal( const Numbers& left, const Numbers& right ) {
    return std::visit(
        []( const auto& lhs, const auto& rhs ) -> bool {
            using T = std::decay_t<decltype( lhs )>;
            using U = std::decay_t<decltype( rhs )>;

            if constexpr ( std::is_same_v<T, U> ) {
                return is_equal( lhs, rhs );
            } else {
                return false;
            }
        },
        left,
        right );
}

bool is_lower_than( const Numbers& left, const Numbers& right ) {
    return std::visit(
        []( const auto& lhs, const auto& rhs ) -> bool {
            using T = std::decay_t<decltype( lhs )>;
            using U = std::decay_t<decltype( rhs )>;

            if constexpr ( std::is_same_v<T, U> ) {
                return is_lower_than( lhs, rhs );
            } else {
                return false;
            }
        },
        left,
        right );
}

std::string to_string( const Numbers& number ) {
    return std::visit(
        []( const auto& value ) -> std::string { return to_string( value ); },
        number );
}
