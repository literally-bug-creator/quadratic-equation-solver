#include <coefficients.hpp>
#include <gtest/gtest.h>
#include <tuple>

class ArithmeticTest : public testing::TestWithParam<
                           std::tuple<std::string, std::string, std::string>> {
};
