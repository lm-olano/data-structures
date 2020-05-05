#include "linked_list.hpp"

#include <iostream>
#include <sstream>


// Linked list methods
template <class T>
void LinkedList<T>::insert_beginning(T new_value) {
    
    Node<T>* new_node = new Node<T>(new_value);

    new_node->set_next(head);

    head = new_node;

}

template <class T>
void LinkedList<T>::insert(T new_value, T previous_value) {

    Node<T>* previous_node;
    Node<T>* next_node;

    previous_node = search_node(previous_value);

    if (previous_node != nullptr) {

        Node<T>* new_node = new Node<T>(new_value);

        previous_node = previous_node->get_next();
        
        next_node = previous_node->get_next();
        previous_node->set_next(new_node);
        new_node->set_next(next_node);
    }
    else {
        std::cout << "Value " << previous_value << " is not in list." << std::endl;
    }
}

template <class T>
void LinkedList<T>::remove_node(T value_to_remove) {

    Node<T>* prev_node;
    Node<T>* rem_node;

    prev_node = search_node(value_to_remove);
    

    if (prev_node != nullptr) {
        rem_node = prev_node->get_next();

        prev_node->set_next(rem_node->get_next());

        delete rem_node;
    }
}


template <class T>
Node<T>* LinkedList<T>::search_node(T value) {
    // The method returns the a pointer to the node BEFORE the node which holds the value

    Node<T>* current_node = head;
    Node<T>* next_node = current_node->get_next();

    while ((next_node != nullptr) && (next_node->get_value() != value)) {
        current_node = current_node->get_next();
        next_node = next_node->get_next();
    }

    if (next_node == nullptr) {
        // The value was not found
        current_node = nullptr;
    }


    // If current_node is nullptr the whole list has been traversed but the value was not found
    return current_node;
}

template <class T>
std::string LinkedList<T>::stringify() {
    Node<T>* current_node = head;
    std::ostringstream buffer;

    while (current_node != nullptr) {
        buffer << current_node->get_value();
        buffer << " ";

        current_node = current_node->get_next();
    }
    return buffer.str();
}


template<class T>
void LinkedList<T>::remove_all() {
    Node<T>* current_node = head;
    Node<T>* temp;
    
    while (current_node != nullptr) {
        temp = current_node;
        current_node = current_node->get_next();
        delete temp;
    }

    head = nullptr;
};


// explicit instantiations
template class Node<int>;
template class Node<int*>;
template class Node<float>;
template class Node<double>;
template class Node<bool>;
template class Node<std::string>;

template class LinkedList<int>;
template class LinkedList<int*>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<bool>;
template class LinkedList<std::string>;
