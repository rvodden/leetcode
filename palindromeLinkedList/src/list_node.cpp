#include "solution.h"
#include <iostream>

namespace Solution {

ListNode::ListNode(std::initializer_list<int> list) {
  this->next = nullptr;
  
  const int* it = list.begin();
  this->val = *it;
  it++; 

  ListNode* curr = this;
  while ( it != list.end() ) {
      curr->next = new ListNode(*it);
      it++;
      curr = curr->next;
  };
}

ListNode::~ListNode() {
  delete next;
}

ListNode::ListNode(ListNode const& list) {
  this->next = nullptr;
  
  ListNode const* it = &list;
  this->val = it->val;
  it = it->next; 

  ListNode* curr = this;
  while ( it != nullptr ) {
      curr->next = new ListNode(it->val);
      it = it->next;
      curr = curr->next;
  }; 
}

ListNode& ListNode::operator=(ListNode const& other) {
  return *this = ListNode(other);
}

ListNode& ListNode::operator=(ListNode&& other) noexcept {
  std::swap(this->next, other.next);
  this->val = other.val;
  return *this;
}

std::ostream& operator<<(std::ostream& os, ListNode const* const node) {
  const ListNode* curr = node;
  bool first = true;
  os << "{";
  while(curr != nullptr) {
    if(!first) {
      os << ",";
    } else {
      first = false;
    };

    os << curr->val;
    curr = curr->next;
  }
  os << "}";
  return os;
}

std::ostream& operator<<(std::ostream& os, ListNode const& node) {
  return os << &node;
}

} // namespace Solution