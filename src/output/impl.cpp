#include <iostream>
#include <string>

#include "constants.cpp"
#include "error.hpp"
#include "number.hpp"
#include "output.hpp"
#include "solution.hpp"

std::string get_unknown_solution_type_msg( const Solution& solution ) {
    return OutputMessages::UNKNOWN_SOLUTION_TYPE;
}

std::string get_no_roots_solution_msg( const Solution& solution ) {
    return OutputMessages::NO_ROOTS;
}

std::string get_inf_roots_solution_msg( const Solution& solution ) {
    return OutputMessages::INF_ROOTS;
}

std::string get_single_root_message( const Number& root ) {
    return OutputMessages::SINGLE_ROOT + to_string( root );
}

std::string get_single_root_solution_msg( const Solution& solution ) {
    return get_single_root_message( get_first_root( solution ) );
}

std::string get_two_same_roots_solution_msg( const Solution& solution ) {
    return get_single_root_message( get_first_root( solution ) );
}

std::string get_two_roots_message( const Number& first_root,
                                   const Number& second_root ) {
    std::string x1_msg = OutputMessages::FIRST_ROOT + to_string( first_root );
    std::string x2_msg = OutputMessages::SECOND_ROOT + to_string( second_root );

    return x1_msg + NEW_LINE + x2_msg;
}

std::string get_two_roots_solution_msg( const Solution& solution ) {
    Number x1 = get_first_root( solution );
    Number x2 = get_second_root( solution );

    return get_two_roots_message( x1, x2 );
}

std::string get_error_msg( const Solution& solution ) {
    Error error = get_error( solution );
    return get_error_message( error );
}

bool has_error( const Solution& solution ) {
    Error error = get_error( solution );
    return !is_ok( error );
}

std::string get_solution_msg( const Solution& solution ) {
    if ( has_error( solution ) ) { return get_error_msg( solution ); }

    if ( has_two_roots( solution ) )
        return get_two_roots_solution_msg( solution );

    else if ( has_two_same_roots( solution ) )
        return get_two_same_roots_solution_msg( solution );

    else if ( has_single_root( solution ) )
        return get_single_root_solution_msg( solution );

    else if ( has_inf_roots( solution ) )
        return get_inf_roots_solution_msg( solution );

    else if ( has_no_roots( solution ) )
        return get_no_roots_solution_msg( solution );

    return get_unknown_solution_type_msg( solution );
}

void output_string( const std::string& str ) {
    OUTPUT_STREAM << str << std::endl;
}

void output( const Solution& solution ) {
    std::string msg = get_solution_msg( solution );
    output_string( msg );
}
