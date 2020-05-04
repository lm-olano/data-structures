#include "tree.hpp"

TreeNode::TreeNode(int value) {
    _value = value;
    no_children = 0;

}


void TreeNode::add_child(TreeNode* child) {
    if (no_children < MAX_NO_CHILDREN) {
        children[no_children] = child;
        no_children += 1;
    }
}


void TreeNode::remove_child(TreeNode* child) {
    for (int i = 0; i<MAX_NO_CHILDREN; i++) {
        if (children[i] == child) {
            children[i] = nullptr;
            no_children -= 1;
        }
    }
}