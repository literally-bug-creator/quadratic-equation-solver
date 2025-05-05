#include <iostream>
#include <string>

inline std::ostream& OUTPUT_STREAM = std::cout;
const std::string NEW_LINE = "\n";

namespace OutputMessages {
    const std::string UNKNOWN_SOLUTION_TYPE = "Неизвестный тип решения!";
    const std::string FIRST_ROOT = "X1 = ";
    const std::string SECOND_ROOT = "X2 = ";
    const std::string SINGLE_ROOT = "X = ";
    const std::string INF_ROOTS = "Бесконечное множество решений!";
    const std::string NO_ROOTS = "Нет корней!";
}
