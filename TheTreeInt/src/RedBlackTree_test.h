/*
 * RedBlackTree_test.cpp
 *
 *  Created on: 01-Dec-2018
 *      Author: vijay
 */

#include "RedBlackTree.h"

void RedBlackTree_add()
{
	std::cout<< "RED BLACK TREE add"<<std::endl;
	RedBlackTree<int> rbTree;
	rbTree.add(5);
	rbTree.add(4);
	rbTree.add(6);
	rbTree.add(3);
	rbTree.add(7);
	rbTree.add(2);
	rbTree.add(8);
	rbTree.add(1);

	rbTree.inorderPrint();
	rbTree.levelorderPrint();
}
void RedBlackTree_test_Driver()
{
	RedBlackTree_add();
}
