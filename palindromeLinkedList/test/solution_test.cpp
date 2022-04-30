#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "solution.h"

namespace SolutionTest {

using ::Solution::ListNode;
using ::Solution::Solution;

using testing::Eq;

using is_palendrome_test_t = std::pair<ListNode, bool>;

class IsPalindromeTest : public testing::TestWithParam<is_palendrome_test_t> {
 public:
  void SetUp() override {
    solution = Solution();
    is_palendrome_test_t param = GetParam();
    list_node = param.first;
    expected_outcome = param.second;
  };

 protected:
  Solution solution;
  ListNode list_node;
  bool expected_outcome;
};

TEST_P(IsPalindromeTest, isPalendromeTest) {
  EXPECT_THAT(solution.isPalindrome(&list_node), Eq(expected_outcome));
}

INSTANTIATE_TEST_SUITE_P(SolutionTest, IsPalindromeTest, testing::Values(
    is_palendrome_test_t({1}, true),
    is_palendrome_test_t({1,2,2,1}, true),
    is_palendrome_test_t({1,2}, false),
    is_palendrome_test_t({1,3,4,3,1}, true)
    ));


} // namespace SolutionTest