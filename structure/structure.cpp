#include "structure.h"

// ARRAY CLASS=====================================================
// Linked List Array
void llArr::addEnd(int data) {
	arr[count] = data;
	count++;
}
void llArr::ins(int data) {
	for (int i = count; i >= 1; i--)
		arr[i] = arr[i - 1];
	arr[0] = data;
	count++;
}
void llArr::arrShow() {
	for (int i = 0; i < count; i++) cout << arr[i] << endl;
}

// Stack Array
void stArr::stPushArr(int data) {
	if (topIdx == TOP_SIZE - 1) {
		printf("Stack Overflow\n");
		return;
	}
	topIdx += 1;
	stack[topIdx] = data;

}

int stArr::stPopArr() {
	if (topIdx == -1) {
		printf("Stack Underflow\n");
		return -INF;
	}
	return stack[topIdx--];
}

void stArr::stShowArr() {
	printf("stack top\n");
	for (int i = topIdx; i >= 0; i--) {
		printf("%.0f\n", stack[i]);
	}
}

// Queue Array
void queArr::quePushArr(int data) {
	if (queRear >= QUEUE_SIZE) {
		printf("Queue Overflow\n");
		return;
	}
	queue[queRear++] = data;
}

int queArr::quePopArr() {
	if (queFront < 0) {
		printf("Queue Underflow\n");
		return -INF;
	}
	return queue[queFront++];
}

void queArr::queShowArr() {
	printf("Queue Top\n");
	for (int i = queFront; i < queRear; i++) {
		printf("%d\n", queue[i]);
	}
	printf("Queue Bottom\n");
}

// STRUCTURE=======================================================
// Linked List Single Side
nodeS *headS;
void insS(int data) {
	nodeS *newNode = (nodeS*)malloc(sizeof(nodeS));
	newNode->data = data;

	newNode->next = headS->next;
	headS->next = newNode;

	printf("newNode address: %p, data: %d\n", newNode, newNode->data);
}

void delBeginS() {
	nodeS *delNode = headS->next;
	headS->next = delNode->next;
	delete delNode;
}

void llShowS() {
	nodeS *obs = headS; // observer
	while (obs != NULL) {
		printf("node address: %p, data: %d\n", obs, obs->data);
		obs = obs->next;
	}
	cout << endl;
}

void freeAllS() {
	nodeS *obs = headS;
	while (obs != NULL) {
		nodeS *aftObs = obs->next;
		printf("del node address: %p, data: %d\n", obs, obs->data);
		delete obs;
		obs = aftObs;
	}
}

// Linked List Double Side
nodeD *headD;
nodeD *tailD;
void insD(int data, int &count) {
	nodeD *newNode = (nodeD*)malloc(sizeof(nodeD));
	newNode->data = data;
	newNode->nodeNum = ++count;

	printf("node %d address: %p, data: %d\n", newNode->nodeNum, newNode, newNode->data);

	nodeD *cur = headD->next;
	nodeD *befCur = cur->prev;
	//nodeD *cur; // sort algorithm
	//cur = root->next;
	//while(cur->data < data && cur != tail){
	//	cur = cur->next;
	//}

	befCur->next = newNode;
	newNode->prev = befCur;

	cur->prev = newNode;
	newNode->next = cur;
}

void delBeginD() {
	nodeD *cur = headD->next;
	nodeD *aftCur = cur->next;

	headD->next = aftCur;
	aftCur->prev = headD;
}

void llShowD() {
	nodeD *obs = headD; // observer
	while (obs != NULL) {
		printf("node %d address: %p, data: %d\n", obs->nodeNum, obs, obs->data);
		obs = obs->next;
	}
	cout << endl;
}

void freeAllD() {
	nodeD *obs = headD;
	while (obs != NULL) {
		nodeD *aftObs = obs->next;
		printf("del node %d address: %p, data: %d\n", obs->nodeNum, obs, obs->data);
		delete obs;
		obs = aftObs;
	}
}

