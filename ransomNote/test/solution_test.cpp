#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "solution.h"

namespace SolutionTest {

using ::Solution::Solution;

using std::get;
using std::string;

using ransom_note_test_t = std::tuple<std::string, std::string, bool>;

class RansomNoteTest : public testing::TestWithParam<ransom_note_test_t> {
    void SetUp() override {
        ransom_note_test_t param = GetParam();
        ransomNote = get<0>(param);
        magazine = get<1>(param);
        expectedResponse = get<2>(param);
    }

    protected:
        Solution solution;

        std::string ransomNote;
        std::string magazine;

        bool expectedResponse;
};

TEST_P(RansomNoteTest, ransomNoteTest) {
    EXPECT_EQ(solution.canConstruct(ransomNote, magazine), expectedResponse);
};

INSTANTIATE_TEST_SUITE_P(SolutionTest, RansomNoteTest, testing::Values(
    ransom_note_test_t({"a", "b", false}),
    ransom_note_test_t({"aa", "ab", false}),
    ransom_note_test_t({"aa", "aab", true})
));

} // namespace SolutionTest