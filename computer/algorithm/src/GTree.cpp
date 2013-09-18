#include "GTree.h"
#include <QDebug>

GTreeNode::GTreeNode()
{
    m_parent = 0;
    m_left = 0;
    m_right = 0;
}

void GBinarySearchTree::inorder_tree_walk(GTreeNode* root)
{
    if(root != 0)
    {
        this->inorder_tree_walk(root->m_left);
        qDebug()<<root->m_value;
        this->inorder_tree_walk(root->m_right);
    }
}

GTreeNode* GBinarySearchTree::tree_seach(GTreeNode* root, int value)
{
    if(root != 0)
    {
        if(value == root->m_value)
        {
            return root;
        }
        else if(value > root->m_value)
        {
            return this->tree_seach(root->m_right, value);
        }
        else if(value < root->m_value)
        {
            return this->tree_seach(root->m_left, value);
        }
    }

    return 0;
}

GTreeNode* GBinarySearchTree::iterative_tree_seach(GTreeNode* root, int value)
{
    GTreeNode* current = root;
    while(current != 0)
    {
        if(value == current->m_value)
        {
            return current;
        }
        else if(value < current->m_value)
        {
            current = current->m_left;
        }
        else if(value > current->m_right)
        {
            current = current->m_right;
        }
    }

    return 0;
}

GTreeNode* GBinarySearchTree::tree_minimum(GTreeNode* root)
{
    GTreeNode* current = root;
    if(current != 0)
    {
        while(current->m_left != 0)
        {
            current = current->m_left;
        }

        return current;
    }

    return 0;
}

GTreeNode* GBinarySearchTree::tree_maximum(GTreeNode* root)
{
    GTreeNode* current = root;
    if(current != 0)
    {
        while(current->m_right != 0)
        {
            current = current->m_right;
        }

        return current;
    }

    return 0;
}

GTreeNode* GBinarySearchTree::tree_successor(GTreeNode* root)
{}

GTreeNode* GBinarySearchTree::tree_predecessor(GTreeNode* root)
{}