// Stack Linked List 
void stPushLl(StackS *stack, int data) {
	stList *newNode = (stList*)malloc(sizeof(stList));
	newNode->data = data;

	printf("new node address: %p, data: %d\n", newNode, newNode->data);

	newNode->next = stack->top;
	stack->top = newNode;
}

int stPopLl(StackS *stack) {
	if (stack->top == NULL) {
		printf("Stack Underflow\n");
		return -INF;
	}
	stList *delNode = stack->top;
	int data = delNode->data;
	stack->top = delNode->next;

	printf("del node address: %p, data: %d\n", delNode, data);
	delete delNode;
	return data;
}

void stShowLl(StackS *stack) {
	stList *cur = stack->top;
	printf("Stack Top\n");
	while (cur != NULL) {
		printf("node address: %p, data: %d\n", cur, cur->data);
		cur = cur->next;
	}
	printf("Stack Bottom\n");
}

void stFreeLl(StackS *stack) {
	stList *cur = stack->top;
	while (cur != NULL) {
		printf("free node address: %p, data: %d\n", cur, cur->data);
		stList *aftCur = cur->next;
		delete cur;
		cur = aftCur;
	}
}

// Queue Linked List
void quePushLl(QueueS *queue, int data) {
	queList *newNode = (queList *)malloc(sizeof(queList));
	newNode->data = data;
	newNode->next = NULL;

	printf("newNode address: %p, data: %d\n", newNode, newNode->data);

	if (!(queue->count)) {
		queue->front = newNode;
	}
	else {
		queue->rear->next = newNode;
	}

	queue->rear = newNode;
	queue->count += 1;
}

int quePopLl(QueueS *queue) {
	queList *delNode = queue->front;
	int data;

	printf("delNode address: %p, data: %d\n", delNode, delNode->data);

	if (!(queue->count)) {
		printf("Queue Underflow\n");
		return -INF;
	}

	else {
		queue->front = delNode->next;
		data = delNode->data;
		delete delNode;
		queue->count -= 1;
	}
	return data;
}

void queShowLl(QueueS *queue) {
	queList *cur = queue->front;

	printf("Queue Top\n");
	while (cur != NULL) {
		printf("node address: %p, data: %d\n", cur, cur->data);
		cur = cur->next;
	}
	printf("Queue Bottom\n");
}

void queFreeLl(QueueS *queue) {
	queList *cur = queue->front;
	while (cur != NULL) {
		printf("free node address: %p, data: %d\n", cur, cur->data);
		queList *aftCur = cur->next;
		delete cur;
		cur = aftCur;
	}
}

// Graph ================================================================
nodeG**  setInitNode(const int _size) {
	nodeG** initNode = (nodeG **)malloc(sizeof(nodeG *) * (_size)); // index start from 1
	for (int i = 0; i < _size; i++) {
		initNode[i] = (nodeG *)malloc(sizeof(nodeG));
		initNode[i]->next = NULL;
	}
	return initNode;
}

void insG(nodeG *root, const int _index, const int _weight) {
	nodeG *newNode = (nodeG *)malloc(sizeof(nodeG));
	newNode->index = _index;
	newNode->weight = _weight;
	newNode->next = root->next;
	root->next = newNode;
}

void showAllG(nodeG *root) {
	nodeG *cur = root->next;
	while (cur != NULL) {
		printf("%d(weight: %d) ", cur->index, cur->weight);
		cur = cur->next;
	}
}

void freeAllG(nodeG **root, const int _size) {
	for (int i = 0; i < _size; i++) {
		nodeG *cur = root[i]->next;
		while (cur != NULL) {
			printf("%d(weight: %d)", cur->index, cur->weight);
			nodeG *aftCur;
			aftCur = cur->next;
			delete cur;
			cur = aftCur;
		}
	}
}

int biSearch::search(int startIdx, int endIdx, int target) {
	if (startIdx > endIdx) {
		return -1;
	}
	int midIdx = (startIdx + endIdx) / 2;
	if (arr[midIdx] == target) {
		return midIdx;
	}
	else if (arr[midIdx] > target) {
		return search(startIdx, midIdx - 1, target);
	}
	else {
		return search(midIdx + 1, endIdx, target);
	}
}

