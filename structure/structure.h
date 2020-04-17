#pragma once
#include "../myInclude.h"
// ARRAY CLASS=====================================================
// Linked List Array
class llArr {
private:
	int count = 0;
	int arr[SIZE_ARR];

public:
	void addEnd(int data);
	void ins(int data);
	void arrShow();
};

class stArr {
public:
	stArr() {
		topIdx = -1;
	}

	void	stPushArr(int data);
	int		stPopArr();
	void	stShowArr();

private:
	int topIdx;
	int stack[TOP_SIZE];
};

class queArr {
private:
	int queue[QUEUE_SIZE];
	int queFront = 0;
	int queRear = 0;

public:
	void quePushArr(int data);
	int quePopArr();
	void queShowArr();
};

// STRUCTURE=======================================================
// Linked List Single Side
typedef struct nodeS {
	int		data;
	nodeS	*next;
};

void insS(int data);
void delBeginS();
void llShowS();
void freeAllS();

// Linked List Double Side

typedef struct nodeD {
	int		nodeNum;
	int		data;
	nodeD	*next;
	nodeD	*prev;
};
void insD(int data, int &count);
void delBeginD();
void llShowD();
void freeAllD();

// Stack Linked List
typedef struct stList {
	int data;
	struct stList *next;
};

typedef struct _StackS {
	stList *top;
}StackS;
void stPushLl(StackS *stack, int data);
int  stPopLl(StackS	*stack);
void stShowLl(StackS *stack);
void stFreeLl(StackS *stack);


// Queue Linked List
typedef struct QueueS {
	int count;
	struct queList *front;
	struct queList *rear;
};

typedef struct queList {
	int data;
	struct queList *next;
};

void quePushLl(QueueS *queue, int data);
int  quePopLl(QueueS *queue);
void queShowLl(QueueS *queue);
void queFreeLl(QueueS *queue);

// Graph ================================================================
// Graph Structure
typedef struct nodeG {
	int index;
	int weight;
	struct nodeG *next;
};
nodeG** setInitNode(const int _size);
void insG(nodeG *root, const int _index, const int _weight);
void showAllG(nodeG *root);
void freeAllG(nodeG **root, const int _size);

// biTree class
class biSearch {
private:
	int arr[SIZE_ARR];
	int idxCnt;
public:
	int startIdx;
	int endIdx;
	biSearch(vector<int> inputVec) {
		for (int i = 0; i < inputVec.size(); i++) {
			idxCnt = i;
			arr[i] = inputVec[i];
		}
		startIdx = 0;
		endIdx = idxCnt;
	}
	int search(int startIdx, int endIdx, int target);
};

// Priority Queue =========================================
#define SIZE_HEAP (100)
enum { DW, UP };
class pQueArr {
private:
	int heap[SIZE_HEAP];
	int count;
	int type;
public:
	pQueArr(const int _type);
	~pQueArr();
	void heapify(const int cur);
	void swap(int &a, int &b);
	void show();
	void push(const int data);
	int  pop();
};

// Main Series =========================================================
int main_llArr();

int main_llSingleS();

int main_llDoubleS();

int main_stArr();

int main_stList();

int main_queArr();

int main_queList();

int main_sequentialSearch();

int main_graph();