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

#endif
