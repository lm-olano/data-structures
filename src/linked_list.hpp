#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

class Node {
    private:
        int _value;
        Node* _next;

    public:

        Node(int value, Node* next=nullptr);

        int get_value() {return _value;}
        Node* get_next() {return _next;}

        void set_value(int value) {_value = value;}
        void set_next(Node* next) {_next = next;}

};

class LinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList(int value = 0);

        Node* get_head_node() {return head;}
        Node* get_tail_node() {return tail;}

        void insert_beginning(int new_value);
        void remove_node(int value_to_delete);

        Node* search_node(int value);
        
        std::string stringify();


};

#endif
