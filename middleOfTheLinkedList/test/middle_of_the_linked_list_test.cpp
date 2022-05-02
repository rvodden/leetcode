#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "middle_of_the_linked_list.h"
#include "list_node.h"

#include <string>

namespace SolutionTest {

using ::Solution::ListNode;
using ::Solution::Solution;

using testing::StrEq;

using middle_node_test_t = std::pair<ListNode, std::string>;

class MiddleNodeTest: public testing::TestWithParam<middle_node_test_t> {
 public:
  void SetUp() override {
    solution = Solution();
    middle_node_test_t param = GetParam();
    list_node = param.first;
    expected_outcome = param.second;
  };

 protected:
  Solution solution;
  ListNode list_node;
  std::string expected_outcome;
};

TEST_P(MiddleNodeTest, middleNodeTest) {
  EXPECT_THAT(solution.middleNode(&list_node)->to_string(), StrEq(expected_outcome));
}

INSTANTIATE_TEST_SUITE_P(SolutionTest, MiddleNodeTest, testing::Values(
    middle_node_test_t({1,2,3,4,5}, "{3,4,5}"),
    middle_node_test_t({1,2,3,4,5,6}, "{4,5,6}")
    ));


} // namespace SolutionTest