#ifndef _SEARCH
#define _SEARCH

#include "../myInclude.h"
#include "../linked_list/linked_list.h"
#include "../graph/graph.h"
class Node;
class Graph;

// Depth First Search
class DFS : public Graph {
public:
	DFS(const int _size);
	~DFS();

	void search(const int startIdx);
	void searchRecur(const int tarIdx);
};

// Breadth First Search
class BFS : public Graph {
public:
	BFS(const int &_size);
	~BFS();

	void search(const int startIdx);
};

// Hash search
enum{LINEAR, CHAIN};

class Hash {
public:
	int size;

	Node **table;

	Hash(const int _size);
	~Hash();

	int function(const int _data, const int _type);
	void ins(const int _data, const int _type);
	int search(const int _data, const int _type);
	
	void show();
	void deleteAll();

};



#endif