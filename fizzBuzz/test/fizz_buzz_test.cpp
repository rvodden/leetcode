#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

#include "fizz_buzz.h"

namespace SolutionTest {

using ::Solution::Solution;
using testing::ContainerEq;

using fizzbuzz_test_t = std::pair<int, std::vector<std::string>>;

class FizzBuzzTest : public testing::TestWithParam<fizzbuzz_test_t> {
    void SetUp() override {
        fizzbuzz_test_t param = GetParam();
        input = param.first;
        expected_solution = param.second;
    }

  protected:
    Solution solution;
    int input;
    std::vector<std::string> expected_solution;

};

TEST_P(FizzBuzzTest, fizzBuzzTest) {
    EXPECT_THAT(solution.fizzBuzz(input), ContainerEq(expected_solution));
};

INSTANTIATE_TEST_SUITE_P(SolutionTest, FizzBuzzTest, testing::Values(
    fizzbuzz_test_t(3, {"1","2","Fizz"}),
    fizzbuzz_test_t(5, {"1","2","Fizz","4","Buzz"})
));

} // namespace SolutionTest