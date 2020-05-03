#include "linked_list.hpp"

class Stack {
    private:
    Node* top_item;
    int size;
    int _max_size;

    public:
    Stack(int max_size=1000);

    Node* get_top_item() {return top_item;}

    int peek();
    int pop();
    void push(int new_value);

};
