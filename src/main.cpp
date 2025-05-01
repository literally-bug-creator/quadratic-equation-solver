#include <iostream>

#include "../include/number_kit.h"
#include "../include/output.h"
#include "../include/solution.h"

int main() {
    NumberKit nums = input_number_kit( std::cin );
    Solution solution = get_solution( nums );
    output( solution );
}
