#include "input.hpp"
#include "equation_coefficients.hpp"
#include "output.hpp"
#include "solution.hpp"

int main() {
    EquationCoefficients coeffs = input_equation_coefficients( INPUT_STREAM ); // Rename interface
    Solution solution = get_solution( coeffs ); // Не "получить решение", а "решить"
    output( solution );
}
