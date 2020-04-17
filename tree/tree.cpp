#include "tree.h"

// Skew Tree
Tree::Tree(const int _rootData) : TreeInit() {
	root->data = _rootData;
	printf("root node address: %p, data: %d\n", root, root->data);
}

Tree::~Tree() {
	deleteAll(root->childL);
	deleteAll(root->childR);
}

void Tree::ins(const int _data) {
	root = insRecur(root, _data);
}

void Tree::del(const int _data) {
	root = delRecur(root, _data);
}

Node* Tree::insRecur(Node *curNode, const int _data) {
 	if (curNode == nullptr) {
		curNode = new Node;
		curNode->childL = nullptr;
		curNode->childR = nullptr;
		curNode->data	= _data;
		printf("newNode address: %p, data: %d\n", curNode, curNode->data);
		return curNode;
	} else {
		if (curNode->data > _data) {
			curNode->childL = insRecur(curNode->childL, _data);
		} else {
			curNode->childR = insRecur(curNode->childR, _data);
		}
		return curNode;
	}
}

Node* Tree::delRecur(Node *curNode, const int _data) {
	if (curNode == nullptr) {
		printf("%d was not found.\n", _data);
		return nullptr;
	} else {
		if (curNode->data > _data) {
			curNode->childL = delRecur(curNode->childL, _data);
		} else if (curNode->data < _data) {
			curNode->childR = delRecur(curNode->childR, _data);
		} else { // curNode->data == _data
			if (curNode->childL == nullptr && curNode->childR == nullptr) {
				//printf("case1 - del Node address: %p, data: %d\n", curNode, curNode->data);
				delete curNode;
				curNode = nullptr;
				return curNode;
			} else if (curNode->childL != nullptr && curNode->childR != nullptr) {
				//printf("case2 - del Node address: %p, data: %d\n", curNode, curNode->data);
				Node* minNode = findMin(curNode->childR);
				curNode->data = minNode->data;
				curNode->childR = delRecur(curNode->childR, minNode->data);
				return curNode;
			} else {
				//printf("case3 - del Node address: %p, data: %d\n", curNode, curNode->data);
				Node* curNodeChild = curNode->childL != nullptr ? curNode->childL : curNode->childR;
				delete curNode;
				curNode = nullptr;
				return curNodeChild;
			}
		}
		return curNode;
	}
}

Node* Tree::findMin(Node *curNode) {
	if (curNode->childL != nullptr) {
		return findMin(curNode->childL);
	} else { 
		return curNode; 
	}
}

void Tree::show(Node *curNode) {
	if (curNode != nullptr) {
		show(curNode->childL);
		printf("%p / %d, ", curNode, curNode->data);
		show(curNode->childR);
		cout << endl;
	}
}

void Tree::deleteAll(Node *curNode) {
	if (curNode == nullptr) {
		return;
	}
	else {
		deleteAll(curNode->childL);
		deleteAll(curNode->childR);
		printf("free Node address: %p, data: %d\n", curNode, curNode->data);
		delete curNode;
		curNode = nullptr;
		return;
	}
}

