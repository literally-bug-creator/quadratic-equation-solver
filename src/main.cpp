#include "../include/coefficient_set.h"
#include "../include/solution.h"
#include "../include/output.h"


int main(){
    CoefficientSet coeffs = input_coefficient_set();
    Solution solution = get_solution(coeffs);
    output(solution);
}
