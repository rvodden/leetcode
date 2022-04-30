#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "solution.h"

namespace SolutionTest {

using Solution::ListNode;

int count_elements(ListNode listNode) {
    int element_count = 0;
    ListNode* head = &listNode;
    while(head != nullptr) {
        element_count++;
        head = head->next;
    }
    return element_count;
}

TEST(listNode, testCreation) {
    EXPECT_EQ(ListNode({1}).next, nullptr);
    EXPECT_EQ(ListNode({1}).val, 1);

    EXPECT_EQ(ListNode(ListNode({1})).next, nullptr);
    EXPECT_EQ(ListNode(ListNode({1})).val, 1);

    ListNode l = {1};
    EXPECT_EQ(l.next, nullptr);
    EXPECT_EQ(l.val, 1);

    EXPECT_EQ(ListNode({1, 2}).next->next, nullptr);
    EXPECT_EQ(ListNode({1, 2}).val, 1);
    EXPECT_EQ(ListNode({1, 2}).next->val, 2);

    EXPECT_EQ(ListNode(ListNode({1, 2})).next->next, nullptr);
    EXPECT_EQ(ListNode(ListNode({1, 2})).val, 1);
    EXPECT_EQ(ListNode(ListNode({1, 2})).next->val, 2);

    l = {1, 2};
    EXPECT_EQ(l.next->next, nullptr);
    EXPECT_EQ(l.val, 1);
    EXPECT_EQ(l.next->val, 2);

    EXPECT_EQ(SolutionTest::count_elements({1,2,2,1}), 4);
    EXPECT_EQ(SolutionTest::count_elements({1,2,2,1,2,2,2,1,2,2,2,2,1}), 13);
}

}