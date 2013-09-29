#ifndef GTREE_H
#define GTREE_H

class GTreeNode
{
public:
    GTreeNode();
    GTreeNode(int value);

public:
    GTreeNode* m_parent;
    GTreeNode* m_left;
    GTreeNode* m_right;
    int m_value;
    int m_color; //0 - black, 1 - red.
};

class GBinarySearchTree
{
public:
    GBinarySearchTree();

    void inorder_tree_walk();
    GTreeNode* tree_seach(int value);
    GTreeNode* tree_minimum();
    GTreeNode* tree_maximum();
    GTreeNode* tree_successor(GTreeNode* node);
    GTreeNode* tree_predecessor(GTreeNode* node);
    bool tree_insert(GTreeNode* node);
    bool tree_delete(GTreeNode* node);
private:
    void inorder_tree_walk(GTreeNode* root);
    GTreeNode* tree_seach(GTreeNode* root, int value);
    GTreeNode* iterative_tree_seach(GTreeNode* root, int value);
    GTreeNode* tree_minimum(GTreeNode* root);
    GTreeNode* tree_maximum(GTreeNode* root);

private:
    void tree_swap(GTreeNode* a, GTreeNode* b);

public:
    GTreeNode*  m_root;
};

class GRedBlackTree : public GBinarySearchTree
{
public:
    void left_rotate(GTreeNode* node);
    void right_rotate(GTreeNode* node);
};

#endif // GTREE_H
