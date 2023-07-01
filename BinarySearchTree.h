/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 6 : Binary Search Tree
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/25/2021
*******************************************************************************/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "EmployeeInfo.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*******************************************************************************
* STRUCT TreeNode
*_______________________________________________________________________________
* This struct is a double node struct with a piece of data that stores children
* nodes and a piece of data.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

template <typename type>
struct TreeNode
{
    type value;         // IN - value of node
    TreeNode *left;     // IN - pointer to left child
    TreeNode *right;    // IN - pointer to right child
};

template <typename type>
class BinarySearchTree{
    private:
        size_t sizeOfTree = 0;
        TreeNode<type>* root;

        /************
         * MUTATORS *
         ************/
        void insert(TreeNode<type> *&, TreeNode<type> *&);
        void destroySubTree(TreeNode<type> *);
        void deleteNode(int , TreeNode<type> *&);
        void makeDeletion(TreeNode<type> *&);

        /*************
         * ACCESSORS *
         *************/
        void displayInOrder(TreeNode<type> *) const;
        void displayPreOrder(TreeNode<type> *) const;
        void displayPostOrder(TreeNode<type> *) const;
        size_t leafCount(TreeNode<type> *) const;
        size_t nonLeafCount(TreeNode<type> *) const;
    public:    
        /******************************
         * CONSTRUCTORS & DESTRUCTORS *
         ******************************/
        BinarySearchTree(){ root = NULL;}
        BinarySearchTree(BinarySearchTree &myTree);
        ~BinarySearchTree(){ destroySubTree(root);}

        /************
         * MUTATORS *
         ************/
        void operator=(const BinarySearchTree &myTree);
        void insertNode(type);
        bool searchNode(type);
        void remove(type);

        /*************
         * ACCESSORS *
         *************/
        void displayInOrder() const{ displayInOrder(root);}
        void displayPreOrder() const{ displayPreOrder(root);}
        void displayPostOrder() const{ displayPostOrder(root);}
        size_t size() const;
        size_t leafCount() const {return leafCount(root);}
        size_t nonLeafCount() const {return nonLeafCount(root);}
};

/*******************************************************************************
* CONSTRUCTOR BinarySearchTree
*_______________________________________________________________________________
* This constructor constructs a BST object using an existing BST
*******************************************************************************/
template <typename type>
BinarySearchTree<type>::BinarySearchTree(BinarySearchTree &myTree)
{
    this->root = myTree.root;
    this->sizeOfTree = myTree.sizeOfTree;
}

/*******************************************************************************
* MUTATOR operator=
*_______________________________________________________________________________
* Overloads the assignment operator for the BST class
*******************************************************************************/
template <typename type>
void BinarySearchTree<type>::operator=(const BinarySearchTree &myTree)
{
    this->root = myTree.root;
    this->sizeOfTree = myTree.sizeOfTree;
}

/*******************************************************************************
* MUTATOR insert
*_______________________________________________________________________________
* Allows insertion for the BST class
*******************************************************************************/
template <typename type>
void BinarySearchTree<type>::insert(TreeNode<type> *&nodePtr, TreeNode<type> *&newNode){
    if (nodePtr == NULL)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

/*******************************************************************************
* MUTATOR destroySubTree
*_______________________________________________________________________________
* Allows deletion of sub tree for the BST class
*******************************************************************************/
template <typename type>
void BinarySearchTree<type>::destroySubTree(TreeNode<type> *nodePtr){
    //cout << "Binary Tree Destroyed\n";
}

/*******************************************************************************
* MUTATOR deleteNode
*_______________________________________________________________________________
* Allows deletion of node for the BST class
*******************************************************************************/
template <typename type>
void BinarySearchTree<type>::deleteNode(int num, TreeNode<type> *&nodePtr){
    if (num < nodePtr->value)
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->value)
        deleteNode(num, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

/*******************************************************************************
* MUTATOR makeDeletion
*_______________________________________________________________________________
* Allows deletion for the BST class
*******************************************************************************/
template <typename type>
void BinarySearchTree<type>::makeDeletion(TreeNode<type> *&nodePtr){
    TreeNode<type> *tempNodePtr;

    if (nodePtr == NULL)
        cout << "Cannot delete empty node\n";
    else if(nodePtr->right == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if(nodePtr->left == NULL)
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
        while(tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        //Reattach the left subtree
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        //Reattach the right subtree
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

/*******************************************************************************
* ACCESSOR displayInOrder
*_______________________________________________________________________________
* Displays the BST in order
*******************************************************************************/
template <typename type>
void BinarySearchTree<type>::displayInOrder(TreeNode<type> *nodePtr) const{
    if(nodePtr){
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

/*******************************************************************************
* ACCESSOR displayPreOrder
*_______________________________________________________________________________
* Displays the BST in pre order
*******************************************************************************/
template <typename type>
void BinarySearchTree<type>::displayPreOrder(TreeNode<type> *nodePtr) const{
    if(nodePtr){
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

/*******************************************************************************
* ACCESSOR displayPostOrder
*_______________________________________________________________________________
* Displays the BST in post order
*******************************************************************************/
template <typename type>
void BinarySearchTree<type>::displayPostOrder(TreeNode<type> *nodePtr) const{
    if(nodePtr){
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}

/*******************************************************************************
* MUTATOR insertNode
*_______________________________________________________________________________
* Allows insertion of node for the BST class
*******************************************************************************/
template <typename type>
void BinarySearchTree<type>::insertNode(type value)
{
    TreeNode<type> *newNode = new TreeNode<type>;

    newNode->value = value;
    newNode->left = newNode->right = NULL;

    //Insert the Node
    insert(root, newNode);
    sizeOfTree+=1;
}

/*******************************************************************************
* ACCESSOR searchNode
*_______________________________________________________________________________
* Searches through BST for specified node for BST class
*******************************************************************************/
template <typename type>
bool BinarySearchTree<type>::searchNode(type value){
    TreeNode<type>* nodePtr = root;

    while(nodePtr){
        if (nodePtr->value == value)
            return true;
        else if (value < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

/*******************************************************************************
* MUTATOR remove
*_______________________________________________________________________________
* Allows removal of node for the BST class
*******************************************************************************/
template <typename type>
void BinarySearchTree<type>::remove(type value){
    deleteNode(value, root);
}

/*******************************************************************************
* ACCESSOR size
*_______________________________________________________________________________
* Returns the size of the BST
*******************************************************************************/
template <typename type>
size_t BinarySearchTree<type>::size() const
{
    return this->sizeOfTree;
}

/*******************************************************************************
* ACCESSOR leafCount
*_______________________________________________________________________________
* Returns the leaf count of the BST
*******************************************************************************/
template <typename type>
size_t BinarySearchTree<type>::leafCount(TreeNode<type> *nodePtr) const{
    if(nodePtr == NULL)
            return 0;
        if(nodePtr->left == NULL && nodePtr->right == NULL)
            return 1;
        else
            return leafCount(nodePtr->left)+
                leafCount(nodePtr->right);
}

/*******************************************************************************
* ACCESSOR nonLeafCount
*_______________________________________________________________________________
* Returns the non leaf count of the BST
*******************************************************************************/
template <typename type>
size_t BinarySearchTree<type>::nonLeafCount(TreeNode<type> *nodePtr) const{
    if(nodePtr == NULL)
            return 0;
        if(nodePtr->left != NULL || nodePtr->right != NULL || nodePtr == root)
            return 1;
        else
            return nonLeafCount(nodePtr->left)+
                nonLeafCount(nodePtr->right);
}

#endif // BINARYSEARCHTREE_H
