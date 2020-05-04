#define MAX_NO_CHILDREN 1000

class TreeNode {
    private:
    int _value;

    int no_children;
    TreeNode* children[MAX_NO_CHILDREN];

    public:
    TreeNode(int value);

    void add_child(TreeNode* child);
    void remove_child(TreeNode* child);

};