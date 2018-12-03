/*
 * RedBlackTree.h
 *
 *  Created on: 01-Dec-2018
 *      Author: vijay
 */

#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_
template<typename T>
class RedBlackTree {
public:
	class Tree{
	public:
		Tree(T value):value_(value), left_(nullptr), right_(nullptr),parent_(nullptr),
				isLeftChild_(false),
				black_(false){}
		virtual ~Tree(){}
	    T value_;
	    Tree*  left_;
	    Tree* right_;
	    Tree* parent_;
		bool isLeftChild_;
		bool black_;
	};


	RedBlackTree():size_(0), root_(nullptr){}
	virtual ~RedBlackTree(){}

	void add(T value)
	{
        auto newNode = new Tree(value);
		if(root_ == nullptr)
		{
			root_= newNode;
			root_->black_ = true;
		}
		else
		{
            add(root_, newNode);
		}
		size_++;
	}

	void inorderPrint()
	{
		inOrderPrintHelper(root_);
		std::cout<<std::endl;
	}

	void levelorderPrint()
	{
		levelOrderPrintHelper(root_);
		std::cout<<std::endl;
	}

	void checkColor(Tree* node)
	{
		if(node == root_)
			return;
		if(!node->black_ && !node->parent_->black_)
			correctTree(node);
		checkColor(node->parent_);

	}

	void correctTree(Tree* node)
	{
		if(node->parent_->isLeftChild_)
		{
			if(node->parent_->parent_->right_ == nullptr ||
					node->parent_->parent_->right_->black_)
			{
				rotate(node);
				return;
			}

			if(node->parent_->parent_->right_ != nullptr)
			{
				node->parent_->parent_->right_->black_ = true;
			}

			node->parent_->parent_->black_ = false;
			node->parent_->black_ =true;
			return;
		}
		else
		{
			if(node->parent_->parent_->left_ == nullptr ||
					node->parent_->parent_->left_->black_)
			{
				rotate(node);
				return;
			}

			if(node->parent_->parent_->left_ != nullptr)
			{
				node->parent_->parent_->left_->black_ = true;
			}

			node->parent_->parent_->black_ = false;
			node->parent_->black_ =true;
			return;
		}
	}

	void rotate(Tree* node)
	{
		if(node->isLeftChild_)
		{
			if(node->parent_->isLeftChild_)
			{
				rightRotate(node->parent_->parent_);
				node->black_ = false;
				node->parent_->black_ = true;
				if(node->parent_->right_ != nullptr)
				{
					node->parent_->right_->black_ =false;
				}
			}
			else
			{
				rightLeftRotate(node->parent_->parent_);
				node->black_ = true;
				node->right_->black_ = false;
				node->left_->black_ =false;
			}
		}
		else
			{
				if(!node->parent_->isLeftChild_)
				{
					leftRotate(node->parent_->parent_);
					node->black_ = false;
					node->parent_->black_ = true;
					if(node->parent_->left_ != nullptr)
					{
						node->parent_->left_->black_ =false;
					}
				}
				else
				{
					leftRightRotate(node->parent_->parent_);
					node->black_ = true;
					node->right_->black_ = false;
					node->left_->black_ =false;
				}
			}
	}


private:
    void inOrderPrintHelper(Tree* node)
    {
    	if(node == nullptr)
    		return;
    	inOrderPrintHelper(node->left_);
    	std::cout<< node->value_ << " ";
    	inOrderPrintHelper(node->right_);
    }

    void levelOrderPrintHelper(Tree* node)
    {
    	if(node == nullptr)
    		return;
    	std::queue<Tree*> lvlQueue;
    	lvlQueue.push(node);
    	while(!lvlQueue.empty())
    	{
    		auto qfront = lvlQueue.front();
    		lvlQueue.pop();

    		std::cout<< qfront->value_ << " ";
    		if(qfront->left_ != nullptr)
    			lvlQueue.push(qfront->left_);
    		if(qfront->right_ != nullptr)
    			lvlQueue.push(qfront->right_);
    	}
    }
	void add(Tree* parent, Tree* newNode)
	{

		if(newNode->value_ > parent->value_)
		{
			if(parent->right_ ==nullptr)
			{
				parent->right_ = newNode;
				newNode->parent_ = parent;
				newNode->isLeftChild_ = false;
				return;
			}
			add(parent->right_, newNode);
			return;
		}
		else
		{
			if(parent->left_ ==nullptr)
			{
				parent->left_ = newNode;
				newNode->parent_ = parent;
				newNode->isLeftChild_ = true;
				return;
			}
			add(parent->left_, newNode);
			return ;
		}

		//check(newNode);
	}
	int size_;
	 Tree* root_;
};

#endif /* REDBLACKTREE_H_ */
