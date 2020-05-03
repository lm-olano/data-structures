#include "linked_list.hpp"

class Stack {
    private:
    Node* top_item;

    public:
    Stack();

    Node* get_top_item() {return top_item;}

    int peek();
    int pop();
    void push(int new_value);

};
