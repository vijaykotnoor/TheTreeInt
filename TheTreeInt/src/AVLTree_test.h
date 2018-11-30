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

void test_AVLTree_Left_heavy()
{
	std::cout << "********** Testing AVL Tree Left Left Case **********" << std::endl;
	AVLTree<int>avltree;
	avltree.insert(90);
	avltree.insert(80);
	avltree.insert(70);
	avltree.insert(60);
	avltree.insert(50);
	avltree.insert(40);
	avltree.insert(30);
	avltree.insert(20);
	avltree.insert(10);
	avltree.printInorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;

}

void test_AVLTree_Right_heavy()
{
	std::cout << "********** Testing AVL Right Right Case **********" << std::endl;
	AVLTree<int>avltree;
	avltree.insert(10);
	avltree.insert(20);
	avltree.insert(30);
	avltree.insert(40);
	avltree.insert(50);
	avltree.insert(60);
	avltree.insert(70);
	avltree.insert(80);
	avltree.insert(90);
	avltree.printInorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;

}

void test_AVLTree_Left_Right()
{
	std::cout << "********** Testing AVL Tree Left Right Case **********" << std::endl;
	AVLTree<int>avltree;
	avltree.insert(10);
	avltree.insert(20);
	avltree.insert(30);
	avltree.insert(27);
	avltree.insert(29);
	avltree.printInorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;

}

void test_AVLTree_Right_Left()
{
	std::cout << "********** Testing AVL Right Left Case **********" << std::endl;
	AVLTree<int>avltree;
	avltree.insert(10);
	avltree.insert(20);
	avltree.insert(30);
	avltree.insert(40);
	avltree.insert(35);
	avltree.printInorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;

}

void test_AVLTree_Removal()
{
	std::cout << "********** Testing AVL Right Right Case **********" << std::endl;
	AVLTree<int>avltree;
	avltree.insert(10);
	avltree.insert(20);
	avltree.insert(30);
	avltree.insert(40);
	avltree.insert(50);
	avltree.insert(60);
	avltree.insert(70);
	avltree.insert(80);
	avltree.insert(90);
	avltree.printInorder();
	avltree.printLevelorder();
	std::cout<< "Remove 90 :" << avltree.remove(90)<< std::endl;
	avltree.printInorder();
	avltree.printLevelorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;
	std::cout<< "Remove 80 :" << avltree.remove(80)<< std::endl;
	avltree.printInorder();
	avltree.printLevelorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;
	std::cout<< "Remove 70 :" << avltree.remove(70)<< std::endl;
	avltree.printInorder();
	avltree.printLevelorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;
	std::cout<< "Remove 60 :" << avltree.remove(60)<< std::endl;
	avltree.printInorder();
	avltree.printLevelorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;
	std::cout<< "Remove 50 :" << avltree.remove(50)<< std::endl;
	avltree.printInorder();
	avltree.printLevelorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;
	std::cout<< "Remove 40 :" << avltree.remove(40)<< std::endl;
	avltree.printInorder();
	avltree.printLevelorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;
	std::cout<< "Remove 30 :" << avltree.remove(30)<< std::endl;
	avltree.printInorder();
	avltree.printLevelorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;
	std::cout<< "Remove 20 :" << avltree.remove(20)<< std::endl;
	avltree.printInorder();
	avltree.printLevelorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;
	std::cout<< "Remove 10 :" << avltree.remove(10)<< std::endl;
	avltree.printInorder();
	avltree.printLevelorder();
	std::cout<< "Height :" << avltree.getHeight()<< std::endl;


}

void test_AVLTree_Driver()
{
	test_AVLTree_Basic_Insert();
	test_AVLTree_Contains();
	test_AVLTree_Height();
	test_AVLTree_Left_heavy();
	test_AVLTree_Right_heavy();
	test_AVLTree_Left_Right();
	test_AVLTree_Right_Left();
	test_AVLTree_Removal();
}
