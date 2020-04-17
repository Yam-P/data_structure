#include "main_group.h"

#if 0
int main_structure() {
	main_llArr();
	main_llSingleS();
	main_llDoubleS();
	main_stArr();
	main_stList();
	main_queArr();
	main_queList();
	main_sequentialSearch();
	main_graph();


	return 0;
}
#endif

int main_stl() {
	//main_stack();
	//main_queue();
	//main_pQueue();
	//main_deque();
	//main_vector();
	//main_set();
	main_map();
	return 0;
}

int main_listS() {
	ListS listS(5);

	printf("address of head: %p\n", listS.head);
	listS.insBegin(1);
	listS.insBegin(2);
	listS.insBegin(3);
	listS.delBegin();
	cout << endl;
	listS.show(listS.head);
	
	return 0;
}

int main_listD() {
	ListD listD(1, 7);
	listD.insBegin(2);
	listD.insBegin(3);
	listD.insBegin(4);
	listD.insBegin(5);
	listD.insBegin(6);

	//listD.delBegin();
	listD.del(6);
	cout << endl;

	listD.show(listD.head);

	return 0;
}

int main_listSt() {
	ListSt stEx;

	stEx.push(1);
	stEx.push(2);
	stEx.push(3);
	stEx.push(4);
	stEx.push(5);
	stEx.show(stEx.stack->top);
	cout << endl;
	
	stEx.pop();
	stEx.pop();
	stEx.push(6);
	stEx.show(stEx.stack->top);
	cout << endl;

	return 0;
}

int main_listQue() {
	ListQue queEx;

	queEx.push(1);
	queEx.push(2);
	queEx.push(3);
	queEx.push(4);
	queEx.push(5);
	queEx.show(queEx.queue->begin);
	cout << endl;

	queEx.pop();
	queEx.pop();
	queEx.push(6);
	queEx.show(queEx.queue->begin);
	cout << endl;

	return 0;
}

int main_sort() {
	//vector<int> inputVec{5, 4, 3, 8, 9, 6, 7, 1, 10, 2};
	vector<int> inputVec{ 7, 84, 25, 341, 65, 30, 34 };
	mySort sortVec(inputVec);
	int n = inputVec.size();
	
	//sortVec.sortSelectVec(true);
	//sortVec.sortInsertVec(false);
	//sortVec.sortBubbleVec(false);
	//sortVec.sortQuickVec(0, n - 1);
	//sortVec.show();
	//sortVec.sortRankVec();
	sortVec.sortRadixVec();
	
	return 0;	
}

int main_graphC() {
	Graph graphEx(5);
	graphEx.addEdgeD(0, 1, 9);
	graphEx.addEdgeD(0, 2, 8);
	graphEx.addEdgeD(0, 4, 10);
	graphEx.addEdgeD(2, 3, 8);
	cout << endl;

	graphEx.show();
	//graphEx.freeAll();

	return 0;
};

int main_dfs() {
	DFS dfsEx(8);
	dfsEx.addEdgeS(0, 1, 8);
	dfsEx.addEdgeS(0, 2, 6);
	dfsEx.addEdgeS(2, 3, 4);
	dfsEx.addEdgeS(2, 4, 6);
	dfsEx.addEdgeS(1, 5, 10);
	dfsEx.addEdgeS(4, 6, 1);
	dfsEx.addEdgeS(6, 7, 2);
	dfsEx.addEdgeS(3, 7, 6);
	dfsEx.show();

	printf("Search Process: \n");

	dfsEx.search(0);
	printf("\n\n");
	return 0;
}

int main_bfs() {
	BFS bfsEx(8);
	bfsEx.addEdgeS(0, 1, 8);
	bfsEx.addEdgeS(0, 2, 6);
	bfsEx.addEdgeS(2, 3, 4);
	bfsEx.addEdgeS(2, 4, 6);
	bfsEx.addEdgeS(1, 5, 10);
	bfsEx.addEdgeS(4, 6, 1);
	bfsEx.addEdgeS(6, 7, 2);
	bfsEx.show();

	printf("Search Process: \n");
	bfsEx.search(0);
	cout << endl;
	return 0;
}

