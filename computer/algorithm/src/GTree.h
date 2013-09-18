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
    void inorder_tree_walk(GTreeNode* root);
    GTreeNode* tree_seach(GTreeNode* root, int value);
    GTreeNode* iterative_tree_seach(GTreeNode* root, int value);
    GTreeNode* tree_minimum(GTreeNode* root);
    GTreeNode* tree_maximum(GTreeNode* root);
    GTreeNode* tree_successor(GTreeNode* root);
    GTreeNode* tree_predecessor(GTreeNode* root);

public:
    GTreeNode*  m_root;
};


#endif // GTREE_H
