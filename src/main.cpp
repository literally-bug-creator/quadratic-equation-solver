#include "input.hpp"
#include "number_kit.hpp"
#include "output.hpp"
#include "solution.hpp"

int main() {
    NumberKit nums = input_number_kit( INPUT_STREAM ); // Rename interface
    Solution solution = get_solution( nums ); // Не "получить решение", а "решить"
    output( OUTPUT_STREAM, solution );
}
