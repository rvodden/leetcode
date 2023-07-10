#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "list_node.h"

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

    ListNode listNode = {1};
    EXPECT_EQ(listNode.next, nullptr);
    EXPECT_EQ(listNode.val, 1);

    EXPECT_EQ(ListNode({1, 2}).next->next, nullptr);
    EXPECT_EQ(ListNode({1, 2}).val, 1);
    EXPECT_EQ(ListNode({1, 2}).next->val, 2);

    EXPECT_EQ(ListNode(ListNode({1, 2})).next->next, nullptr);
    EXPECT_EQ(ListNode(ListNode({1, 2})).val, 1);
    EXPECT_EQ(ListNode(ListNode({1, 2})).next->val, 2);

    listNode = {1, 2};
    EXPECT_EQ(listNode.next->next, nullptr);
    EXPECT_EQ(listNode.val, 1);
    EXPECT_EQ(listNode.next->val, 2);

    EXPECT_EQ(SolutionTest::count_elements({1,2,2,1}), 4);
    EXPECT_EQ(SolutionTest::count_elements({1,2,2,1,2,2,2,1,2,2,2,2,1}), 13);
}

}