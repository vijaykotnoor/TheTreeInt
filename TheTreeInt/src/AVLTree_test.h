/*
 * AVLTree_test.h
 *
 *  Created on: Nov 29, 2018
 *      Author: vkotnoor
 */

#include "AVLTree.h"

void test_AVLTree_Basic_Insert()
{
	std::cout << "********** Testing AVL Tree Insert **********" << std::endl;
	AVLTree<int>avltree;
	avltree.insert(100);
	avltree.insert(20);
	avltree.insert(30);
	avltree.insert(40);
	avltree.insert(50);
	avltree.insert(60);
	avltree.insert(70);
	avltree.insert(80);
	avltree.insert(90);
	avltree.printInorder();
}

void test_AVLTree_Contains()
{
	std::cout << "********** Testing AVL Tree conatins **********" << std::endl;
	AVLTree<int>avltree;
	avltree.insert(100);
	avltree.insert(20);
	avltree.insert(30);
	avltree.insert(40);
	avltree.insert(50);
	avltree.insert(60);
	avltree.insert(70);
	avltree.insert(80);
	avltree.insert(90);
	avltree.printInorder();
	std::cout<< "contains 90:" << avltree.contains(90)<< std::endl;
	std::cout<< "contains 110:" << avltree.contains(110)<< std::endl;
}

void test_AVLTree_Height()
{
	std::cout << "********** Testing AVL Tree Height **********" << std::endl;
	AVLTree<int>avltree;
	avltree.insert(50);
	avltree.insert(20);
	avltree.insert(30);
	avltree.insert(40);
	avltree.insert(10);
	avltree.insert(60);
	avltree.insert(70);
	avltree.insert(80);
	avltree.insert(90);
	avltree.printInorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;

}


void test_AVLTree_Driver()
{
	test_AVLTree_Basic_Insert();
	test_AVLTree_Contains();
	test_AVLTree_Height();
}
