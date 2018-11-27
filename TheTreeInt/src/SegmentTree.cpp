/*
 * segmentTree.cpp
 *
 *  Created on: 26-Nov-2018
 *      Author: vijay
 */
#include <iostream>
#include "SegmentTree.h"


SegmentTree::SegmentTree(int size):size_(size),tree_(2*size, 0) {
	// TODO Auto-generated constructor stub

}

SegmentTree::~SegmentTree() {
	// TODO Auto-generated destructor stub
}

void SegmentTree::buildAddition(std::vector<int>& inputArray)
{
	//copy the input array from n+1 index
	for(auto i = 0;i < size_; i++)
	{
		tree_[size_ +i] = inputArray[i];
	}

    // 0 index does not contain any thing
	// rest of the indeses will be filled based on the value from the indexes alredy filled
	// we do a left shift which double the number and the or with the last bit is always plus one
	// we can use plus one also.
	//ex if the size is 8 then
	// tree[7] = tree[14]+tree_[15]                 (1)
	// tree[6] = tree[12]+tree_[13]                 (2)
	// tree[5] = tree[10]+tree_[11]
	// tree[4] = tree[8]+tree_[9]
	// tree[3] = tree[6]+tree_[7]=tree[12]+tree_[13]+tree[14]+tree_[15]
	// tree[2] = tree[4]+tree_[5]=tree[8]+tree_[9]+tree[10]+tree_[11]
	// tree[1] = tree[2]+tree_[3]=sum of all
	// tree[0] = never updated and used.

	for(auto i = size_ - 1; i > 0; i--)
	{
		tree_[i] = tree_[i << 1] + tree_[i << 1 | 1];
	}
}

void SegmentTree::buildMinimum(std::vector<int>& inputArray)
{
	//copy the input array from n+1 index
	for(auto i = 0;i < size_; i++)
	{
		tree_[size_ +i] = inputArray[i];
	}

	for(auto i = size_ - 1; i > 0; i--)
	{
		tree_[i] = std::min(tree_[i << 1] , tree_[i << 1 | 1]);
	}
}

void SegmentTree::updateAdditionTree(int idx, int val)
{
	//add the size to idx to update the value

	tree_[size_ + idx] = val;
	//update the parents by shifting left and finding the index
	//if the size is 8 and idx 3 then parent 5 , 2, 1 are updated
	// the xor makes sure whether to pick value from the left or right of the index updated
	//O(logn)
	for(auto i = size_ + idx; i > 1; i = i >> 1)
	{
		tree_[i >> 1] = tree_[i] + tree_[i^1];
	}
}

void SegmentTree::updateMinimumTree(int idx, int val)
{

	tree_[size_ + idx] = val;
	for(auto i = size_ + idx; i > 1; i = i >> 1)
	{
		tree_[i >> 1] = std::min(tree_[i] , tree_[i^1]);
	}
}

void SegmentTree::printTree(){
	for(auto const elem : tree_)
		std::cout<< elem <<" ";
	std::cout << std::endl;
}
//r is not inclusive int this case
//add one to it if you want to make it inclusive
int SegmentTree::queryAddition(int l, int r){
	int res = 0;
	// when given a range of values we pick based on the indexes
	// we use the size to go to the indexes
	// the logic below makes sure that we add the nodes which
	/// are needed in the tree.
	// even and odd numbers are used here to do that.
	for(l += size_, r +=size_; l<r; l>>=1, r>>=1)
	{
		if((l & 1)> 0)
			res += tree_[l++];
		if((r & 1) >0)
			res += tree_[--r];
	}
	return res;
}

int SegmentTree::queryMinimum(int l, int r){
	int res = INT_MAX;

	for(l += size_, r +=size_; l<r; l>>=1, r>>=1)
	{
		if((l & 1)> 0)
			res = std::min(res, tree_[l++]);
		if((r & 1) >0)
			res = std::min(res, tree_[--r]);
	}
	return res;
}



