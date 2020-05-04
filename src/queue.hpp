#include "linked_list.hpp"

class Queue {
    private:
        Node* head;
        Node* tail;

        int size;
        int _max_size;
    public:
        Queue(int max_size = 1000);

        Node* get_head() {return head;}
        int get_size() {return size;}

        bool is_empty();
        bool has_space();

        int peek();

        void enqueue(int new_value);
        int dequeue();
};
