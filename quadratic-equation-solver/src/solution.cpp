#include "solution.hpp"

#include "error.hpp"
#include "number.hpp"

const Solution make_solution( const SolutionType& type,
                              const Number& first_root,
                              const Number& second_root,
                              const Error& error ) {
    return Solution{ type, first_root, second_root, error };
}

const SolutionType& get_solution_type( const Solution& solution ) {
    return solution.type;
}

std::vector<Number> get_roots( const Solution& solution ) {
    return std::vector<Number>{ solution.x1, solution.x2 };
}

const Error& get_error( const Solution& solution ) { return solution.error; }

bool is_equal( const SolutionType a, const SolutionType b ) { return a == b; }
