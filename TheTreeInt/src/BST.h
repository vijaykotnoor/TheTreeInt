/*
 * BST.h
 *
 *  Created on: Nov 27, 2018
 *      Author: vkotnoor
 */

#ifndef THETREEINT_SRC_BST_H_
#define THETREEINT_SRC_BST_H_
#include <iostream>
#include "Tree.h"
template <typename T>
class BST {
public:
	BST():root_(nullptr){};
	virtual ~BST(){};
	void insert(T value)
	{
		root_ = insertHelper(value, root_);
	}

	void printInorder()
	{
		printInorderHelper(root_);
		std::cout<<std::endl;
	}
	// 1 for found 0 for not found //
	bool search(T value)
	{
		Tree<T>* node = searchHelper(value, root_);
		if(node != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void remove(T value)
	{
		root_ = removeHelper(value, root_);
	}



private:
	//Insert
	Tree<T>* insertHelper(T value, Tree<T> * node = nullptr)
	{
		// node addition
		if(node == nullptr)
		{
			node = new Tree<T>(value);
			node->setData(value);
		}
		else if(value < node->getData())
		{
			node->setLeft(insertHelper(value, node->getLeft()));
		}
		else if(value > node->getData())
		{
			node->setRight(insertHelper(value, node->getRight()));
		}
		return node;

	}

	Tree<T>* searchHelper(T value, Tree<T> * node = nullptr)
	{
		// node addition
		auto retValue = node;
		if(node == nullptr)
		{
			return retValue;
		}
		else if(value == node->getData())
		{
			return retValue;
		}
		else if(value < node->getData())
		{
			retValue = searchHelper(value, node->getLeft());
		}
		else if(value > node->getData())
		{
			retValue = searchHelper(value, node->getRight());
		}
		return retValue;

	}

	Tree<T>* removeHelper(T value, Tree<T> * node = nullptr)
	{

		// node addition
        if(node == nullptr)
        	return node;
        // the left root might change
        if(value < node->getData())
        	node->setLeft(removeHelper(value, node->getLeft()));

        else if(value > node->getData())
        	node->setRight(removeHelper(value, node->getRight()));

        else
        {
        	if(node->getLeft() == nullptr)
        	{
        		auto temp = node->getRight();
        		delete node;
        	    return temp;
        	}
        	else if(node->getRight() == nullptr)
        	{
        		auto temp = node->getLeft();
        		delete node;
        	    return temp;
        	}

        	//find the minimum
        	auto temp = minValueNode(node->getLeft());

        	node->setData(temp->getData());

        	node->setRight(removeHelper(temp->getData(), node->getRight()));
        }

		return node;

	}


	Tree<T>* minValueNode(Tree<T>* root)
	{
		auto node = root;
		while(node->getLeft() != nullptr)
		{
			node = node->getLeft();
		}
		return node;
	}

	void printInorderHelper(Tree<T> * node = nullptr)
	{
		if(node != nullptr)
		{
			printInorderHelper(node->getLeft());

			std::cout<< node->getData() <<" ";

			printInorderHelper(node->getRight());
		}
	}

	Tree<T>* root_;

};

#endif /* THETREEINT_SRC_BST_H_ */
