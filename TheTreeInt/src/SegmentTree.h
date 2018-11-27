/*
 * segmentTree.h
 *
 *  Created on: 26-Nov-2018
 *      Author: vijay
 */

#ifndef SEGMENTTREE_H_
#define SEGMENTTREE_H_
#include <vector>
class SegmentTree {
public:
	SegmentTree(int size);
	virtual ~SegmentTree();
	void buildAddition(std::vector<int>& inputArray);
	void buildMinimum(std::vector<int>& inputArray);
	void updateAdditionTree(int idx, int val);
	void updateMinimumTree(int idx, int val);
	void printTree();
	int queryAddition(int l, int r);
	int queryMinimum(int l, int r);
private:
	int size_;
	std::vector<int> tree_;
};

#endif /* SEGMENTTREE_H_ */
