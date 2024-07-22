#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph
{
private:
    list<int>* Adjacency_List;
    int vertices;
    int* visited;
public:

    Graph(int x = 0)
    {
        vertices = x;
        Adjacency_List = new list<int>[vertices];
        visited = new int[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = 0;
    }
    void AddGuest()
    {
        int in = 0;
        for (int i = 0; i < vertices; i++)
        {
            cout << "Guest No " << i+1 << "  " << endl;
            for (int j = 0; j < vertices - 1; j++)
            {
                cin >> in;
                Adjacency_List[i].push_back(in);
            }
        }
    }
    void PrintAdjList()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << "Guest" << i + 1 << " -> ";
            for (int x : Adjacency_List[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    int CheckConsistency()
    {
        list<int>::iterator M1;
        list<int>::iterator M2;
        for (int i = 0; i < vertices; i++)
        {
            M1 = Adjacency_List[i].begin();
            M2 = Adjacency_List[*M1 - 1].begin();
            for (int j = 0; j < vertices - 1; j++)
            {
                if (i+1 != *M2)
                {
                    return -1;
                }
                else if (M1 != Adjacency_List[i].end())
                {
                    int k = 0;
                    M1++;
                    M2 = Adjacency_List[*M1 - 1].begin();
                    while (k <= j)
                    {
                        M2++;
                        k++;
                    }
                }
            }
        }
        return 0;
    }
    void HandShakes()
    {
        int time = 0;
        int* Parents = new int[vertices];
        int* Distance = new int[vertices];
        for (int i = 0; i < vertices; i++)
        {
            BFS(i, Parents, Distance);
            for (int i = 0; i < vertices; i++)
            {
                time = time + Distance[i];
            }
        }
        cout << "Time Taken in the HandShakes : " << time << endl << endl;
    }
    void BFS(int start, int*& Parents, int*& Distance)
    {
        int* visited = new int[vertices];
       
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = 0;
            Parents[i] = -1;
            Distance[i] =0;      // Some Max Integer

        }

        int u = 0, v = 0;
        list<int>::iterator iter;

        queue <int> TempQ;
        visited[start] = 1;
        TempQ.push(start);
        //Distance[start]=0;
        while (!TempQ.empty())
        {
            u = TempQ.front();
            TempQ.pop();
            for (iter = Adjacency_List[u].begin(); iter != Adjacency_List[u].end(); iter++)
            {
                v = *iter;
                if (visited[v] == 0)
                {
                    visited[v] = 1;
                    TempQ.push(v);
                    Parents[v] = u;
                    Distance[v] = Distance[u] + 1;
                }
            }
        }
    }

};
int main()
{
    int Guests = 0;
    cout << "Enter Total Number of Guests : ";
    cin >> Guests;

    Graph G(Guests);

    cout << "Enter Adjacency list for Each Guest : " << endl;

    G.AddGuest();
    system("cls");
    G.PrintAdjList();
    cout << endl << endl;
    G.HandShakes();
    return 0;
}