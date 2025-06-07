#include <cmath>
#include <optional>

#include "big_number.hpp"
#include "constants.cpp"
#include "constants.hpp"
#include "error.hpp"
#include "input.hpp"
#include "number.hpp"

Error convert_error( const big_number::BigNumber& value ) {
    big_number::Error error = big_number::get_error( value );
    return make_error( (ErrorCode)big_number::get_error_code( error ),
                       big_number::get_error_message( error ) );
}

big_number::BigNumber get_value( const Number& coeff ) { return coeff.value; }

Number make_number( big_number::BigNumber value, const Error& error ) {
    return Number{ value, error };
}

Number input_number() {
    std::optional<big_number::BigNumber> number = read_value();

    if ( !number.has_value() )
        return make_number( Numeric::ZERO, NumberErrors::INVALID_INPUT );

    return make_number( number.value(), Errors::OK );
}

const Error& get_error( const Number& number ) { return number.error; }

bool is_equal( const Number& left, const Number& right ) {
    return big_number::is_equal( get_value( left ), get_value( right ) );
}

bool is_lower_than( const Number& left, const Number& right ) {
    return big_number::is_lower_than( get_value( left ), get_value( right ) );
}

Number neg( const Number& operand ) {
    big_number::BigNumber value = get_value( operand );
    return make_number( big_number::neg( value ), convert_error( value ) );
}

Number add( const Number& augend, const Number& addend ) {
    big_number::BigNumber sum =
        big_number::add( get_value( augend ), get_value( addend ) );
    return make_number( sum, convert_error( sum ) );
}

Number sub( const Number& minuend, const Number& subtrahend ) {
    big_number::BigNumber diff =
        big_number::sub( get_value( minuend ), get_value( subtrahend ) );
    return make_number( diff, convert_error( diff ) );
}

Number mul( const Number& multiplicand, const Number& multiplier ) {
    big_number::BigNumber product =
        big_number::mul( get_value( multiplicand ), get_value( multiplier ) );

    return make_number( product, convert_error( product ) );
}

Number div( const Number& dividend, const Number& divisor ) {
    big_number::BigNumber div =
        big_number::div( get_value( dividend ), get_value( divisor ) );

    Error error = convert_error( div );

    return make_number( div, error );
}

Number sqrt( const Number& radicand ) {
    big_number::BigNumber root = big_number::sqrt( get_value( radicand ) );
    Error error = convert_error( root );

    return make_number( root, error );
}

std::string to_string( const Number& coeff ) {
    return big_number::to_string( get_value( coeff ) );
}
