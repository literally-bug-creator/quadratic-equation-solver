#include "coefficients.hpp"
#include "output.hpp"
#include "solver.hpp"

int main() {
    Coefficients coeffs = input_coefficients();
    Solution solution = solve_equation( coeffs );
    output( solution );
}
