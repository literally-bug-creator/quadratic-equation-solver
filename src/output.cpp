#include "../include/output.h"

#include <iostream>

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

    void output_error_solution( const Solution& solution ) {
        Error error = get_error( solution );
        std::string error_msg = get_error_message( error );

        std::cout << error_msg << std::endl;
    }

    bool has_same_roots( const Solution& solution ) {
        Number x1 = get_first_root( solution );
        Number x2 = get_second_root( solution );

        return is_equal( x1, x2 );
    }

    void output_two_roots( const Solution& solution ) {
        Number x1 = get_first_root( solution );
        Number x2 = get_second_root( solution );

        std::cout << FIRST_ROOT_MSG << to_string( x1 ) << std::endl;
        std::cout << SECOND_ROOT_MSG << to_string( x2 ) << std::endl;
    }

    void output_single_root( const Solution& solution ) {
        Number x = get_first_root( solution );

        std::cout << SINGLE_ROOT_MSG << to_string( x ) << std::endl;
    }

    void output_inf_roots() { std::cout << INF_ROOTS_MSG << std::endl; }

    void output_no_roots() { std::cout << NO_ROOTS_MSG << std::endl; }

    void output_solution( const Solution& solution ) {
        SolutionType type = get_solution_type( solution );

        if ( ( type == TWO_ROOTS ) && ( !has_same_roots( solution ) ) ) {
            output_two_roots( solution );
        }

        else if ( ( type == TWO_ROOTS ) && ( has_same_roots( solution ) ) ) {
            output_single_root( solution );
        }

        else if ( type == ONE_ROOT ) {
            output_single_root( solution );
        }

        else if ( type == INF_ROOTS ) {
            output_inf_roots();
        }

        else {
            output_no_roots();
        }
    }
}

void output( const Solution& solution ) {
    if ( has_error( solution ) ) {
        output_error_solution( solution );
        return;
    }

    output_solution( solution );
}
