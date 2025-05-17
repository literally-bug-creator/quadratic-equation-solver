#include <any>
#include <cmath>
#include <optional>

#include "constants.cpp"
#include "constants.hpp"
#include "input.hpp"
#include "number.hpp"
#include "selector.hpp"

Selector get_selector( const Number& number ) {
    std::function<std::any( int index )> field =
        [number]( int index ) -> std::any {
        if ( index == 0 ) {
            return std::any( number.first );
        } else {
            return std::any( number.second );
        }
    };

    return field;
}

Number make_number( const double value, const Error& error ) {
    return Number( value, error );
}

Number input_number() {
    std::optional<double> number = read_value();

    if ( !number.has_value() ) {
        return make_number( Numeric::ZERO, NumberErrors::INVALID_INPUT );
    }

    return make_number( number.value(), Errors::OK );
}

double get_value( const Number& number ) {
    return std::any_cast<double>( get_selector( number )( 0 ) );
}

const Error get_error( const Number& number ) {
    return std::any_cast<Error>( get_selector( number )( 1 ) );
}

bool operator==( const Number& left, const Number& right ) {
    return get_value( left ) == get_value( right );
}

bool operator!=( const Number& left, const Number& right ) {
    return !( left == right );
}

bool operator<( const Number& left, const Number& right ) {
    return get_value( left ) < get_value( right );
}

bool operator>( const Number& left, const Number& right ) {
    return !( left < right ) && !( left == right );
}

bool operator<=( const Number& left, const Number& right ) {
    return !( left > right );
}

bool operator>=( const Number& left, const Number& right ) {
    return !( left < right );
}

const Number operator-( const Number& operand ) {
    double value = get_value( operand );
    return make_number( -value );
}

const Number operator+( const Number& augend, const Number& addend ) {
    double sum = get_value( augend ) + get_value( addend );
    return make_number( sum );
}

const Number operator-( const Number& minuend, const Number& subtrahend ) {
    double difference = get_value( minuend ) - get_value( subtrahend );
    return make_number( difference );
}

const Number operator*( const Number& multiplicand, const Number& multiplier ) {
    double product = get_value( multiplicand ) * get_value( multiplier );
    return make_number( product );
}

const Number operator/( const Number& dividend, const Number& divisor ) {
    double dividend_value = get_value( dividend );
    double divisor_value = get_value( divisor );

    if ( divisor_value == Numeric::ZERO ) {
        return make_number( Numeric::ZERO, NumberErrors::DIV_BY_ZERO );
    }

    return make_number( dividend_value / divisor_value, Errors::OK );
}

const Number sqrt( const Number& radicand ) {
    double value = get_value( radicand );

    if ( value < Numeric::ZERO ) {
        return make_number( Numeric::ZERO, NumberErrors::ROOT_FROM_NEG );
    }

    return make_number( sqrt( value ), Errors::OK );
}

const std::string to_string( const Number& coeff ) {
    return std::to_string( get_value( coeff ) );
}
