#ifndef LISTNODE_H
#define LISTNODE_H

#include <string>
#include <initializer_list>
#include <utility>

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

    std::string to_string() const;

    int val;
    ListNode *next;
};

std::ostream& operator<<(std::ostream& os, ListNode const* const);
std::ostream& operator<<(std::ostream& os, ListNode const&);

} // namespace Solution

#endif // LISTNODE_H