void Tree::insStudy(const int _data) {
	Node *newNode = new Node;
	newNode->childL = nullptr;
	newNode->childR = nullptr;
	newNode->data = _data;

	Node *curNode = root;
	Node *prevNode = root;
	bool leftFlag = true;
	while (curNode != nullptr) {
		prevNode = curNode;
		if (curNode->data > _data) {
			curNode = curNode->childL;
			leftFlag = true;
		}
		else {
			curNode = curNode->childR;
			leftFlag = false;
		}
	}

	if (leftFlag) {
		prevNode->childL = newNode;
	}
	else {
		prevNode->childR = newNode;
	}
}
void Tree::delStudy(const int _data) {
	Node *curNode = root;
	Node *prevNode = root;
	Node *delNode = nullptr;

	bool leftFlag = true;
	while (curNode != nullptr) {
		if (curNode->data > _data) {
			prevNode = curNode;
			curNode = curNode->childL;
			leftFlag = true;
		}
		else if (curNode->data < _data) {
			prevNode = curNode;
			curNode = curNode->childR;
			leftFlag = false;
		}
		else { // curNode->data == _data
			if (curNode->childL != nullptr && curNode->childR != nullptr) {
				cout << "Case 3" << endl;
				printf("delNode: %p / %d\n", curNode, curNode->data);
				Node *minNode = curNode->childR;
				Node *minPrevNode = minNode;
				while (minNode->childL != nullptr) {
					minPrevNode = minNode;
					minNode = minNode->childL;
				}
				curNode->data = minNode->data;

				minPrevNode->childL = nullptr; // minNode
				delete minNode;
			}

			else if (curNode->childL != nullptr) {
				cout << "Case 2(L)" << endl;
				if (leftFlag) {
					prevNode->childL = curNode->childL;
				}
				else {
					prevNode->childR = curNode->childL;
				}
				printf("delNode: %p / %d\n", curNode, curNode->data);
				delete curNode;
			}

			else if (curNode->childR != nullptr) {
				cout << "Case 2(R)" << endl;
				if (leftFlag) {
					prevNode->childL = curNode->childR;
				}
				else {
					prevNode->childR = curNode->childR;
				}
				printf("delNode: %p / %d\n", curNode, curNode->data);
				delete curNode;
			}

			else {
				cout << "Case 1" << endl;
				printf("delNode: %p / %d\n", curNode, curNode->data);
				delete curNode;
				if (leftFlag) {
					prevNode->childL = nullptr;
				}
				else {
					prevNode->childR = nullptr;
				}
			}
			curNode = nullptr;
		}
	}
}


// AVL Tree
TreeAVL::TreeAVL(const int _rootData) : Tree(_rootData) {}
TreeAVL::~TreeAVL() {}

int TreeAVL::getHeight(Node *curNode) {
	return (curNode == nullptr ? 0 : curNode->height);
}

void TreeAVL::setHeight(Node *curNode) {
	//printf("curNode->L/R address: %p / %p\n", curNode->childL, curNode->childR);
	curNode->height = MAX(getHeight(curNode->childL), getHeight(curNode->childR)) + 1;
}

int TreeAVL::getBF(Node *curNode) {
	return (curNode == nullptr ? 0 : getHeight(curNode->childL) - getHeight(curNode->childR));
}

Node* TreeAVL::rot(Node *curNode, const int type) {
	Node *curNodeChildL = curNode->childL;
	Node *curNodeChildR = curNode->childR;
	switch(type){
		case LL	:	printf("LL\n");
					curNode->childL = curNodeChildL->childR;
					curNodeChildL->childR = curNode;
					setHeight(curNode);
					return curNodeChildL;
					break;

		case RR :	printf("RR\n"); 
					curNode->childR = curNodeChildR->childL;
					curNodeChildR->childL = curNode;
					setHeight(curNode);
					return curNodeChildR;
					break;

		case LR :	printf("LR\n");
					curNode->childL = rot(curNodeChildL, RR);
					setHeight(curNode->childL);
					return rot(curNode, LL);
					break;

		case RL :	printf("RL\n");
					curNode->childR = rot(curNodeChildR, LL);
					setHeight(curNode->childR);
					return rot(curNode, RR);
					break;
		default :	break;
	}

}

Node* TreeAVL::bal(Node *curNode) {
	if (getBF(curNode) >= 2) {
		if (getBF(curNode->childL) >= 1) {
			curNode = rot(curNode, LL);
		} else {
			curNode = rot(curNode, LR);
		}
	} else if (getBF(curNode) <= -2) {
		if (getBF(curNode->childR) <= -1) {
			curNode = rot(curNode, RR);
		} else {
			curNode = rot(curNode, RL);
		}
	} else {}
	setHeight(curNode); // after rearanging, reset the height
	return curNode;
}

