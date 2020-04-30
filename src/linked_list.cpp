#include "linked_list.hpp"

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

    new_node->set_next(head);

    head = new_node;

}

void LinkedList::remove_node(int value_to_remove) {

    Node* prev_node;
    Node* rem_node;

    prev_node = search_node(value_to_remove);
    

    if (prev_node != nullptr) {
        rem_node = (*prev_node).get_next();

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


}
