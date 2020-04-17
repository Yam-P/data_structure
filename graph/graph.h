#ifndef _GRAPH
#define _GRAPH

#include "../myInclude.h"
#include "../linked_list/linked_list.h"
#include "../tree/tree.h"

// Graph Class
class Graph : public Node {
private:
	int size;

public:
	Node **graph;
	bool *visit;

	Graph(int _size);
	~Graph();
	int getSize();
	void addEdgeS(const int _rootIdx, const int _tarIdx, const int _weight);
	void addEdgeD(const int _rootIdx, const int _tarIdx, const int _weight);
	void show();
};

class Prim {
private:
	int weightSum;
	Node *startNode;

public:
	Graph *graph;

	Prim(Graph *_graph);
	~Prim();

	int run();
	int getWeightSum();
	
};

class Dijkstra {
private:
	Node *startNode;
	int *dist;
public:
	Graph *graph;

	Dijkstra(Graph *_graph);
	~Dijkstra();

	int run();
};


#endif