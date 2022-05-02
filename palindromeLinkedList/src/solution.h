//
// Created by Richard Vodden on 26/04/2022.
//

#ifndef LEETCODE_PALINDROMELINKEDLIST_SRC_SOLUTION_H_
#define LEETCODE_PALINDROMELINKEDLIST_SRC_SOLUTION_H_

#include <initializer_list>
#include <vector>

#include "list_node.h"

namespace Solution {

std::ostream& operator<<(std::ostream&, ListNode const* const);
std::ostream& operator<<(std::ostream&, ListNode const&);

class Solution {
 public:
  bool isPalindrome(ListNode* head);
};

} // namespace Solution

#endif //LEETCODE_PALINDROMELINKEDLIST_SRC_SOLUTION_H_
