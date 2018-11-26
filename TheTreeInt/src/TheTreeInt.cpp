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

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Tree<int>* root = new Tree<int>(1);
	root->setLeft(new Tree<int>(2));
	root->setRight(new Tree<int>(3));
	root->getLeft()->setLeft(new Tree<int>(4));
	root->getLeft()->setRight(new Tree<int>(5));
	root->getRight()->setLeft(new Tree<int>(6));
	root->getRight()->setRight(new Tree<int>(7));
	root->getLeft()->getLeft()->setLeft(new Tree<int>(8));
	root->getLeft()->getLeft()->setRight(new Tree<int>(9));
	inOrderStack(root);
	reverseOrderStack(root);
	std::cout<<"\n"<< countHalfNode(root)<<std::endl;
	std::cout<<"\n"<< countLeafNode(root)<<std::endl;
	std::cout<<"\n"<< countFullNode(root)<<std::endl;
	preOrder(root);
	std::cout<<"\n";
	postOrder(root);
	std::cout<<"\n"<< iterativeHeight(root)<<std::endl;
	return 0;
}
