#include "search.h"

// Depth First Search
DFS::DFS(const int _size) : Graph(_size) {}
DFS::~DFS() {}

//dfsEx.searchRecur(0); // wrong algorithm
void DFS::searchRecur(const int tarIdx) {
	if (visit[tarIdx]) {
		return;
	}
	else {
		printf("%d ", tarIdx);
		visit[tarIdx] = true;

		Node *cur = graph[tarIdx]->next; // connected node with graph[tar]
		while (cur != nullptr) {
			int next = cur->index;
			searchRecur(next);
			cur = cur->next;
		}
	}
}

void DFS::search(const int startIdx) {
	ListSt stList;
	stList.push(startIdx);

	visit[startIdx] = true;

	while (stList.stack->top != nullptr) {
		int popData = stList.pop();
		printf("%d ", popData);
		Node *cur = graph[popData]->next;	// 해당 graph node 접근
		while (cur != nullptr) {
			int nextIdx = cur->index;			// 간선 탐색
			if (!visit[nextIdx]) {
				stList.push(nextIdx);
				visit[nextIdx] = true;
			}
			cur = cur->next;
		}
	}
	printf("\n");
}

// Breadth First Search
BFS::BFS(const int &_size) : Graph(_size) {}

BFS::~BFS() {}

void BFS::search(const int startIdx) {
	ListQue queList;
	queList.push(startIdx);

	visit[startIdx] = true;

	while (queList.queue->count > 0) {
		int popData = queList.pop();
		printf("%d ", popData);
		Node *cur = graph[popData]->next;	// 해당 graph node 접근
		while (cur != nullptr) {
			int nextIdx = cur->index;			// 간선 탐색
			if (!visit[nextIdx]) {
				queList.push(nextIdx);
				visit[nextIdx] = true;
			}
			cur = cur->next;
		}
	}
}

// Hash Search
Hash::Hash(const int _size) {
	size = _size;
	table = new Node *[size];
	for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
	printf("Hash table set\n");
}

Hash::~Hash() {
	deleteAll();
	delete[] table;
	printf("Hash table delete\n");
}

int Hash::function(const int _data, const int _type) {
	int idx = _data % size;
	switch(_type) {
		case LINEAR:	while (idx < size) {
							if (table[idx] != nullptr) {
								printf("This space[%d] is not empty\n", idx);
								idx++;
							} else {
								return idx;
							}
						}
						break;
		
		case CHAIN:		return idx;
						break;
		default:		break;
	}
	
}

void Hash::ins(const int _data, int _type) {
	int key;

	switch (_type) {
	case LINEAR:	key= function(_data, LINEAR);
					table[key] = new Node; 
					table[key]->data = _data;
					table[key]->next = nullptr;
					break;

	case CHAIN:		key = function(_data, CHAIN); 
					if (table[key] == nullptr) {
						table[key] = new Node;
						table[key]->data = _data;
						table[key]->next = nullptr;
						printf("%d idx setting address: %p, data: %d\n", key, table[key], table[key]->data);
					} else {
						Node *newNode = new Node;
						newNode->data = _data;
						newNode->next = table[key]->next;
						table[key]->next = newNode;
						printf("newNode address: %p, data: %d\n", newNode->next, newNode->data);
					}
				break;
	default:	break;
	}
}

int Hash::search(const int _data, const int _type) {
	int idx = _data % size;
	if (table[idx] == nullptr) {
		printf("empty space\n");
		return -1;
	} else {
		switch(_type) {
			case LINEAR:	for (;idx < size; idx++){
								if (table[idx]->data == _data) {
									return idx;
								} else {}
							}

			case CHAIN:		Node *obsNode = table[idx];
							while (obsNode != nullptr) {
								if (obsNode->data == _data) {
									return idx;
								}
								else {
									obsNode = obsNode->next;
								}
							}
							break;
		}
	}
}

void Hash::deleteAll() {
	for (int i = 0; i < size; i++) {
		Node *cur = table[i];
		while (cur != nullptr) {
			Node *aftCur = cur->next;
			printf("del table[%d] address:   %p\n", i, cur);
			delete cur;
			cur = aftCur;
		}
	}
}

void Hash::show() {
	for (int i = 0; i < size; i++) {
		Node *obsNode = table[i];
		while (obsNode != nullptr) {
			printf("%d idx address: %p, data: %d\n", i, obsNode, obsNode->data);
			obsNode = obsNode->next;
		}
	}
}
