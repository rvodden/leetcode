#include "middle_of_the_linked_list.h"

namespace Solution {

ListNode* Solution::middleNode(ListNode* head) {
    ListNode* fast = head;


    while(true) {
        if(fast == nullptr) break;
        if(fast->next == nullptr) break;
        head = head->next;
        fast = fast->next->next;
    }

    return head;
};

} // namespace Solution