#include "solution.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace SolutionTest {

using Solution::Solution;

using testing::Eq;

typedef std::pair<std::string, int> roman_to_int_t;

class RomanToIntegerTest : public testing::TestWithParam<roman_to_int_t> {
 public:
  void SetUp() override {
    solution = Solution();
    roman_to_int_t pair = GetParam();
    roman_string = pair.first;
    expected_result = pair.second;
  };

 protected:
  Solution solution;
  std::string roman_string;
  int expected_result;
};

TEST_P(RomanToIntegerTest, romanToInt) {
  EXPECT_THAT(solution.romanToInt(roman_string), Eq(expected_result));
}

INSTANTIATE_TEST_SUITE_P(MazeTest, RomanToIntegerTest, testing::Values(
    roman_to_int_t({"I"}, 1),
    roman_to_int_t({"III", 3}),
    roman_to_int_t({"LVIII", 58}),
    roman_to_int_t({"MCMXCIV", 1994})
));

} // namespace SolutionTest