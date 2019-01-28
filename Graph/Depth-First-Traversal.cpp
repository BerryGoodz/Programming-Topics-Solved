#include <iostream>
#include <list>
using namespace std;

class Graph
{
public:
    Graph(int V)
    {
        this -> V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int a)
    {
        adj[v].push_back(a); // this is a directed graph
    }
    void DFSUtil(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); i ++)
        {
            if(visited[*i] == false)
            {
                DFSUtil(*i, visited);
            }
        }
    }
    void DFS(int v)
    {
        bool *visited = new bool[V];
        for(int i = 0; i < V; i ++)
            visited[i] = false;
        DFSUtil(v, visited);
    }
private:
    int V;
    list<int> *adj;

};
int main()
{
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 2);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.DFS(0);// 0, 1, 4, 2, 3
    return 0;
}
