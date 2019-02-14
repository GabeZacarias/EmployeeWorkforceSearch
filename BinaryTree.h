#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include<string>
#include<cstdlib>
#include <iomanip>

using namespace std;

template<class T>
struct TreeNode
{
    T value;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T &val) : value(val), left(NULL), right(NULL) { }
};

template<class T>
class BinaryTree
{
private:
    TreeNode<T>* root;
    void insert(TreeNode<T> *&, TreeNode<T> *&);
    void destroySubTree(TreeNode<T> *);
    void deleteNode(T, TreeNode<T> *&);
    void makeDeletion(TreeNode<T> *&);
    void displayInOrder(TreeNode<T> *) const;
    void displayPreOrder(TreeNode<T> *) const;
    void displayPostOrder(TreeNode<T> *) const;
public:
    //Constructor
    BinaryTree();
    ~BinaryTree() { destroySubTree(root); }

    //Binary Tree Operations
    void insertNode(T);
    T *searchNode(T);
    void remove(T);

    void displayInOrder() const { displayInOrder(root); }
    void displayPreOrder() const { displayPreOrder(root); }
    void displayPostOrder() const { displayPostOrder(root); }

};

template<class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

template<class T>
void BinaryTree<T>::insert(TreeNode<T> *&nodePtr, TreeNode<T> *&newNode)
{
    if (nodePtr == NULL)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

template<class T>
void BinaryTree<T>::insertNode(T val)
{
    TreeNode<T> *newNode = new TreeNode < T >(val);

    newNode->value = val;
    newNode->left = newNode->right = NULL;

    //Insert the Node
    insert(root, newNode);
}

template<class T>
void BinaryTree<T>::displayInOrder(TreeNode<T> *nodePtr) const
{
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

template<class T>
void BinaryTree<T>::displayPreOrder(TreeNode<T> *nodePtr) const
{
    if (nodePtr) {
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

template<class T>
void BinaryTree<T>::displayPostOrder(TreeNode<T> *nodePtr) const {
    if (nodePtr) {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}

template<class T>
void BinaryTree<T>::destroySubTree(TreeNode<T> *nodePtr) {
    if (nodePtr != NULL)
    {
        if (nodePtr->left != NULL)
        {
            destroySubTree(nodePtr->left);
        }
        if (nodePtr->right != NULL)
        {
            destroySubTree(nodePtr->right);
        }
        delete nodePtr;
    }

    //cout << "Binary Tree Destroyed\n";
}

template <class T>
T *BinaryTree<T>::searchNode(T num)
{
    TreeNode<T> *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == num)
        {
            return &nodePtr->value;
        }
        else if (num < nodePtr->value)
        {
            nodePtr = nodePtr->left;
        }
        else
        {
            nodePtr = nodePtr->right;
        }
    }

    return NULL;
}

template<class T>
void BinaryTree<T>::remove(T val) {
    deleteNode(val, root);
}

template<class T>
void BinaryTree<T>::deleteNode(T val, TreeNode<T> *&nodePtr) {
    if (val < nodePtr->value)
        deleteNode(val, nodePtr->left);
    else if (val > nodePtr->value)
        deleteNode(val, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

template<class T>
void BinaryTree<T>::makeDeletion(TreeNode<T> *&nodePtr) {
    TreeNode<T> *tempNodePtr;

    if (nodePtr == NULL)
        cout << "Cannot delete empty node\n";
    else if (nodePtr->right == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if (nodePtr->left == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    //If the node has two Children
    else
    {
        //Move one node to the right
        tempNodePtr = nodePtr->right;
        //Go to the end left node
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        //Reattach the left subtree
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        //Reattach the right subtree
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

#endif