void TreeAVL::ins(const int _data) {
	root = insRecur(root, _data);
}

Node* TreeAVL::insRecur(Node *curNode, const int _data) {
	if (curNode == nullptr) {
		curNode = new Node;
		curNode->childL = nullptr;
		curNode->childR = nullptr;
		curNode->data = _data;
		curNode->height = 1;
		printf("newNode address: %p, data: %d\n", curNode, curNode->data);
	} else {
		if (curNode->data > _data) {
			curNode->childL = insRecur(curNode->childL, _data);
			curNode = bal(curNode);
		} else {
			curNode->childR = insRecur(curNode->childR, _data);
			curNode = bal(curNode);
		}
	}
	return curNode;
}

// Priority Queue using Node
pQue::pQue(int _size) {
	size = _size;
	count = 0;
	heap = new Node *[size];
	tempNode = new Node; // space for popNode
}

pQue::~pQue() {
	for (int i = 0; i < count; i++) {
		if (heap[i] != nullptr) { // when using with graph
			printf("free heap[%d] adress: %p\n", i, heap[i]);
			delete heap[i];
		}
	}
	
	delete tempNode;
	printf("free all heap\n");
	delete[] heap;
}

void pQue::swap(Node *a, Node *b) {
	int tempIdx, tempWeight;
	
	tempIdx = a->index;
	a->index = b->index;
	b->index = tempIdx;

	tempWeight = a->weight;
	a->weight = b->weight;
	b->weight = tempWeight;
}

void pQue::push(Node *curNode) {
	if (count >= size) {
		printf("It's over the size");
		return;
	} else {
		int curIdx = count;
		heap[curIdx] = new Node;
		heap[curIdx]->index		= curNode->index;
		heap[curIdx]->weight	= curNode->weight;
		printf("push node address/index/weight: %p/%d/%d\n", heap[curIdx], heap[curIdx]->index, heap[curIdx]->weight);
		int parentIdx = (curIdx - 1) / 2;

		while (curIdx > 0 && (heap[curIdx]->weight < heap[parentIdx]->weight)) {
			swap(heap[curIdx], heap[parentIdx]);
			curIdx = parentIdx;
			parentIdx = (curIdx - 1) / 2;
		}
		count++;
	}
}

Node* pQue::pop() {
	if (count <= 0) {
		printf("heap underflow!!\n");
		return nullptr;
	}
	else {
		tempNode->index = heap[0]->index; // using stack memory
		tempNode->weight = heap[0]->weight; // using stack memory
		Node *popNode = tempNode; 
		int beginIdx = 0;
		int endIdx = count - 1;
		swap(heap[beginIdx], heap[endIdx]);
		printf("free last index address/index/weight: %p\n", heap[endIdx]);
		delete heap[endIdx];

		if (count > 1) {
			heapify(beginIdx);
		} else {}

		printf("pop node address/index/weight: %p/%d/%d without dynamic mem\n", popNode, popNode->index, popNode->weight);
		count--;
		return popNode;
	}
}

void pQue::heapify(const int curIdx) {
	int childLIdx = curIdx * 2 + 1; // child index setting using cur index
	int childRIdx = curIdx * 2 + 2;
	int tarIdx = childLIdx;
	int endIdx = count - 1;

	if (tarIdx >= endIdx - 1) { // target limit range setting
		return;
	} else {}

	// target setting --> compare child node --> set finish condition
	if ((tarIdx < count) && (heap[childLIdx]->weight > heap[childRIdx]->weight)) {
		tarIdx = childRIdx;
	} else {}

	if (heap[curIdx]->weight > heap[tarIdx]->weight) {
		swap(heap[curIdx], heap[tarIdx]);
	} else { return; }

	if (tarIdx <= count / 2) {
		heapify(tarIdx);
	} else {}
}

