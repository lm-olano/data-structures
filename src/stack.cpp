#include "stack.hpp"

Stack::Stack() {

    top_item = nullptr;
}


int Stack::peek() {
    return (*top_item).get_value();
}


void Stack::push(int new_value) {

    Node* new_node = new Node(new_value);

    (*new_node).set_next(top_item);

    top_item = new_node;
}

