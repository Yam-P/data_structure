#pragma once

#include "../myInclude.h"

#define SORT_VECTOR_SIZE	(5)

class myVec{
private:
public:
	vector<int> vec;
	myVec(){}
	void setVec(vector<int> inputVec);
	void showVec();
	void swapVec(int &a, int &b);
};

class mySort : myVec{
private:
	vector<int> sortVec;
public:
	mySort(vector<int> inputVec) : myVec(){
		setVec(inputVec);
	}
	void show(void);

	void sortSelectVec(bool ascend);
	void sortInsertVec(bool ascend);
	void sortBubbleVec(bool ascend);
	void sortQuickVec(int start, int end);
	void sortRankVec();
	void sortRadixVec();
};

