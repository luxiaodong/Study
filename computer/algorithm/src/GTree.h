#ifndef GTREE_H
#define GTREE_H

class GTreeNode
{
public:
    GTreeNode();

public:
    GTreeNode* m_parent;
    GTreeNode* m_left;
    GTreeNode* m_right;
    int m_value;
};

class GBinarySearchTree
{
public:
    void inorder_tree_walk();
    GTreeNode* tree_seach(int value);
    GTreeNode* tree_minimum();
    GTreeNode* tree_maximum();
    GTreeNode* tree_successor(GTreeNode* node);
    GTreeNode* tree_predecessor(GTreeNode* node);
//    bool tree_insert(GTreeNode* node);
//    bool tree_delete(GTreeNode* node);
private:
    void inorder_tree_walk(GTreeNode* root);
    GTreeNode* tree_seach(GTreeNode* root, int value);
    GTreeNode* iterative_tree_seach(GTreeNode* root, int value);
    GTreeNode* tree_minimum(GTreeNode* root);
    GTreeNode* tree_maximum(GTreeNode* root);
    bool tree_insert(GTreeNode* root, GTreeNode* node);
    bool tree_delete(GTreeNode* root, GTreeNode* node);

public:
    GTreeNode*  m_root;
};


#endif // GTREE_H
