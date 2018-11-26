/*
 * Tree.h
 *
 *  Created on: 24-Nov-2018
 *      Author: vijay
 */

#ifndef TREE_H_
#define TREE_H_
template<typename T>
class Tree {
public:
	Tree(T data):left_(nullptr),right_(nullptr), data_(data){}
	Tree(Tree* left, Tree* right, T data):left_(nullptr),right_(nullptr), data_(data){}
	Tree(Tree* left, Tree* right);
	virtual ~Tree(){};
	Tree* getLeft(){
		return left_;
	}
	Tree* getRight(){
		return right_;
	}

	void setLeft( Tree* left){
		 left_ = left;
	}

	void setRight( Tree* right){
		 right_ = right;
	}

	T& getData()
	{
        return data_;
	}

	void setData(T data){
		data_= data;
	}
private:
	Tree* left_;
	Tree* right_;
	T data_;
};

#endif /* TREE_H_ */
