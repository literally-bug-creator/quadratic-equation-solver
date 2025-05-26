#include <cmath>
#include <optional>

#include "constants.cpp"
#include "constants.hpp"
#include "input.hpp"
#include "number.hpp"

double get_value( const Number& coeff ) { return coeff.value; }

Number make_number( double value, const Error& error ) {
    return Number{ value, error };
}

Number input_number() {
    std::optional<double> number = read_value();

    if ( !number.has_value() ) {
        return make_number( Numeric::ZERO, NumberErrors::INVALID_INPUT );
    }

    return make_number( number.value(), Errors::OK );
}

const Error& get_error( const Number& number ) { return number.error; }

bool is_equal( const Number& left, const Number& right ) {
    return get_value( left ) == get_value( right );
}

bool is_greater_than( const Number& left, const Number& right ) {
    return get_value( left ) > get_value( right );
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

    if ( divisor_value == Numeric::ZERO ) {
        return make_number( Numeric::ZERO, NumberErrors::DIV_BY_ZERO );
    }

    return make_number( dividend_value / divisor_value, Errors::OK );
}

Number sqrt( const Number& radicand ) {
    double value = get_value( radicand );

    if ( value < Numeric::ZERO ) {
        return make_number( Numeric::ZERO, NumberErrors::ROOT_FROM_NEG );
    }

    return make_number( sqrt( value ), Errors::OK );
}

std::string to_string( const Number& coeff ) {
    return std::to_string( get_value( coeff ) );
}
