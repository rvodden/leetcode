#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "k_weakest_rows.h"

namespace SolutionTest {

using ::Solution::Solution;

using std::vector;

using testing::ContainerEq;

using row_int_test_t = std::tuple<std::vector<int>, int>;

class RowIntTest : public testing::TestWithParam<row_int_test_t>{  
    void SetUp() override {
        row_int_test_t param = GetParam();

        input = std::get<0>(param);
        expected_output = std::get<1>(param);
    }

  protected:
    std::vector<int> input;
    int expected_output;
};

class RankTest : public RowIntTest {};

TEST_P(RankTest, rankTest) {
    EXPECT_EQ(Solution::rank(input), expected_output);
}

INSTANTIATE_TEST_SUITE_P(SolutionTest, RankTest, testing::Values(
    row_int_test_t({1,1,0,0,0}, 2),
    row_int_test_t({1,1,1,0,0}, 3),
    row_int_test_t({1,1,1,1,0}, 4)
));

using k_weakest_rows_test_t = std::tuple<vector<vector<int>>, int, vector<int>>;

class KWeakestRowsTest : public testing::TestWithParam<k_weakest_rows_test_t> {
    void SetUp() override {
        k_weakest_rows_test_t param = GetParam();
        mat = std::get<0>(param);
        num_elements = std::get<1>(param);
        expected_outcome = std::get<2>(param);
    }

    protected:
        vector<vector<int>> mat;
        int num_elements;
        vector<int> expected_outcome;

        Solution solution;
};


TEST_P(KWeakestRowsTest, kWeastestRowsTest) {
    EXPECT_THAT(solution.kWeakestRows(mat, num_elements), ContainerEq(expected_outcome));
};

INSTANTIATE_TEST_SUITE_P(SolutionTest, KWeakestRowsTest, testing::Values(
    k_weakest_rows_test_t({
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    }, 3, {2,0,3}),
    k_weakest_rows_test_t({
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}
    }, 2, {0,2})
));

} // namespace SolutionTest