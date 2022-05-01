#include "solution.h"

namespace Solution {

bool Solution::isPalindrome(ListNode *head) {

  /**
   * To check for palindromes we need to compare the
   * first element with the last element
   * then the first but on element with the last but one
   * 
   * etc..
   * 
   * However with a singly linked list we can only go
   * in one direction.
   * 
   * We will therefore set about reversing the order of the 
   * list so that we can go backwards. Whilst we're doing 
   * that we'll set a pointer off twice as fast as the reversal
   * process. When that pointer hits the end, our reversal will be 
   * half way. We can then set about comparing.
   */

  ListNode* prev = nullptr;
  ListNode* next = nullptr;
  ListNode* slow = head;
  ListNode* fast = head->next;

  while(fast && fast->next){
      // reverse the list at "slow"
      next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;

      // double increment fast
      fast = fast->next->next;
  }
  
  /* if fast gets to the penultimate element
   * then we have an odd number of elements in our 
   * list. We need to point slow at the element before the middle 
   * and fast at the element after.
   */
  if(fast && !fast->next){
      next = slow->next;
      slow->next = prev;
      fast = next;
  }

  /* if fast gets to the end then we have an even number of
   * elements in our list. So we point slow at the middle
   * and fast at the element after */
  if(!fast){
      fast = slow->next;
      slow = prev;
  }
  
  /* now simply compare and see if we have a palindrome */
  while(slow){
      if(slow->val != fast->val)
          return false;
      slow = slow->next;
      fast = fast->next;
  }

  return true;

}



} // namespace Solution