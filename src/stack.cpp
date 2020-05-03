#include "stack.hpp"

#include <iostream>

Stack::Stack(int max_size) {

    top_item = nullptr;
    size = 0;
    _max_size = max_size; 
}


int Stack::peek() {
    return (*top_item).get_value();
}


int Stack::pop() {
    Node* temp;
    int value;

    if (top_item != nullptr) {
        temp = top_item;
        value = (*temp).get_value();
        top_item = (*top_item).get_next();

        delete temp;
        size--;

        return value;   
    }
    else {

        std::cout << "Stack is empty." << std::endl;
    }
}


void Stack::push(int new_value) {

    Node* new_node = new Node(new_value);

    (*new_node).set_next(top_item);

    top_item = new_node;

    size++;
}

