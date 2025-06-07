#include "solution.hpp"

#include "error.hpp"
#include "numbers.hpp"

const Solution make_solution( const SolutionType& type,
                              const Numbers& first_root,
                              const Numbers& second_root,
                              const Error& error ) {
    return Solution{ type, first_root, second_root, error };
}

const SolutionType& get_solution_type( const Solution& solution ) {
    return solution.type;
}

std::vector<Numbers> get_roots( const Solution& solution ) {
    return std::vector<Numbers>{ solution.x1, solution.x2 };
}

const Error& get_error( const Solution& solution ) { return solution.error; }

bool is_equal( const SolutionType a, const SolutionType b ) { return a == b; }
