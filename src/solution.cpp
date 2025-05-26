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

const Number& get_first_root( const Solution& solution ) { return solution.x1; }

const Number& get_second_root( const Solution& solution ) {
    return solution.x2;
}

const Error& get_error( const Solution& solution ) { return solution.error; }

bool is_equal( const SolutionType a, const SolutionType b ) { return a == b; }

bool has_two_roots( const Solution& solution ) {
    return is_equal( get_solution_type( solution ), SolutionType::TWO_ROOTS );
}

bool has_two_same_roots( const Solution& solution ) {
    return is_equal( get_solution_type( solution ),
                     SolutionType::TWO_SAME_ROOTS );
}

bool has_single_root( const Solution& solution ) {
    return is_equal( get_solution_type( solution ), SolutionType::SINGLE_ROOT );
}

bool has_no_roots( const Solution& solution ) {
    return is_equal( get_solution_type( solution ), SolutionType::NO_ROOTS );
}

bool has_inf_roots( const Solution& solution ) {
    return is_equal( get_solution_type( solution ), SolutionType::INF_ROOTS );
}
