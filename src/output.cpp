#include "../include/output.h"

#include <ostream>

const std::string FIRST_ROOT_MSG = "X1 = ";
const std::string SECOND_ROOT_MSG = "X2 = ";
const std::string SINGLE_ROOT_MSG = "X = ";
const std::string INF_ROOTS_MSG = "Бесконечное множество решений!";
const std::string NO_ROOTS_MSG = "Нет корней!";

namespace {
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

    void output_two_roots( std::ostream& destination,
                           const Solution& solution ) {
        Number x1 = get_first_root( solution );
        Number x2 = get_second_root( solution );

        destination << FIRST_ROOT_MSG << to_string( x1 ) << std::endl;
        destination << SECOND_ROOT_MSG << to_string( x2 ) << std::endl;
    }

    void output_single_root( std::ostream& destination,
                             const Solution& solution ) {
        Number x = get_first_root( solution );

        destination << SINGLE_ROOT_MSG << to_string( x ) << std::endl;
    }

    void output_inf_roots( std::ostream& destination ) {
        destination << INF_ROOTS_MSG << std::endl;
    }

    void output_no_roots( std::ostream& destination ) {
        destination << NO_ROOTS_MSG << std::endl;
    }

    void output_solution( std::ostream& destination,
                          const Solution& solution ) {
        SolutionType type = get_solution_type( solution );

        if ( type == TWO_ROOTS ) {
            output_two_roots( destination, solution );
        }

        else if ( type == ONE_ROOT ) {
            output_single_root( destination, solution );
        }

        else if ( type == INF_ROOTS ) {
            output_inf_roots( destination );
        }

        else {
            output_no_roots( destination );
        }
    }
}

void output( std::ostream& destination, const Solution& solution ) {
    if ( has_error( solution ) ) {
        output_error_solution( destination, solution );
        return;
    }

    output_solution( destination, solution );
}
