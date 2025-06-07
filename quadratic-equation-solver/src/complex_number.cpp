
#include "complex_number.hpp"

#include <string>

#include "error.hpp"

const std::string I = "i";

ComplexNumber make_complex_number( Number real_part,
                                   Number imaginary_part,
                                   const Error& error ) {
    return ComplexNumber{ .real_part = real_part,
                          .imaginary_part = imaginary_part,
                          .error = error };
}

const Error& get_error( const ComplexNumber& number ) { return number.error; }

const Number& get_real_part( const ComplexNumber& number ) {
    return number.real_part;
}

const Number& get_imaginary_part( const ComplexNumber& number ) {
    return number.imaginary_part;
}

bool is_equal( const ComplexNumber& left, const ComplexNumber& right ) {
    return is_equal( get_real_part( left ), get_real_part( right ) ) &&
           is_equal( get_imaginary_part( left ), get_imaginary_part( right ) );
}

std::string to_string( const ComplexNumber& number ) {
    return to_string( get_real_part( number ) ) +
           to_string( get_imaginary_part( number ) ) + I;
}
