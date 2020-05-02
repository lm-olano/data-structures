#include "linked_list.hpp"

#include <iostream>

// Class constructors
Node::Node(int value, Node* next) {

    _value = value;
    _next = next;
}

LinkedList::LinkedList(int value) {
    head = new Node(value);
}


// Linked list methods
void LinkedList::insert_beginning(int new_value) {
    
    Node* new_node = new Node(new_value);

    std::cout << "Adding node with value " << std::to_string(new_value) << " at " << new_node << std::endl;

    new_node->set_next(head);

    head = new_node;

}

void LinkedList::insert(int new_value, int previous_value) {

    Node* previous_node;
    Node* next_node;

    previous_node = search_node(previous_value);

    if (previous_node != nullptr) {

        Node* new_node = new Node(new_value);

        previous_node = (*previous_node).get_next();
        
        next_node = (*previous_node).get_next();
        (*previous_node).set_next(new_node);
        (*new_node).set_next(next_node);
    }
    else {
        std::cout << "Value " << previous_value << " is not in list." << std::endl;
    }


}

void LinkedList::remove_node(int value_to_remove) {

    Node* prev_node;
    Node* rem_node;

    prev_node = search_node(value_to_remove);
    

    if (prev_node != nullptr) {
        rem_node = (*prev_node).get_next();

        std::cout << "Removing node with value " << std::to_string(value_to_remove) << " at " << rem_node << std::endl;

        (*prev_node).set_next((*rem_node).get_next());

        delete rem_node;
    }

}

Node* LinkedList::search_node(int value) {
    // The method returns the a pointer to the node BEFORE the node which holds the value

    Node* current_node = head;
    Node* next_node = (*current_node).get_next();

    while ((next_node != nullptr) && ((*next_node).get_value() != value)) {
        current_node = (*current_node).get_next();
        next_node = (*next_node).get_next();
    }

    if (next_node == nullptr) {
        // The value was not found
        current_node = nullptr;
    }


    // If current_node is nullptr the whole list has been traversed but the value was not found
    return current_node;
}

std::string LinkedList::stringify() {
    Node* current_node = head;
    std::string list_string = "";

    while (current_node != nullptr) {
        list_string += std::to_string((*current_node).get_value());
        list_string += " ";

        current_node = (*current_node).get_next();
    }
    return list_string;
}

void LinkedList::remove_all() {
    Node* current_node = head;
    Node* temp;
    
    while (current_node != nullptr) {
        temp = current_node;
        current_node = (*current_node).get_next();
        std::cout << "Removing node with value " << std::to_string((*temp).get_value()) << " at " << temp << std::endl;
        delete temp;
    }

    head = nullptr;
};