int main_biTree() {
	Tree treeEx(7);

	treeEx.insStudy(2);
	treeEx.insStudy(1);
	treeEx.insStudy(5);
	treeEx.insStudy(6);
	treeEx.insStudy(10);
	treeEx.insStudy(9);
	treeEx.insStudy(8);
	treeEx.insStudy(12);
	treeEx.insStudy(13);

	cout << "tree: " << endl;
	treeEx.show(treeEx.root);

	//treeEx.del(8);
	treeEx.delStudy(13);
	treeEx.delStudy(7);
	treeEx.delStudy(12);
	treeEx.delStudy(6);
	treeEx.delStudy(5);


	treeEx.show(treeEx.root);
	printf("\n");

	return 0;
}

int main_biTreeSearch() {
	TreeAVL treeEx(7);
	treeEx.ins(5);
	treeEx.ins(2);
	treeEx.ins(1);
	treeEx.ins(6);
	treeEx.ins(4);
	treeEx.ins(8);
	treeEx.ins(9);
	treeEx.show(treeEx.root);
	treeEx.ins(10);
	treeEx.ins(12);
	treeEx.ins(11);
	treeEx.ins(13);
	cout << endl;

	treeEx.show(treeEx.root);

	return 0;
}

int main_pQue() {
#if 1
	pQue pqueEx(3);
	Node *node1;
	Node *node2;
	node1 = new Node;
	printf("new Node address: %p\n", node1);
	node1->index = 1;
	node1->weight = 3;
	node2 = new Node;
	printf("new Node address: %p\n", node2);
	node2->index = 2;
	node2->weight = 4;
	
	pqueEx.push(node1);
	pqueEx.push(node2);
	pqueEx.pop();
	pqueEx.show();
	printf("free Node address: %p\n", node1);
	printf("free Node address: %p\n", node2);
	delete node1;
	delete node2;
#endif
	//node1 = nullptr;
	
	//printf("new Node address/index/weight: %p\n", *node1);

	return 0;
}

int main_prim() {
	Graph graphEx(5);
	graphEx.addEdgeD(0, 1, 3);
	graphEx.addEdgeD(0, 4, 20);
	graphEx.addEdgeD(1, 2, 6);
	graphEx.addEdgeD(1, 3, 5);
	graphEx.addEdgeD(1, 4, 15);
	graphEx.addEdgeD(2, 4, 4);
	graphEx.addEdgeD(3, 4, 7);

	Prim primEx(&graphEx);
	primEx.graph->show();
	primEx.run();

	printf("sum of shortest weight of this graph: %d\n", primEx.getWeightSum());

	return 0;
}


int main_dijkstra() {
	Graph graphEx(5);
	graphEx.addEdgeS(0, 1, 3);
	graphEx.addEdgeS(0, 4, 20);
	graphEx.addEdgeS(1, 2, 6);
	graphEx.addEdgeS(1, 3, 5);
	graphEx.addEdgeS(1, 4, 15);
	graphEx.addEdgeS(2, 4, 4);
	graphEx.addEdgeS(3, 4, 7);

	Dijkstra dijEx(&graphEx);
	dijEx.run();

	return 0;
}

int main_segTree() {
	int arr[3] = {7, 9, 8};

	segTree segTreeEx(arr, 3);	

	segTreeEx.setInit();
	segTreeEx.update(1, 10);

	segTreeEx.show();
	printf("segment sum value: %d\n", segTreeEx.segSum(1, 2));
	
	//int curIdx = 0;
	//int childLIdx = curIdx * 2 + 1;
	//int childRIdx = curIdx * 2 + 2;
	//
	//
	//tree[childLIdx] = arr[0];
	//tree[childRIdx] = arr[1];


	
	return 0;
}

#if 0

int main_hash() {
	// list를 bucket으로 넣을까? listS를 table[i]로 사용하면 될듯
	
	printf("Hash Search Algorithm\n");
	Hash hashEx(10);
	
	hashEx.ins(31, LINEAR);
	hashEx.ins(41, LINEAR);
	hashEx.ins(21, LINEAR);
	hashEx.ins(11, LINEAR);
	hashEx.ins(4,  LINEAR);
	hashEx.ins(24, LINEAR);

	hashEx.show();

	printf("index of data: %d\n", hashEx.search(11, LINEAR));

	return 0;
}

int main_voyager(){
	main_ll();

	
	return 0;
}






#endif