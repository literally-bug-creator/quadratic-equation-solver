#include "solution.hpp"
#include <any>

#include "error.hpp"
#include "number.hpp"
#include "selector.hpp"

Selector get_selector( const Solution& solution ) {
    std::function<std::any( int index )> field =
        [solution]( int index ) -> std::any {
        if ( index == 0 ) {
            return std::any( solution.first.first );
        } else if ( index == 1 ) {
            return std::any( solution.first.second );
        } else if ( index == 2 ) {
            return std::any( solution.second.first );
        } else {
            return std::any( solution.second.second );
        }
    };

    return field;
}

const Solution make_solution( const SolutionType& type,
                              const Number& first_root,
                              const Number& second_root,
                              const Error& error ) {
    return Solution( { type, first_root }, { second_root, error } );
}

SolutionType get_solution_type( const Solution& solution ) {
    return std::any_cast<SolutionType>(get_selector(solution)(0));
}

const Number get_first_root( const Solution& solution ) {
    return std::any_cast<Number>(get_selector(solution)(1));
}

const Number get_second_root( const Solution& solution ) {
    return std::any_cast<Number>(get_selector(solution)(2));
}

const Error get_error( const Solution& solution ) {
    return std::any_cast<Error>(get_selector(solution)(3));
}

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
