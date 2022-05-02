#include "middle_of_the_linked_list.h"

namespace Solution {

ListNode* Solution::middleNode(ListNode* head) {
    ListNode* fast = head->next;

    while (fast != nullptr and fast->next != nullptr) {
        head = head->next;
        fast = fast->next->next;
    }

    if(fast != nullptr) {
        return head->next;
    }

    return head;
};

} // namespace Solution