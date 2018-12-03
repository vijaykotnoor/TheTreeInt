/*
 * BST_test.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: vkotnoor
 */

#include "BST.h"


void test_BST_Insert()
{
	std::cout << "********** Testing BST Insert **********" << std::endl;
	BST<int> btree;
	btree.insert(100);
	btree.insert(20);
	btree.insert(30);
	btree.insert(40);
	btree.insert(50);
	btree.insert(60);
	btree.insert(70);
	btree.insert(80);
	btree.insert(90);
	btree.printInorder();
}

void test_BST_Search()
{
	std::cout << "\n********** Testing BST Search **********" << std::endl;
	BST<int> btree;
	btree.insert(10);
	btree.insert(20);
	btree.insert(30);
	btree.insert(40);
	btree.insert(50);
	btree.insert(60);
	btree.insert(70);
	btree.insert(80);
	btree.insert(90);
	btree.printInorder();
	std::cout << "\n70 found is:" << btree.search(70)<<std::endl;
	std::cout << "110 found is:" << btree.search(110)<<std::endl;
	std::cout << "20 found is:" << btree.search(20)<<std::endl;
	std::cout << "-10 found is:" << btree.search(-10)<<std::endl;

}

void test_BST_driver()
{
	test_BST_Insert();
	test_BST_Search();
}
