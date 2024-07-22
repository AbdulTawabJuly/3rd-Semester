//#include <iostream>
//#include <queue>
//#include <list>
//using namespace std;
//
//class Graph {
//private:
//	int vertices;
//	list<int>* Adjacency_List;
//
//public:
//	Graph(int v) {
//		vertices = v;
//		Adjacency_List = new list<int>[vertices];
//	}
//
//	void TakeInput(int n, int w) {
//		Adjacency_List[n].push_back(w);
//	}
//
//	void BFS(int start, int*& parent, int*& distance) {
//		int* Visited = new int[vertices];
//
//		for (int i = 0; i < vertices; i++) {
//			Visited[i] = 0;
//			parent[i] = -1;
//			distance[i] = INT_MAX;
//		}
//
//		int u = 0;  int v = 0;
//		list<int>::iterator i;
//		queue<int> Q;
//		Visited[start] = 1;
//		Q.push(start);
//		distance[start] = 0;
//
//		while (!Q.empty()) {
//			u = Q.front();
//			Q.pop();
//
//			for (i = Adjacency_List[start].begin(); i != Adjacency_List[start].end(); ++i) {
//				v = *i;
//				if (Visited[v] == 0)
//				{
//					Visited[v] = 1;
//					Q.push(v);
//					distance[v] = distance[u] + 1;
//				}
//			}
//		}
//	}
//};
//
//int main()
//{
//	Graph G1(9);
//	G1.TakeInput(1, 2);
//	G1.TakeInput(1, 3);
//	G1.TakeInput(1, 4);
//	G1.TakeInput(2, 1);
//	G1.TakeInput(2, 3);
//	G1.TakeInput(2, 4);
//	G1.TakeInput(3, 4);
//	G1.TakeInput(3, 1);
//	G1.TakeInput(3, 2);
//	G1.TakeInput(4, 3);
//	G1.TakeInput(4, 1);
//	G1.TakeInput(4, 2);
//
//	int* parent = new int[9];
//	int* distance = new int[9];
//	G1.BFS(2, parent, distance);
//
//	int time = 0;
//	for (int i = 0; i < 9; i++) {
//		time = time + distance[i];
//	}
//	cout << "Time Taken in Handshaking: " << time << endl;
//	return 0;
//}