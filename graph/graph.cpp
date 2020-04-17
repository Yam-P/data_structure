#include "graph.h"

// Graph Class
Graph::Graph(const int _size) : Node() {
	size = _size;
	graph = new Node *[size];
	visit = new bool[size];

	for (int i = 0; i < size; i++) {
		graph[i] = new Node;
		graph[i]->index = i;
		graph[i]->next = nullptr;
		printf("set graph[%d] node adress: %p\n", i, graph[i]);

		visit[i] = false;
	}
	printf("set graph address set: %p\n", graph);
	printf("set bool array address set: %p\n", visit);
}

Graph::~Graph() {
	printf("Graph ¼Ò¸êÀÚ\n");
	for (int i = 0; i < size; i++) {
		Node *cur = graph[i];
		while (cur != NULL) {
			printf("free graph[%d] node adress: %p\n", i, cur);
			Node *aftCur = cur->next;
			delete cur;
			cur = aftCur;
		}
	}
	printf("free Graph address: %p\n", graph);
	printf("free bool array address: %p\n", visit);
	delete[] visit;
	delete[] graph;

}

void Graph::addEdgeS(const int _rootIdx, const int _tarIdx, const int _weight) {
	Node *newNode = new Node;
	newNode->index = _tarIdx;
	newNode->weight = _weight;
	newNode->next = graph[_rootIdx]->next;
	graph[_rootIdx]->next = newNode;
	printf("added node adress: %p\n", newNode);
}

void Graph::addEdgeD(const int _rootIdx, const int _tarIdx, const int _weight) {
	Node *newNode1 = new Node;
	newNode1->index = _tarIdx;
	newNode1->weight = _weight;

	Node *newNode2 = new Node;
	newNode2->index = _rootIdx;
	newNode2->weight = _weight;

	newNode1->next = graph[_rootIdx]->next;
	graph[_rootIdx]->next = newNode1;
	printf("added node1 adress: %p\n", newNode1);
	newNode2->next = graph[_tarIdx]->next;
	graph[_tarIdx]->next = newNode2;
	printf("added node2 adress: %p\n", newNode2);
}

int Graph::getSize() {
	return size;
}

void Graph::show() {
	for (int i = 0; i < size; i++) {
		Node *cur = graph[i]->next;
		printf("¿ø¼Ò [%d]: ", i);
		while (cur != nullptr) {
			printf("%d(weight: %d), ", cur->index, cur->weight);
			cur = cur->next;
		}
		printf("\n");
	}
	printf("\n");
}

// Prim Algorithm
Prim::Prim(Graph *_graph) {
	weightSum = 0;

	startNode = new Node;
	startNode->index = 0;
	startNode->weight = 0;

	graph = _graph;
}

Prim::~Prim() {
	delete startNode;
}

int Prim::run() {
	pQue heap(30);
	heap.push(startNode);
	for (int i = 0; i < graph->getSize(); i++) {
		int nextIdx = -1, nextWeight = INT_MAX;

		while (true) {
			Node *popNode = heap.pop(); // pop data is the node which has minimum weight
			printf("popNode->index: %d, popNode->weight: %d\n", popNode->index, popNode->weight);
			if (popNode == nullptr) {
				break;
			}
			else {
				nextIdx = popNode->index;
				if (!graph->visit[nextIdx]) {
					nextWeight = popNode->weight;
					printf("nextIdx/Weight: %d/%d\n", nextIdx, nextWeight);
					break;
				}
				else {}
			}
		}

		if (nextWeight == INT_MAX) {
			printf("It is not linked graph\n");
		}
		else {
			printf("visit[%d] pass\n", nextIdx);
			graph->visit[nextIdx] = true;

			Node *curNode = graph->graph[nextIdx]->next;
			while (curNode != nullptr) {
				heap.push(curNode);
				curNode = curNode->next;
			}
			heap.show();

			weightSum += nextWeight;
		}
	}

	graph = nullptr; // it points at graph outside of Prim
	return 0;
}

int Prim::getWeightSum() {
	return weightSum;
}

// Dijkstra Algorithm
Dijkstra::Dijkstra(Graph *_graph) {
	startNode = new Node;
	startNode->index = 0;
	startNode->weight = 0;

	graph = _graph;

	dist = new int[graph->getSize()];
	for (int i = 0; i < graph->getSize(); i++) {
		if (!i) {
			dist[i] = 0;
		}
		else {
			dist[i] = INT_MAX;
		}
	}
}
Dijkstra::~Dijkstra() {
	delete startNode;
	delete[] dist;
}

int Dijkstra::run() {
	pQue heap(30);
	heap.push(startNode);

	while (true) {
		Node *popNode = heap.pop();

		if (popNode == nullptr) {
			break;
		}
		else {
			printf("popNode->index: %d, popNode->weight: %d\n", popNode->index, popNode->weight);
			if (dist[popNode->index] >= popNode->weight) {
				Node *curNode = graph->graph[popNode->index]->next;
				while (curNode != nullptr) {
					curNode->weight += popNode->weight;
					if (curNode->weight < dist[curNode->index]) {
						dist[curNode->index] = curNode->weight;
						heap.push(curNode);
						heap.show();
					}
					else {}
					curNode = curNode->next;
				}
			}
			else {}
		}
	}

	for (int i = 0; i < 5; i++) {
		if (dist[i] == INT_MAX) printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	graph = nullptr;

	return 0;
}
