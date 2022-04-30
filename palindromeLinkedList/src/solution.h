//
// Created by Richard Vodden on 26/04/2022.
//

#ifndef LEETCODE_PALINDROMELINKEDLIST_SRC_SOLUTION_H_
#define LEETCODE_PALINDROMELINKEDLIST_SRC_SOLUTION_H_

#include <initializer_list>
#include <vector>

namespace Solution {

class ListNode{
  public:
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
    ListNode(std::initializer_list<int>);

    ListNode(ListNode const&); // copy
    ListNode(ListNode&& other) noexcept : val(other.val), next(std::exchange(other.next, nullptr)) {}; // move

    ~ListNode();

    ListNode& operator=(ListNode const&); // copy
    ListNode& operator=(ListNode&& other) noexcept; // move


    int val;
    ListNode *next;
};


std::ostream& operator<<(std::ostream&, ListNode const* const);
std::ostream& operator<<(std::ostream&, ListNode const&);

class Solution {
 public:
  bool isPalindrome(ListNode* head);
};

} // namespace Solution

#endif //LEETCODE_PALINDROMELINKEDLIST_SRC_SOLUTION_H_
