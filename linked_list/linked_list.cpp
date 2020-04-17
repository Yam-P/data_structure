#include "linked_list.h"

// CLASS===========================================================
// Node
Node::Node(){
	weight = 0;
	height = 0;
} 

// Linked List Single Node
List::List() {}
List::~List() {}

void List::show(Node *obsNode) {
	while (obsNode != nullptr) {
		printf("node address: %p, data: %d\n", obsNode, obsNode->data);
		obsNode = obsNode->next;
	}
}

// Linked List Single Node
ListS::ListS(int _headData) : List() {
	head = new Node;
	head->next = nullptr;
	head->data = _headData;
	printf("head address: %p, data: %d\n", head, head->data);
}

ListS::~ListS() {
	deleteAll(head);
}

void List::deleteAll(Node *root) {
	while (root != nullptr) {
		Node *aftRoot = root->next;
		printf("free node address: %p, data: %d\n", root, root->data);
		delete root;
		root = aftRoot;
	}
}

void ListS::insBegin(int _data) {
	Node *newNode = new Node;
	newNode->data = _data;

	newNode->next = head->next;
	head->next = newNode;

	printf("newNode address: %p, data: %d\n", newNode, newNode->data);
}

// Linked List Single Node
void ListS::delBegin() {
	Node *delNode	= head->next;
	head->next		= delNode->next;
	printf("del node address: %p, data: %d\n", delNode, delNode->data);
	delete delNode;
}

// Linked List Double Node
ListD::ListD(const int _headData, const int _tailData) : List() {
	head = new Node;
	tail = new Node;
	
	head->next = tail;
	head->prev = head;
	head->data = _headData;

	tail->prev = head;
	tail->next = nullptr;
	tail->data = _tailData;
	printf("head address: %p, data: %d\n", head, head->data);
	printf("tail address: %p, data: %d\n", tail, tail->data);
}

ListD::~ListD() {
	deleteAll(head);
	printf("free all node\n");
}

void ListD::insBegin(const int _data) {
	Node *newNode = new Node;
	newNode->data = _data;

	printf("newNode address: %p, data: %d\n", newNode, newNode->data);

	Node *headNext = head->next; // insert newNode between cur and befCur
	//Node *befCur = cur->prev;

	while (headNext->data < _data && headNext != tail) {
		headNext = headNext->next;
	}

	headNext->prev->next = newNode; // (headNext->prev) is same as head
	newNode->prev = headNext->prev;

	headNext->prev = newNode;
	newNode->next = headNext;
}

void ListD::delBegin() {
	Node *delNode = head->next;
	delNode->next->prev = head;
	delNode->prev->next = delNode->next;

	printf("del node address: %p, data: %d\n", delNode, delNode->data);
	delete delNode;
	delNode = nullptr;
}

void ListD::del(const int _data) {
	Node *delNode = head->next;
	bool findFlag = false;
	while (delNode != tail) {
		if (delNode->data == _data) {
			delNode->next->prev = head;
			delNode->prev->next = delNode->next;

			printf("del node address: %p, data: %d\n", delNode, delNode->data);
			delete delNode; 
			delNode = nullptr;
			
			break;
		} else {
			delNode = delNode->next;
		}		
	}
	if (!findFlag) {
		printf("%d was not founded before tail!\n", _data);
	} else {}
}

// Stack Class
ListSt::ListSt() : Stack(), List(){
	printf("Stack Start============\n");
	stack = new Stack;
	printf("address of stack: %p\n", stack);
	stack->top = nullptr;
};

ListSt::~ListSt() {
	deleteAll(stack->top);
	printf("free stack address: %p\n", stack);
	delete stack;
	printf("Stack End============\n");
}

void ListSt::push(int data) {
	Node *newNode = new Node;
	newNode->data = data;

	//printf("new node address: %p, data: %d\n", newNode, newNode->data);

	newNode->next = stack->top;
	stack->top = newNode;
}

int ListSt::pop() {
	if (stack->top == nullptr) {
		printf("Stack Underflow\n");
		return INT_MIN;
	} else {
		Node *delNode = stack->top;
		int popData = delNode->data;
		stack->top = delNode->next;

		//printf("del node address: %p, data: %d\n", delNode, data);
		delete delNode;
		delNode = nullptr;
		return popData;
	}
}

void ListSt::show(Node *obsNode) {
	printf("Stack Top\n");
	List::show(obsNode);
	printf("Stack Bottom\n");
}

// Queue Class
ListQue::ListQue() : Queue(), List() {
	printf("Queue Start============\n");
	queue = new Queue;
	printf("address of queue: %p\n", queue);
	queue->count = 0;
	queue->begin = nullptr;
	queue->end = nullptr;
}

ListQue::~ListQue() {
	deleteAll(queue->begin);

	printf("free address of queue: %p\n", queue);
	delete queue;
	printf("Queue End============\n");
}

void ListQue::push(int data) {
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	//printf("newNode address: %p, data: %d\n", newNode, newNode->data);

	if (!(queue->count)) {
		queue->begin = newNode;
	} else {
		queue->end->next = newNode;
	}

	queue->end = newNode;
	queue->count++;
}

int ListQue::pop() {
	Node *delNode = queue->begin;
	int data;

	//printf("delNode address: %p, data: %d\n", delNode, delNode->data);

	if (!(queue->count)) {
		printf("Queue Underflow\n");
		return INT_MIN;
	} else {
		queue->begin = delNode->next;
		data = delNode->data;
		delete delNode;
		delNode = nullptr;
		queue->count--;
	}
	return data;
}

void ListQue::show(Node *obsNode) {
	printf("Queue Top\n");
	List::show(obsNode);
	printf("Queue Bottom\n");
}