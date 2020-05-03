#include "stack.hpp"

#include <iostream>

Stack::Stack(int max_size) {

    top_item = nullptr;
    size = 0;
    _max_size = max_size; 
}


bool Stack::has_space() {
    return size < _max_size ? true : false;
}

bool Stack::is_empty() {
    return size <= 0 ? true : false; 
}


int Stack::peek() {

    if (!is_empty()) {
        return (*top_item).get_value();
    }
    else {

        std::cout << "Stack is empty." << std::endl;
    }    
}


int Stack::pop() {
    Node* temp;
    int value;

    if (!is_empty()) {
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

    if (has_space()) {
        Node* new_node = new Node(new_value);

        (*new_node).set_next(top_item);

        top_item = new_node;

        size++;
    }
    else {
        std::cout << "Stack is full." << std::endl;
    }
}

