#include <cstddef>
#include <iostream>
#include <string>

#include "constants.cpp"
#include "error.hpp"
#include "number.hpp"
#include "output.hpp"
#include "solution.hpp"

std::string build_solution_type_msg( const Solution& solution ) {
    switch ( get_solution_type( solution ) ) {
    case SolutionType::INF_ROOTS:
        return OutputMessages::INF_ROOTS;

    case SolutionType::NO_ROOTS:
        return OutputMessages::NO_ROOTS;

    default:
        return EMPTY_STR;
    }
}

bool is_roots_equals( std::vector<Number> roots ) {
    if ( roots.empty() ) return false;
    if ( roots.size() == ONE ) return true;

    for ( size_t index = ONE; index < roots.size(); index++ ) {
        if ( !is_equal( roots[index], roots[index - ONE] ) ) return false;
    }

    return true;
}

std::string get_no_index_root_msg( const Number& root ) {
    return X_STR + EQUAL_SIGN_STR + to_string( root );
}

std::string get_index_root_msg( const Number& root, size_t index ) {
    return X_STR + std::to_string( index ) + EQUAL_SIGN_STR + to_string( root );
}

std::string build_root_msg( const Number& root,
                            size_t index = OUTBOUND_INDEX ) {
    if ( index == OUTBOUND_INDEX ) return get_no_index_root_msg( root );
    return get_index_root_msg( root, index );
}

std::string build_solution_roots_msg( const Solution& solution ) {
    std::vector<Number> roots = get_roots( solution );

    if ( is_roots_equals( roots ) ) return build_root_msg( roots[ZERO] );

    std::string msg = EMPTY_STR;

    for ( size_t index = ZERO; index < roots.size(); index++ ) {
        msg += build_root_msg( roots[index], index + ONE );

        if ( index < roots.size() - ONE ) msg += NEW_LINE;
    }

    return msg;
}

std::string get_error_msg( const Solution& solution ) {
    const Error& error = get_error( solution );
    return get_error_message( error );
}

bool has_error( const Solution& solution ) {
    const Error& error = get_error( solution );
    return !is_ok( error );
}

std::string build_solution_msg( const std::string& type_msg,
                                const std::string& roots_msg ) {
    if ( type_msg.empty() ) return roots_msg;
    return type_msg;
}

std::string build_solution_msg( const Solution& solution ) {
    if ( has_error( solution ) ) { return get_error_msg( solution ); }

    std::string type_msg = build_solution_type_msg( solution );
    std::string roots_msg = build_solution_roots_msg( solution );

    return build_solution_msg( type_msg, roots_msg );
}

void output_string( const std::string& str ) {
    OUTPUT_STREAM << str << std::endl;
}

void output( const Solution& solution ) {
    std::string msg = build_solution_msg( solution );
    output_string( msg );
}
