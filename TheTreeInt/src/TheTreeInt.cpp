//============================================================================
// Name        : TheTreeInt.cpp
// Author      : Vijay
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Tree.h"
#include <iostream>
#include <stack>
#include <queue>
#include <deque>

#include "BST_test.h"
#include "SegmentTree.h"
#include "AVLTree_test.h"
using namespace std;

void inOrderStack(Tree<int>* root)
{
	std::stack<Tree<int>*> inOrderStack;
    auto  curr = root;
	while(!inOrderStack.empty() || curr)
	{
		while(curr)
		{

			inOrderStack.push(curr);
			curr = curr->getLeft();
		}
	    curr = inOrderStack.top();
		inOrderStack.pop();
		std::cout<< curr->getData() << " ";

		curr = curr->getRight();
	}

}

void reverseOrderStack(Tree<int>* root)
{
	std::queue<Tree<int>*> revQueue;
	std::stack<Tree<int>*> revStack;
	revQueue.push(root);
	while(!revQueue.empty())
	{
		auto curr = revQueue.front();
		revQueue.pop();
		revStack.push(curr);
		if(curr->getRight())
			revQueue.push(curr->getRight());
		if(curr->getLeft())
			revQueue.push(curr->getLeft());
	}

	while(!revStack.empty())
	{
		std::cout<< " " << revStack.top()->getData();
		revStack.pop();
	}

}

int countHalfNode(Tree<int>* root)
{
	std::queue<Tree<int>*> revQueue;
	revQueue.push(root);
	int count = 0;
	while(!revQueue.empty())
	{
		auto curr = revQueue.front();
		revQueue.pop();
		if((curr->getLeft() && !curr->getRight()) ||
				(!curr->getLeft() && curr->getRight()))
			count++;
		if(curr->getLeft())
			revQueue.push(curr->getLeft());
		if(curr->getRight())
			revQueue.push(curr->getRight());
	}
	return count;

}

int countLeafNode(Tree<int>* root)
{
	std::queue<Tree<int>*> revQueue;
	revQueue.push(root);
	int count = 0;
	while(!revQueue.empty())
	{
		auto curr = revQueue.front();
        revQueue.pop();
		if(!curr->getLeft() && !curr->getRight())
			count++;
		if(curr->getLeft())
			revQueue.push(curr->getLeft());
		if(curr->getRight())
			revQueue.push(curr->getRight());

	}
	return count;
}

int countFullNode(Tree<int>* root)
{
	std::queue<Tree<int>*> revQueue;
	revQueue.push(root);
	int count = 0;
	while(!revQueue.empty())
	{
		auto curr = revQueue.front();
        revQueue.pop();
		if(curr->getLeft() && curr->getRight())
			count++;
		if(curr->getLeft())
			revQueue.push(curr->getLeft());
		if(curr->getRight())
			revQueue.push(curr->getRight());

	}
	return count;
}

void preOrder(Tree<int>* root)
{
	std::stack<Tree<int>*> revStack;
	revStack.push(root);

	while(!revStack.empty())
	{
		auto curr = revStack.top();
		revStack.pop();
        std::cout<<curr->getData() << " ";
		if(curr->getRight())
			revStack.push(curr->getRight());
		if(curr->getLeft())
			revStack.push(curr->getLeft());
	}
}

void postOrder(Tree<int>* root)
{
	std::stack<Tree<int>*> revStack;
	std::stack<Tree<int>*> postStack;
	revStack.push(root);
	while(!revStack.empty())
	{
		auto curr = revStack.top();
		revStack.pop();

		postStack.push(curr);
		if(curr->getLeft())
			revStack.push(curr->getLeft());
		if(curr->getRight())
			revStack.push(curr->getRight());

	}
	while(!postStack.empty())
	{
		std::cout<<postStack.top()->getData()<< " ";
		postStack.pop();
	}

}

int iterativeHeight(Tree<int>* root)
{
	std::queue<Tree<int>*> bfsQueue;
	bfsQueue.push(root);
	int height =0;
	while(1)
	{
		auto nodecount = bfsQueue.size();
		if(nodecount == 0)
			return height;
		height++;
		while(nodecount > 0)
		{
			auto curr = bfsQueue.front();
			bfsQueue.pop();
			if(curr->getLeft())
				bfsQueue.push(curr->getLeft());
			if(curr->getRight())
				bfsQueue.push(curr->getRight());
			nodecount--;
		}
	}
}

void testSegmentTree()
{

   std::vector<int> array = {3,4,5,6,7,8,9,0};
   SegmentTree t(array.size());
   t.buildAddition(array);
   t.printTree();
   t.updateAdditionTree(7, 10);
   t.printTree();
   std::cout<< "Range: "<< t.queryAddition(6, 8)<< std::endl;

   SegmentTree minimum(array.size());
   minimum.buildMinimum(array);
   minimum.printTree();
   minimum.updateMinimumTree(7, 10);
   minimum.printTree();
   std::cout<< "Range: "<< minimum.queryMinimum(6, 8)<< std::endl;

}

int main() {

//	test_BST_driver();
	test_AVLTree_Driver();

	return 0;
}
