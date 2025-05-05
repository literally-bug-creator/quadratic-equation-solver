#include <iostream>
#include <string>

#include "constants.cpp"
#include "error.hpp"
#include "number.hpp"
#include "output.hpp"
#include "solution.hpp"

bool has_error( const Solution& solution ) {
    Error error = get_error( solution );
    return get_error_code( error ) != ErrorCode::OK; // TODO: Fix abst. leak
}

std::string get_single_root_solution_message( const Solution& solution ) {
    Number x = get_first_root( solution );
    return OutputMessages::SINGLE_ROOT + to_string( x );
}

std::string get_two_roots_solution_message( const Solution& solution ) {
    Number x1 = get_first_root( solution );
    Number x2 = get_second_root( solution );

    std::string first_root_msg = OutputMessages::FIRST_ROOT + to_string( x1 );
    std::string second_root_msg = OutputMessages::SECOND_ROOT + to_string( x2 );

    return first_root_msg + "\n" + second_root_msg +
           "\n"; // TODO: Fix abst. level leak
}

std::string get_error_message( const Solution& solution ) {
    Error error = get_error( solution );
    return get_error_message( error );
}

std::string get_solution_message( const Solution& solution ) {
    if ( has_error( solution ) ) { return get_error_message( solution ); }

    SolutionType type = get_solution_type( solution );

    switch ( type ) {
    case SolutionType::TWO_ROOTS:
        return get_two_roots_solution_message( solution );

    case SolutionType::SINGLE_ROOT:
        return get_single_root_solution_message( solution );

    case SolutionType::NO_ROOTS:
        return OutputMessages::NO_ROOTS;

    case SolutionType::INF_ROOTS:
        return OutputMessages::INF_ROOTS;

    default:
        return OutputMessages::UNKNOWN_SOLUTION_TYPE;
    }
}

void output_string( const std::string& str ) {
    OUTPUT_STREAM << str << std::endl;
}

void output( const Solution& solution ) {
    std::string message = get_solution_message( solution );
    output_string( message );
}
