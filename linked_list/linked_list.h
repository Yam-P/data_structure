#ifndef _LIST_H
#define _LIST_H
#include "../myInclude.h"

// Node Class
class Node {
public:
	int		data;
	int		index;
	int		vertex;
	int		weight;
	int		height;

	Node	*next;
	Node	*prev;
	Node	*childL;
	Node	*childR;

	Node();
};

// Linked List Class
class List {
public:
	Node *head;
	Node *tail;

	List();
	~List();

	void show(Node *obsNode);
	void deleteAll(Node *root);
};

// Linked List Single Node
class ListS : public List {
public:
	ListS(int _headData);
	~ListS();
	void insBegin(int data);
	void delBegin();
	
};

// Linked List Double Node
class ListD : public List {
public:
	ListD(const int _headData, const int _tailData);
	~ListD();
	void insBegin(const int _data);
	void delBegin();
	void del(const int _data);
};

// Stack Class
class Stack {
public:
	Node *top;
};

class ListSt : public Stack, public List {
public:
	Stack *stack;

	ListSt();
	~ListSt();

	void push(int data);
	int pop();
	void show(Node *obsNode);
};

// Queue Class
class Queue {
public:
	int count;
	Node *begin;
	Node *end;
};

class ListQue : public Queue, public List {
public:
	Queue *queue;

	ListQue();
	~ListQue();
	void push(int data);
	int pop();
	void show(Node *obsNode);
};

#endif