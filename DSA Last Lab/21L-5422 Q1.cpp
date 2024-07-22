//#include<iostream>
//#include<list>
//#include<queue>
//#include<stack>
//
//using namespace std;
//
//class Graph
//{
//private:
//    list<int>* Adjacency_List;
//    int vertices;
//public:
//
//    Graph(int x=0)
//    {
//        vertices = x;
//        Adjacency_List = new list<int>[vertices];
//    }
//
//    void TakeInput(int n,int w)
//    {
//        Adjacency_List[n].push_back(w);
//    }
//
//    void ExploreFunction(int start, int*& temp, int*& visited)
//    {
//        int j = 0;
//        while (temp[j] != -1)
//        {
//            cout << temp[j] << " ";
//            j++;
//        }
//        cout << endl;
//        visited[start] = 1;
//        int i = 0;
//        while (i < vertices)
//        {
//            if (temp[i] == -1)
//            {
//                temp[i] = start;
//                break;
//            }
//            else
//            {
//                i++;
//            }
//        }
//        list<int>::iterator it;
//        int nbr;
//        for (it = Adjacency_List[start].begin(); it != Adjacency_List[start].end(); it++)
//        {
//            nbr = *it;
//            if (visited[nbr] == 0)
//            {
//                ExploreFunction(nbr, temp, visited);
//            }
//        }
//    }
//    void ExploreFunction(int S)
//    {
//        int* temp = new int[vertices];
//        for (int i = 0; i < vertices; i++)
//            temp[i] = -1;
//
//        int* visited = new int[vertices];
//        for (int i = 0; i < vertices; i++)
//            visited[i] = 0;
//
//        ExploreFunction(S, temp, visited);
//        for (int i = 0; i < vertices; i++)
//            cout << temp[i] << " ";
//        cout << endl;
//
//        delete[]visited;
//    }
//
//    void PrintAdjList()
//    {
//        for (int i = 0; i < vertices; i++)
//        {
//            cout << "vertex " << i+1 << " -> ";
//            for (int x : Adjacency_List[i])
//            {
//                cout << x << ", ";
//            }
//            cout << endl;
//        }
//    }
//
//    void ExplorePath(int start)
//    {
//        int* visited = new int[vertices];
//        int* Parents = new int[vertices];
//        int* Distance = new int[vertices];
//        for (int i = 0; i < vertices; i++)
//        {
//            visited[i] = 0;
//            Parents[i] = -1;
//            Distance[i] = 999;      // Some Max Integer
//
//        }
//
//        int u = 0, v = 0;
//        list<int>::iterator iter;
//
//        queue <int> TempQ;
//        visited[start] = 1;
//        TempQ.push(start);
//        Distance[start] = 0;
//        while (!TempQ.empty())
//        {
//            u = TempQ.front();
//            cout << " -> " << u;
//            TempQ.pop();
//            for (iter = Adjacency_List[u].begin(); iter != Adjacency_List[u].end(); iter++)
//            {
//                v = *iter;
//                if (visited[v] == 0)
//                {
//                    visited[v] = 1;
//                    TempQ.push(v);
//                    Parents[v] = u;
//                    Distance[v] = Distance[u] + 1;
//                }
//            }
//        }
//    }
//
//    ~Graph()
//    {
//        delete[]Adjacency_List;
//    }
//};
//int main()
//{
//    Graph G(4);
//
//    G.TakeInput(0, 1);
//    G.TakeInput(0, 2);
//    G.TakeInput(1, 2);
//    G.TakeInput(2, 0);
//    G.TakeInput(2, 3);
//    G.TakeInput(3, 3);
//
//    cout << "Following is Depth First Traversal for vertice 2 " ;
//    G.ExploreFunction(2);
//    cout << endl;
//
//    cout << "Following is Depth First Traversal for vertice 1 ";
//    G.ExploreFunction(1);
//
//    return 0;
//}