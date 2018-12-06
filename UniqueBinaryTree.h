//Content of UniqueBinaryTree.h

// Specification file for the UniqueBinaryTree class
#ifndef UNIQUEBINARYTREE_H
#define UNIQUEBINARYTREE_H

#include <iostream>

template <typename T>
class UniqueBinaryTree
{
private:
	struct TreeNode
	{
	    T value; // The value in the node
	    unsigned int frequency = 0; // The frequency of value
	    TreeNode *left; // Pointer to left child node
	    TreeNode *right; // Pointer to right child node
	};

	TreeNode *root; // Pointer to the root node

	// Private member functions
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *) {}
	void deleteNode(int, TreeNode *&) {}
	void makeDeletion(TreeNode *&) {}
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;

public:
	// Constructor
	UniqueBinaryTree()
	{
	    root = nullptr;
	}

	// Destructor
	~UniqueBinaryTree()
	{
	    destroySubTree(root);
	}

	// Binary tree operations
	void insertNode(T);
	bool searchNode(T);
	void remove(T);

	void displayInOrder() const
	{
	    displayInOrder(root);
	}

	void displayPreOrder() const
	{
	    displayPreOrder(root);
	}

	void displayPostOrder() const
	{
	    displayPostOrder(root);
	}
};
#endif

//Inserting a node
template <typename T>
void UniqueBinaryTree<T>::insertNode(T num)
{
    TreeNode *newNode = nullptr; // Pointer to a new node.

    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;

    // Insert the node.
    insert(root, newNode);
}

template <typename T>
void UniqueBinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr) {
	nodePtr = newNode; // Insert the node.
	++nodePtr->frequency; // Increment the frequency
    } else if (newNode->value < nodePtr->value) {
	insert(nodePtr->left, newNode); // Search the left branch.
    } else if (newNode->value > nodePtr->value) {
	insert(nodePtr->right, newNode); // Search the right branch.
    } else {
	++nodePtr->frequency; // If there is already a node with the given value, increment the frequency
	delete newNode;
    }
}

//Traverse a tree
//*************************************************************
// The displayInOrder member function displays the values *
// in the subtree pointed to by nodePtr, via inorder traversal. *
//*************************************************************
template <typename T>
void UniqueBinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
	displayInOrder(nodePtr->left);
	std::cout << "{" << nodePtr->value << ", " << nodePtr->frequency << "}" << std::endl;
	displayInOrder(nodePtr->right);
    }
}

//*************************************************************
// The displayPreOrder member function displays the values *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//*************************************************************
template <typename T>
void UniqueBinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
	std::cout << "{" << nodePtr->value << ", " << nodePtr->frequency << "}" << std::endl;
	displayPreOrder(nodePtr->left);

	displayPreOrder(nodePtr->right);
    }
}

//*************************************************************
// The displayPostOrder member function displays the values *
// in the subtree pointed to by nodePtr, via postorder traversal. *
//*************************************************************
template <typename T>
void UniqueBinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
	displayPostOrder(nodePtr->left);
	displayPostOrder(nodePtr->right);
	std::cout << "{" << nodePtr->value << ", " << nodePtr->frequency << "}" << std::endl;
    }
}

//Search a tree
template <typename T>
bool UniqueBinaryTree<T>::searchNode(T num)
{
    TreeNode *nodePtr = root;
    while (nodePtr)
    {
	if (nodePtr->value == num) {
	    return true;
	} else if (num < nodePtr->value) {
	    nodePtr = nodePtr->left;
	} else {
	    nodePtr = nodePtr->right;
	}
    }
    return false;
}
