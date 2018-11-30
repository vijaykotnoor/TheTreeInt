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

	//print values
    void printLevelorder()
    {
    	printLevelorderHelper(root_);
    	std::cout<<std::endl;
    }

    //check if the value is already present in the tree.
    bool contains(T value)
    {
    	return contains(root_, value);
    }

    bool remove(T value)
    {
    	if(root_ == nullptr)
    		return false;
    	if(contains(value))
    	{
    		root_ = remove(root_, value);
    		nodeCount_--;
    		return true;
    	}

    	return false;

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
		//balance node
		node = balance(node);
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

	void printLevelorderHelper(Node* node)
	{
		//base case
		if(node == nullptr)
			return;

		std::queue<Node*> lvlQueue;
		lvlQueue.push(node);
		//auto height = node->height_;
		while(!lvlQueue.empty())
		{
			auto temp = lvlQueue.front();
			/*if(temp->height_ != height)
			{
				height = temp->height_
			}*/

			lvlQueue.pop();
			std::cout<< temp->value_ << " " ;
			if(temp->left_ != nullptr)
				lvlQueue.push(temp->left_);
			if(temp->right_ != nullptr)
				lvlQueue.push(temp->right_);
		}
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
		return node;

	}

	Node* leftLeftCase(Node* node)
	{
		return rightRotation(node);
	}

	Node*leftRightCase(Node* node)
	{
		node->left_ = leftRotation(node->left_);
		return leftLeftCase(node);
	}

	Node* rightRightCase(Node* node)
	{
		return leftRotation(node);
	}

	Node* rightLeftCase(Node* node)
	{
		node->right_ = rightRotation(node->right_);
		return rightRightCase(node);
	}

	Node* leftRotation(Node* node)
	{
		Node* newParent = node->right_;
		node->right_ = newParent->left_;
		newParent->left_ = node;

		updateHeightBalanceFactor(node);
		updateHeightBalanceFactor(newParent);
		return newParent;

	}

	Node* rightRotation(Node* node)
	{
		Node* newParent = node->left_;
		node->left_ = newParent->right_;
		newParent->right_ = node;
		updateHeightBalanceFactor(node);
		updateHeightBalanceFactor(newParent);
		return newParent;
	}

	Node* remove(Node* node, T value)
	{
		if(node == nullptr)
			return node;

		if(value > node->value_)
			node->right_ = remove(node->right_, value);
		else if(value < node->value_)
			node->left_ = remove(node->left_, value);
		else
		{
			if(node->left_ == nullptr && node->right_ == nullptr)
			{
				delete node;
			    return nullptr;
			}
			else if(node->left_ == nullptr)
			{
				auto newnode = node->right_;
				delete node;
				return newnode;
			}
			else if(node->right_ == nullptr)
			{
				auto newnode = node->left_;
				delete node;
				return newnode;
			}
			else
			{
                //extra case to check the tree height
				if(node->left_->height_ > node->right_->height_)
				{
					auto succValue = findMax(node->left_);
					node->value_ = succValue;
					node->left_ = remove(node->left_, succValue);
				}
				else
				{
					auto succValue = findMin(node->right_);
					node->value_ = succValue;
					node->right_ = remove(node->right_, succValue);
				}
			}
		}
		updateHeightBalanceFactor(node);
		return balance(node);
	}

	T findMin(Node* node)
	{
		while(node->left_ != nullptr)
			node = node->left_;
		return node->value_;
	}

	T findMax(Node* node)
	{
		while(node->right_ != nullptr)
			node = node->right_;
		return node->value_;
	}

	Node* root_; //root node
	int nodeCount_;// number of nodes in the AVL Tree
};

#endif /* AVLTREE_H_ */
