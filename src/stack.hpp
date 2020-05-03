#include "linked_list.hpp"

class Stack {
    private:
    Node* top_item;

    public:
    Stack();

    int peek();
    void push(int new_value);

};
