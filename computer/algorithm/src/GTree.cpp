#include "GTree.h"
#include <QDebug>

GTreeNode::GTreeNode()
{
    m_parent = 0;
    m_left = 0;
    m_right = 0;
    m_value = 0;
}

GTreeNode::GTreeNode(int value)
{
    m_value = value;
    m_parent = 0;
    m_left = 0;
    m_right = 0;
}

GBinarySearchTree::GBinarySearchTree()
{
    m_root = 0;
}

void GBinarySearchTree::inorder_tree_walk()
{
    return this->inorder_tree_walk(this->m_root);
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

GTreeNode* GBinarySearchTree::tree_seach(int value)
{
    return this->tree_seach(this->m_root, value);
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
        else if(value > current->m_value)
        {
            current = current->m_right;
        }
    }

    return 0;
}

GTreeNode* GBinarySearchTree::tree_minimum()
{
    return this->tree_minimum(this->m_root);
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

GTreeNode* GBinarySearchTree::tree_maximum()
{
    return this->tree_maximum(this->m_root);
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

GTreeNode* GBinarySearchTree::tree_successor(GTreeNode* node)
{
    if(node != 0)
    {
        if(node->m_right != 0)
        {
            return this->tree_minimum(node->m_right);
        }
        else
        {
            GTreeNode* current = node;
            GTreeNode* parent = current->m_parent;

            while(1)
            {
                if(parent == 0)
                {
                    break; //find none;
                }

                if(parent->m_left == current)
                {
                    return parent;
                }
                else
                {
                    current = parent;
                    parent = parent->m_parent;
                }
            }
        }
    }

    return 0;
}

GTreeNode* GBinarySearchTree::tree_predecessor(GTreeNode* node)
{
    if(node != 0)
    {
        if(node->m_left != 0)
        {
            return this->tree_maximum(node->m_left);
        }
        else
        {
            GTreeNode* current = node;
            GTreeNode* parent = current->m_parent;

            while(1)
            {
                if(parent == 0)
                {
                    break; //find none;
                }

                if(parent->m_right == current)
                {
                    return parent;
                }
                else
                {
                    current = parent;
                    parent = parent->m_parent;
                }
            }
        }
    }

    return 0;
}

bool GBinarySearchTree::tree_insert(GTreeNode* node)
{
    if (node == 0)
    {
        return false;
    }

    if(m_root == 0)
    {
        m_root = node;
        return true;
    }

    GTreeNode* parent = m_root;
    while(1)
    {
        GTreeNode* son = 0;
        if(node->m_value < parent->m_value)
        {
            son = parent->m_left;

            if(son == 0)
            {
                node->m_parent = parent;
                parent->m_left = node;
                return true;
            }
        }
        else
        {
            son = parent->m_right;

            if(son == 0)
            {
                node->m_parent = parent;
                parent->m_right = node;
                return true;
            }
        }

        parent = son;
    }

    return false;
}

bool GBinarySearchTree::tree_delete(GTreeNode* node)
{
    if(node == 0)
    {
        return false;
    }

    //check node is in root ? or return false
    if(node->m_left == 0 && node->m_right == 0)
    {
        if(node == m_root)
        {
            m_root = 0;
        }
        else
        {
            GTreeNode* parent = node->m_parent;
            if(node == parent->m_left)
            {
                parent->m_left = 0;
            }
            else
            {
                parent->m_right = 0;
            }
        }
    }
    else if(node->m_left == 0 || node->m_right == 0)
    {
        if(node == m_root)
        {
            if(node->m_left == 0)
            {
                m_root = node->m_right;
            }
            else
            {
                m_root = node->m_left;
            }
        }
        else
        {
            GTreeNode* parent = node->m_parent;
            if(node->m_left == 0)
            {
                if(parent->m_left == node)
                {
                    parent->m_left = node->m_right;
                }
                else
                {
                    parent->m_right = node->m_right;
                }
            }
            else
            {
                if(parent->m_left == node)
                {
                    parent->m_left = node->m_left;
                }
                else
                {
                    parent->m_right = node->m_left;
                }
            }
        }
    }
    else if(node->m_left != 0 && node->m_right != 0)
    {
        GTreeNode* next = this->tree_successor(node);
        //swap value, not swap point
        int value = next->m_value;
        next->m_value = node->m_value;
        node->m_value = value;
        //this->tree_swap(next, node);

//        if(node == m_root)
//        {
//            m_root = node;
//        }

        return this->tree_delete(next);
    }

    return true;
}

void GBinarySearchTree::tree_swap(GTreeNode* a, GTreeNode* b)
{
    GTreeNode* temp_parent = a->m_parent;
    GTreeNode* temp_left = a->m_left;
    GTreeNode* temp_right = a->m_right;
    int temp_value = a->m_value;

    a->m_parent = b->m_parent;
    a->m_left = b->m_left;
    a->m_right = b->m_right;
    a->m_value = b->m_value;

    b->m_parent = temp_parent;
    b->m_left = temp_left;
    b->m_right = temp_right;
    b->m_value = temp_value;

    if(a->m_parent != 0)
    {
        if(a == a->m_parent->m_left)
        {
            a->m_parent->m_left = b;
        }
        else
        {
            a->m_parent->m_right = b;
        }
    }

    if(b->m_parent != 0)
    {
        if(b == b->m_parent->m_left)
        {
            b->m_parent->m_left = a;
        }
        else
        {
            b->m_parent->m_right = a;
        }
    }
}
