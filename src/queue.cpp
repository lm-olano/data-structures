#include "queue.hpp"

#include <iostream>

Queue::Queue(int max_size) {
    head = nullptr;
    tail = nullptr;
    _max_size = max_size;
    size = 0;
}


bool Queue::is_empty() {
    return size <= 0 ? true : false;
}


bool Queue::has_space() {
    return size < _max_size ? true : false;
}


int Queue::peek() {
    if (!is_empty()) {
        return (*head).get_value();
    }
    else {
        std::cout << "The queue is empty." << std::endl;
    }
}


void Queue::enqueue(int new_value) {

    if (has_space()) {
        Node* new_node = new Node(new_value);
        if (is_empty()) {
            
            head = new_node;
            tail = new_node;
        }
        else {

            (*tail).set_next(new_node);

            tail = new_node;
        }
        size += 1;
    }
    else {
        std::cout << "The queue is full." << std::endl;
    }
}


int Queue::dequeue() {
    if (!is_empty()) {
        Node* temp = head; 
        int value;
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = (*head).get_next();
        }
        value = (*temp).get_value();
        delete temp;
        size -= 1;

        return value;
    }
    else {
        std::cout << "The queue is empty." << std::endl;
    }
}
