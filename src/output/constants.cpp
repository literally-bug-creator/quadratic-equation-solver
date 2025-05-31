#include <cstddef>
#include <iostream>
#include <string>

inline std::ostream& OUTPUT_STREAM = std::cout;
const std::string NEW_LINE = "\n";
const std::string EMPTY_STR = "";
const std::string X_STR = "X";
const std::string EQUAL_SIGN_STR = " = ";
const size_t OUTBOUND_INDEX = -1;
const size_t ONE = 1;
const size_t ZERO = 0;

namespace OutputMessages {
    const std::string UNKNOWN_SOLUTION_TYPE = "Неизвестный тип решения!";
    const std::string INF_ROOTS = "Бесконечное множество решений!";
    const std::string NO_ROOTS = "Нет корней!";
}
