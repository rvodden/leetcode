#include "list_node.h"
#include <iostream>
#include <sstream>

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

std::string ListNode::to_string() const {
  std::stringstream ss;
  const ListNode* curr = this;
  bool first = true;
  ss << "{";
  while(curr != nullptr) {
    if(!first) {
      ss << ",";
    } else {
      first = false;
    };

    ss << curr->val;
    curr = curr->next;
  }
  ss << "}";
  return ss.str();
}

std::ostream& operator<<(std::ostream& os, ListNode const* const node) {
  os << node->to_string();
  return os;
}

std::ostream& operator<<(std::ostream& os, ListNode const& node) {
  return os << &node;
}

} // namespace Solution