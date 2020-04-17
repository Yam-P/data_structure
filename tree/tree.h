#ifndef _TREE
#define _TREE

#include "../myInclude.h"
#include "../graph/graph.h"
#include "../linked_list/linked_list.h"

class Node;

class TreeInit {
public:
	Node *root;

	TreeInit(){
		root = new Node;
		root->data = 0;
		root->childL = NULL;
		root->childR = NULL;
		printf("set root node address: %p, data: %d\n", root, root->data);
	}
	~TreeInit(){
		printf("del root node address: %p, data: %d\n", root, root->data);
		delete root;
	}

	
};

// Skew Tree
class Tree : public TreeInit {
public:
	Tree(int _rootData);
	~Tree();

	void show(Node *curNode); // method: In Order
	
	void insStudy(const int _data);
	void delStudy(const int _data);
	Node* findMin(Node *curNode);

	void ins(const int _data);
	void del(const int _data);
	Node* insRecur(Node *curNode, const int _data);
	Node* delRecur(Node *curNode, const int _data);

	void deleteAll(Node *curNode);
	
	/*void inOrder(Node *curNode);*/
};

// AVL Tree
enum { LL, RR, LR, RL };

class TreeAVL : public Tree {
public:
	TreeAVL(const int _rootData);
	~TreeAVL();

	int getHeight(Node *curNode);
	void setHeight(Node *curNode);
	int getBF(Node *curNode);

	void ins(const int _data);
	Node* insRecur(Node *curNode, const int _data);

	Node* rot(Node *curNode, const int type);
	Node* bal(Node *curNode);
};

// Priority Queue
class pQue {
private:
	int size;
	Node **heap;
	Node *tempNode;
	int count;

public:
	pQue(int _size);
	~pQue();

	void swap(Node *a, Node *b);
	void push(Node *curNode);
	Node* pop();
	void heapify(const int cur);
	void show();
	int getCount();
	int getSize();
};

// Segment Tree
class segTree {
private:
	int *tree;
	int treeSize;

	int *arr;
	int arrSize;

	int arrBegIdx;
	int arrEndIdx;
	int segLIdx;
	int segRIdx;

	int diff;
	int modIdx;
public:
	segTree(int *arr, int _arrSize);
	~segTree();

	void setInit();
	int setTree(int begIdx, int endIdx, int curIdx);

	int segSum(int _segLIdx, int _segRIdx);
	int getSegSum(int begIdx, int endIdx, int curIdx);

	void update(int _modIdx, int modNum);
	void updateTree(int begIdx, int endIdx, int curIdx);

	void show();
};

#endif
