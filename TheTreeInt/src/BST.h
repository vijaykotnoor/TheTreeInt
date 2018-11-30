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

    bool remove(T value)
    {
    	Tree<T>* node = removeHelper(value, root_);
    	if(node != nullptr)
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
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
			auto retValue = searchHelper(value, node->getLeft());
		}
		else if(value > node->getData())
		{
			auto retValue = searchHelper(value, node->getRight());
		}
		return retValue;

	}

	Tree<T>* removeHelper(T value, Tree<T> * node = nullptr)
	{
		// node addition

		auto retValue = searchHelper(value, node);


		return retValue;

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
