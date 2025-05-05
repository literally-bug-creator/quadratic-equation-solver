#include "output.hpp"

#include <iostream>

#include "output_constants.cpp"
#include "solution.hpp"

std::ostream& OUTPUT_STREAM = std::cout;

bool has_error( const Solution& solution ) {
    Error error = get_error( solution );
    return get_error_code( error ) != OK;
}

void output_error_solution( std::ostream& destination,
                            const Solution& solution ) {
    Error error = get_error( solution );
    std::string error_msg = get_error_message( error );

    destination << error_msg << std::endl;
}

void output_two_roots( std::ostream& destination, const Solution& solution ) {
    Number x1 = get_first_root( solution );
    Number x2 = get_second_root( solution );

    destination << OutputMessages::FIRST_ROOT << to_string( x1 ) << std::endl;
    destination << OutputMessages::SECOND_ROOT << to_string( x2 ) << std::endl;
}

void output_single_root( std::ostream& destination, const Solution& solution ) {
    Number x = get_first_root( solution );

    destination << OutputMessages::SINGLE_ROOT << to_string( x ) << std::endl;
}

void output_inf_roots( std::ostream& destination ) {
    destination << OutputMessages::INF_ROOTS << std::endl;
}

void output_no_roots( std::ostream& destination ) {
    destination << OutputMessages::NO_ROOTS << std::endl;
}

void output_solution( std::ostream& destination, const Solution& solution ) {
    SolutionType type = get_solution_type( solution );

    if ( type == SolutionType::TWO_ROOTS ) {
        output_two_roots( destination, solution );
    }

    else if ( type == SolutionType::SINGLE_ROOT ) {
        output_single_root( destination, solution );
    }

    else if ( type == SolutionType::INF_ROOTS ) {
        output_inf_roots( destination );
    }

    else {
        output_no_roots( destination );
    }
}

void output( std::ostream& destination, const Solution& solution ) {
    if ( has_error( solution ) ) {
        output_error_solution( destination, solution );
        return;
    }

    output_solution( destination, solution );
}
