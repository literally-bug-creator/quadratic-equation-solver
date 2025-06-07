#include <coefficients.hpp>
#include <gtest/gtest.h>
#include <tuple>

class EquationTest : public testing::TestWithParam<
                           std::tuple<std::string, std::string, std::string>> {
};
