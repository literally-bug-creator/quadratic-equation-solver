#include "../include/output.h"

#include <iostream>

const std::string FIRST_ROOT_MSG = "X1 = ";
const std::string SECOND_ROOT_MSG = "X2 = ";
const std::string ONE_ROOT_MSG = "X = ";
const std::string ANY_ROOT_MSG = "Бесконечное множество решений!";
const std::string NO_ROOT_MSG = "Нет корней!";

void output_invalid_solution( const Solution& solution ) {
    std::string msg = get_error_msg( solution );
    std::cout << msg << std::endl;
}

void output_quadratic_solution( const Solution& solution ) {
    Coefficient x1 = get_first_root( solution );
    Coefficient x2 = get_second_root( solution );

    std::cout << FIRST_ROOT_MSG << to_string( x1 ) << std::endl;
    std::cout << SECOND_ROOT_MSG << to_string( x2 ) << std::endl;
}

void output_linear_solution( const Solution& solution ) {
    Coefficient x1 = get_first_root( solution );

    std::cout << ONE_ROOT_MSG << to_string( x1 ) << std::endl;
}

void output_any_root_solution() { std::cout << ANY_ROOT_MSG << std::endl; }

void output_no_root_solution() { std::cout << NO_ROOT_MSG << std::endl; }

void output( const Solution& solution ) {
    if ( !is_valid( solution ) ) {
        output_invalid_solution( solution );
        return;
    }

    SolutionType type = get_solution_type( solution );

    if ( type == QUADRATIC ) {
        output_quadratic_solution( solution );
    }

    else if ( type == LINEAR ) {
        output_linear_solution( solution );
    }

    else if ( type == ANY_ROOT ) {
        output_any_root_solution();
    }

    else {
        output_no_root_solution();
    }
}
