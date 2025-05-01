#include "../include/number.h"

#include <cmath>
#include <iostream>
#include <optional>

namespace {
    const double ZERO = 0;

    const std::string INVALID_INPUT_MSG = "Некорректный ввод";
    const std::string DIV_BY_ZERO_MSG = "Деление на ноль";
    const std::string ROOT_FROM_NEG_MSG = "Корень из отрицательного числа";

    const Error INVALID_INPUT_ERROR =
        make_error( INVALID_INPUT, INVALID_INPUT_MSG );
    const Error DIV_BY_ZERO_ERROR =
        make_error( CALCULATION_ERROR, DIV_BY_ZERO_MSG );
    const Error ROOT_FROM_NEG_ERROR =
        make_error( CALCULATION_ERROR, ROOT_FROM_NEG_MSG );

    std::optional<double> read_value( std::istream& in ) {
        double value;
        if ( in >> value ) { return value; }

        return std::optional<double>{};
    }

    double get_value( const Number& coeff ) { return coeff.value; }
}

Number
make_number( const double value, const Error& error, const bool is_null ) {
    return Number( value, error, is_null );
}

Number input_number( std::istream& in ) {
    std::optional<double> number = read_value( in );

    if ( !number.has_value() ) {
        return make_number( ZERO, INVALID_INPUT_ERROR, true );
    }

    return make_number( number.value() );
}

Error get_error( const Number& number ) { return number.error; }

bool is_null( const Number& coeff ) { return coeff.is_null; }

bool is_equal( const Number& left, const Number& right ) {
    return get_value( left ) == get_value( right );
}

bool is_lower_than( const Number& left, const Number& right ) {
    return get_value( left ) < get_value( right );
}

Number neg( const Number& operand ) {
    double value = get_value( operand );
    return make_number( -value );
}

Number add( const Number& augend, const Number& addend ) {
    double sum = get_value( augend ) + get_value( addend );
    return make_number( sum );
}

Number sub( const Number& minuend, const Number& subtrahend ) {
    double difference = get_value( minuend ) - get_value( subtrahend );
    return make_number( difference );
}

Number mul( const Number& multiplicand, const Number& multiplier ) {
    double product = get_value( multiplicand ) * get_value( multiplier );
    return make_number( product );
}

Number div( const Number& dividend, const Number& divisor ) {
    double dividend_value = get_value( dividend );
    double divisor_value = get_value( divisor );

    if ( divisor_value == ZERO ) {
        return make_number( ZERO, DIV_BY_ZERO_ERROR, true );
    }

    return make_number( dividend_value / divisor_value );
}

Number sqrt( const Number& radicand ) {
    double value = get_value( radicand );

    if ( value < ZERO ) {
        return make_number( ZERO, ROOT_FROM_NEG_ERROR, true );
    }

    return make_number( sqrt( value ) );
}

std::string to_string( const Number& coeff ) {
    return std::to_string( get_value( coeff ) );
}
