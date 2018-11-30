/*
 * AVLTree.h
 *
 *  Created on: Nov 29, 2018
 *      Author: vkotnoor
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_
#include <iostream>
template <typename T>
class AVLTree {
public:
	AVLTree():root_(nullptr),nodeCount_(0){}
	virtual ~AVLTree(){}
	// height of the AVL tree
	int getHeight()
	{
		if(root_ == nullptr)
			return 0;
		return root_->height_;
	}

	//Number of nodes in the AVL tree.
	int getSize()
	{
		return nodeCount_;
	}

	//Check whether the AVL tree empty
	bool isEmpty()
	{
		return nodeCount_ == 0;
	}
	// insert values in the AVL tree
	bool insert(T value)
	{
		if(!contains(value))
		{
			root_ =insert(root_, value);
			nodeCount_++;
			return true;
		}
		return false;
	}

	//print values
    void printInorder()
    {
    	printInorderHelper(root_);
    	std::cout<<std::endl;
    }

    //check if the value is already present in the tree.
    bool contains(T value)
    {
    	return contains(root_, value);
    }

private:
	class Node{
	public:
		Node(T value):balanceFactor_(0),value_(value), height_(0),left_(nullptr),right_(nullptr){}
		~Node(){}
		int balanceFactor_; //balance factor
		T value_;  // data stored in the node
		int height_; // height of the tree from the root
		Node* left_; // left subtree pointer
		Node* right_; // right subtree
	};

	//
	Node* insert(Node* node, T value)
	{
		// Recursion base case
		if(node == nullptr)
			return new Node(value);
		auto nodeVal = (node->value_ > value);

		if(nodeVal) // value need to go to the left node
		{
			node->left_ = insert(node->left_, value);
		}
		else // value need to go the right node
		{
			node->right_ = insert(node->right_, value);
		}

		//update node
		updateHeightBalanceFactor(node);
		//TODO: balance node

		return node;
	}

	bool contains(Node* node, T value)
	{
		//base case for recursion
		if(node == nullptr)
			return false;

		//if the value is present return true
		if(node->value_ == value)
			return true;

		// recurse throught he tree to find the value
		if(value < node->value_)
			return contains(node->left_ , value);
		else
			return contains(node->right_, value);
	}

	void printInorderHelper(Node* node)
	{
		//base case
		if(node == nullptr)
			return;
		printInorderHelper(node->left_);
		std::cout<< node->value_ <<" ";
		printInorderHelper(node->right_);
	}

	//update the height and the balance factor for all the nodes
	// The function is called in a recursive function so the height of all nodes are updated
	void updateHeightBalanceFactor(Node* node)
	{
		auto leftNodeHeight = (node->left_ == nullptr)? -1 : node->left_->height_;
		auto rightNodeHeight = (node->right_ == nullptr)? -1 : node->right_->height_;

		// update this nodes height
		node->height_= 1 + std::max(leftNodeHeight, rightNodeHeight);

		//update the balance factor
		node->balanceFactor_ = rightNodeHeight -leftNodeHeight;

	}

	// Balance the node and return the new root
	Node* balance(Node* node)
	{
		// if left is heavy
		if(node->balanceFactor_ == -2)
		{
			//left left case
			if(node->left_->balanceFactor_ <= 0)
				return leftLeftCase(node);
			else // left right case
				return leftRightCase(node);
		}
		else if(node->balanceFactor_ == 2)  //right heavy
		{
			//right right case
			if(node->right_->balanceFactor_ >= 0)
				return rightRightCase(node);
			else // right left case
				return rightLeftCase(node);
		}

	}
	Node* root_; //root node
	int nodeCount_;// number of nodes in the AVL Tree
};

#endif /* AVLTREE_H_ */
