#include "solution.h"

namespace Solution {

bool Solution::isPalindrome(ListNode *head) {

  /* calculate the number of elements
   * and find the last row
   */
  int number_of_elements = 1;
  ListNode* tail = head;
  while(tail->next != nullptr) {
    tail = tail->next;
    number_of_elements++;
  }

  switch (number_of_elements) {
    case 1:
      return true;
    case 2:
      return (head->val == head->next->val);
    case 3:
      return (head->val == head->next->next->val);
  }

  int middle_element_index = number_of_elements / 2;
  ListNode* prev;
  tail = head;

  for ( int current_index = 0; current_index < middle_element_index; current_index++) {
    prev = tail;
    tail = tail->next;
  }
  ListNode* next;

  // snap off the tail from the rest of the ListNode:
  prev->next = nullptr;
  prev = tail;
  tail = tail->next;
  prev->next = nullptr;
  next = tail->next;

  // reverse the order of tail
  while(next != nullptr) {
    tail->next = prev;
    prev = tail;
    tail = next;
    next = next->next;
  }
  tail->next = prev;

  // check for palindromeness

  while(tail != nullptr and head != nullptr) {
    if (tail->val != head->val)  return false;
    
    head = head->next;
    tail = tail->next;
  }

  return true;
}

} // namespace Solution