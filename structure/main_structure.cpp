#include "structure.h"
int main_llArr() {
	llArr arrEx;

	arrEx.ins(5);
	arrEx.ins(4);
	arrEx.addEnd(1);
	arrEx.arrShow();

	return 0;
}

extern nodeS *headS;
int main_llSingleS() {
	headS = (nodeS*)malloc(sizeof(nodeS));
	headS->next = NULL;
	headS->data = 0;
	printf("address of head: %p\n", headS);
	insS(1);
	insS(2);
	insS(3);
	cout << endl;
	llShowS();
	freeAllS();

	return 0;
}

extern nodeD *headD;
extern nodeD *tailD;
int main_llDoubleS() {
	int count = 0;
	headD = (nodeD *)malloc(sizeof(nodeD));
	tailD = (nodeD *)malloc(sizeof(nodeD));
	printf("address of head: %p\n", headD);
	printf("address of tail: %p\n", tailD);

	headD->next = tailD;
	headD->prev = headD;
	headD->data = 1;
	headD->nodeNum = count;

	tailD->prev = headD;
	tailD->next = NULL;
	tailD->data = 5;

	insD(2, count);
	insD(3, count);
	insD(4, count);
	tailD->nodeNum = ++count;
	cout << endl;

	delBeginD();

	llShowD();
	freeAllD();


	return 0;
}

int main_stArr() {
	stArr stackEx;
	stackEx.stPushArr(7);
	stackEx.stPushArr(5);
	stackEx.stPushArr(4);
	stackEx.stPopArr();
	stackEx.stPushArr(6);
	stackEx.stPopArr();

	stackEx.stShowArr();

	return 0;
}

int main_stList() {
	StackS *stEx = (StackS *)malloc(sizeof(StackS));
	stEx->top = NULL;

	stPushLl(stEx, 1);
	stPushLl(stEx, 2);
	stPushLl(stEx, 3);
	cout << endl;

	stShowLl(stEx);
	cout << endl;

	stPopLl(stEx);
	stPushLl(stEx, 4);
	cout << endl;

	stShowLl(stEx);
	cout << endl;

	stFreeLl(stEx);

	delete stEx;

	return 0;
}

int main_queArr() {
	queArr queue;
	queue.quePushArr(7);
	queue.quePushArr(7);
	queue.quePushArr(5);

	queue.queShowArr();
	cout << endl;

	queue.quePopArr();
	queue.quePopArr();

	queue.queShowArr();
	cout << endl;

	return 0;
}

int main_queList() {
	QueueS *queEx = (QueueS *)malloc(sizeof(QueueS));
	queEx->count = 0;
	queEx->front = NULL;
	queEx->rear = NULL;

	quePushLl(queEx, 1);
	quePushLl(queEx, 2);
	quePushLl(queEx, 3);
	cout << endl;

	queShowLl(queEx);
	cout << endl;

	quePopLl(queEx);
	cout << endl;

	queShowLl(queEx);
	cout << endl;

	queFreeLl(queEx);
	delete queEx;

	return 0;
}

int main_sequentialSearch() {
	vector<int> inputVec{ 1, 2, 3, 4, 5, 6, 7 };
	biSearch biSearchEx(inputVec);
	int searchVal = 6;
	int searchIdx = biSearchEx.search(biSearchEx.startIdx, biSearchEx.endIdx, searchVal);

	printf("%d is %dth index", searchVal, searchIdx);

	return 0;
}

int main_graph() {
	int n = 5;
	int m = 4;

	nodeG **init = setInitNode(5);
	insG(init[0], 1, 9);
	insG(init[0], 2, 8);
	insG(init[0], 4, 10);
	insG(init[2], 3, 8);

	for (int i = 0; i < n; i++) {
		printf("원소 [%d] ", i);
		showAllG(init[i]);
		cout << endl;
	}

	freeAllG(init, n);
	delete init;

	return 0;
} // 무방향도 만들기!

int main_priorityQueue() {
	pQueArr pQueEx(DW);
	pQueEx.push(4);
	pQueEx.push(5);
	pQueEx.push(1);
	pQueEx.push(6);
	pQueEx.push(2);
	pQueEx.push(7);
	pQueEx.push(3);
	pQueEx.show();
	//pQueEx.show();
	//
	pQueEx.pop();
	//pQueEx.pop();
	//pQueEx.pop();
	pQueEx.show();
	//pQueEx.pop();
	//pQueEx.show();
	// 0이 왜있지==============================
	return 0;
}