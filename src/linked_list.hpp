#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

    public:
        LinkedList(int value = 0);

        Node* get_head_node() {return head;}

};

#endif
