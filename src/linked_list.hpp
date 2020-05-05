#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

template <class T>
class Node {
    private:
        T _value;
        Node<T>* _next;

    public:
        Node(): _next(nullptr), _value(0) {}
        Node(T value) : _next(nullptr), _value(value) {}
        Node(Node<T>* node) : _value(node->get_value()), _next(node->get_next()) {}

        T get_value() {return _value;}
        Node<T>* get_next() {return _next;}

        void set_value(T value) {_value = value;}
        void set_next(Node<T>* next) {_next = next;}

};

template <class T>
class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        LinkedList() {head = nullptr;}
        LinkedList(T value) {head = new Node<T>(value);};

        Node<T>* get_head_node() {return head;}
        Node<T>* get_tail_node() {return tail;}

        void insert_beginning(T new_value);
        void insert(T new_value, T previous_value);
        void remove_node(T value_to_delete);

        Node<T>* search_node(T value);
        
        std::string stringify();

        void remove_all();
};

#endif
