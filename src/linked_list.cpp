#include "linked_list.hpp"

Node::Node(int value, Node* next) {

    _value = value;
    _next = next;
}

LinkedList::LinkedList(int value) {
    head = new Node(value);

}