// Priority Queue using array
pQueArr::pQueArr(const int _type) {
	type = _type;
	count = 0;
}
pQueArr::~pQueArr() {}

void pQueArr::swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void pQueArr::show() {
	printf("\nelements of arr:\n");
	for (int i = 0; i < count; i++) {
		if (i == count - 1) {
			printf("%d", heap[i]);
		}
		else {
			printf("%d, ", heap[i]);
		}
	}
	printf("\n");
}

void pQueArr::push(const int data) {
	if (count >= SIZE_HEAP) {
		printf("It's over the size");
		return;
	}
	else {
		int curIdx = count;
		int parIdx = (curIdx - 1) / 2;
		heap[curIdx] = data;


		bool compVer = type ? heap[curIdx] > heap[parIdx] : heap[curIdx] < heap[parIdx];
		while (curIdx > 0 && compVer) {
			swap(heap[curIdx], heap[parIdx]);
			curIdx = parIdx;
			parIdx = (curIdx - 1) / 2;
			printf("curIdx: %d", curIdx);
			compVer = type ? heap[curIdx] > heap[parIdx] : heap[curIdx] < heap[parIdx];
		}

		//switch(type) {
		//	case UP:	while (curIdx > 0 && (heap[curIdx] > heap[parIdx])) {
		//					swap(heap[curIdx], heap[parIdx]);
		//					curIdx = parIdx;
		//					parIdx = (parIdx - 1) / 2;
		//				} 
		//				break;
		//
		//	case DW:	while (curIdx > 0 && (heap[curIdx] < heap[parIdx])) {
		//					swap(heap[curIdx], heap[parIdx]);
		//					curIdx = parIdx;
		//					parIdx = (parIdx - 1) / 2;
		//				} break;
		//
		//	default: break;
		//}
		printf("push data: %d\n", data);
		count++;
	}
}

void pQueArr::heapify(const int curIdx) {
	int childLIdx = curIdx * 2 + 1; // child index setting using cur index
	int childRIdx = curIdx * 2 + 2;
	int tarIdx = childLIdx;
	int lastIdx = count - 1;
	if (tarIdx >= lastIdx - 1) { // target limit range setting
		return;
	}
	else {}

	// DW: change with smaller, UP: change with larger
	bool compHor = type ? heap[childLIdx] < heap[childRIdx] : heap[childLIdx] > heap[childRIdx];
	bool childREmpty = tarIdx < count;

	// target setting --> compare child node && right child is present --> set finish condition
	if (childREmpty && compHor) {
		tarIdx = childRIdx;
	}
	else {}
	bool compVer = type ? heap[curIdx] < heap[tarIdx] : heap[curIdx] > heap[tarIdx];
	if (compVer) {
		swap(heap[curIdx], heap[tarIdx]);
	}
	else { return; }
	if (tarIdx <= count / 2) {
		heapify(tarIdx);
	}
	else {}

# if 0
	if (type) {
		if ((tarIdx < count) && (heap[childLIdx] < heap[childRIdx])) {
			tarIdx = childRIdx;
		}
		else {}
		if (heap[curIdx] < heap[tarIdx]) {
			swap(heap[curIdx], heap[tarIdx]);
		}
		else { return; }
		if (tarIdx <= count / 2) {
			heapify(tarIdx);
		}
		else {}
	}
	else {
		if ((tarIdx < count) && (heap[childLIdx] > heap[childRIdx])) {
			tarIdx = childRIdx;
		}
		else {}
		if (heap[curIdx] > heap[tarIdx]) {
			swap(heap[curIdx], heap[tarIdx]);
		}
		else { return; }
		if (tarIdx <= count / 2) {
			heapify(tarIdx);
		}
		else {}
	}
#endif
}

int pQueArr::pop() {
	if (count <= 0) {
		return -1;
	}
	else {
		int popData = heap[0];
		int begin = 0;
		int end = count - 1;
		heap[begin] = heap[end]; // index: cur - 1 
		heap[end] = NULL;

		if (count > 1) {
			heapify(begin);
		}
		else {}

		printf("pop data: %d\n", popData);
		count--;
		return popData;
	}
}