void pQue::show() {
	printf("\nelements of arr:\n");
	for (int i = 0; i < count; i++) {
		if (i == count - 1) {
			printf("%d/%d ", heap[i]->index, heap[i]->weight);
		}
		else {
			printf("%d/%d, ", heap[i]->index, heap[i]->weight);
		}
	}
	printf("\n\n");
}

int pQue::getCount() {
	return count;
}

int pQue::getSize() {
	return size;
}

// Segment tree
segTree::segTree(int *_arr, int _arrSize) {
	arrSize = _arrSize;
	arr = _arr;

	arrBegIdx = 0;
	arrEndIdx = arrSize - 1;

	treeSize = _arrSize * 4;
	tree = new int[treeSize];

	for (int i = 0; i < treeSize; i++) {
		tree[i] = 0;
	}
}
segTree::~segTree() {
	delete[] tree;
}

void segTree::show() {
	printf("array elements\n");
	for (int i = 0; i < arrSize; i++) {
		if (i == arrSize - 1) {
			printf("%d\n", arr[i]);
		}
		else {
			printf("%d, ", arr[i]);
		}
	}

	printf("segTree elements\n");
	for (int i = 0; i < treeSize; i++) {
		if (i == treeSize - 1) {
			printf("%d\n", tree[i]);
		}
		else {
			printf("%d, ", tree[i]);
		}
	}

}

void segTree::setInit() {
	setTree(arrBegIdx, arrEndIdx, 0);
}

int segTree::setTree(int begIdx, int endIdx, int curIdx) {
	int childLIdx = curIdx * 2 + 1;
	int childRIdx = curIdx * 2 + 2;

	if (begIdx == endIdx) {
		tree[curIdx] = arr[begIdx];
		return tree[curIdx];
	}
	else {
		int midIdx = (begIdx + endIdx) / 2;
		tree[childLIdx] = setTree(begIdx, midIdx, childLIdx);
		tree[childRIdx] = setTree(midIdx + 1, endIdx, childRIdx);
		tree[curIdx] = tree[childLIdx] + tree[childRIdx];
		return tree[curIdx];
	}
}

int segTree::segSum(int _segLIdx, int _segRIdx) {
	segLIdx = _segLIdx;
	segRIdx = _segRIdx;
	return getSegSum(arrBegIdx, arrEndIdx, 0);
}

int segTree::getSegSum(int begIdx, int endIdx, int curIdx) {
	int childLIdx = curIdx * 2 + 1;
	int childRIdx = curIdx * 2 + 2;

	if (segRIdx < begIdx || segLIdx > endIdx) {
		return 0; // condition about leaf which is not including seg range
	}
	else if (segLIdx <= begIdx && segRIdx >= endIdx) {
		return tree[curIdx];
	}
	else {
		int midIdx = (begIdx + endIdx) / 2;
		tree[childLIdx] = getSegSum(begIdx, midIdx, childLIdx);
		tree[childRIdx] = getSegSum(midIdx + 1, endIdx, childRIdx);

		return tree[childLIdx] + tree[childRIdx];
	}
}

void segTree::update(int _modIdx, int modVal) {
	modIdx = _modIdx;
	diff = modVal - arr[modIdx];

	updateTree(arrBegIdx, arrEndIdx, 0);
}

void segTree::updateTree(int begIdx, int endIdx, int curIdx) {
	int childLIdx = curIdx * 2 + 1;
	int childRIdx = curIdx * 2 + 2;

	if (begIdx <= modIdx && modIdx <= endIdx) {
		tree[curIdx] += diff;
		if (begIdx == endIdx) {
			return;
		}
		else {
			int midIdx = (begIdx + endIdx) / 2;
			updateTree(begIdx, midIdx, childLIdx);
			updateTree(midIdx + 1, endIdx, childRIdx);
		}
	}
	else {
		return;
	}

}