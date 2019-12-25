#include <iostream>
#include <vector>
#include <list>
using namespace std;

void addEdge(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void printGraph(vector<int> adj[], int V)
{
    for(int i = 1; i < V; i ++)
    {
        cout << i << ": ";
        for(int j = 0; j < adj[i].size(); j ++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
void breadthFirstTraversal(vector<int> adj[], int V, int start)
{
    list<int> que;
    que.push_back(start);
    bool *visited = new bool[V];
    for(int i = 1; i < V; i ++)
    {
        visited[i] = false;
    }
    while(!que.empty())
    {
        int j = que.front();
        if(visited[j] == false)
        {
            visited[j] = true;
            cout << j << " ";
            for(int i = 0; i < adj[j].size(); i ++)
            {
                int value = adj[j][i];
                que.push_back(value);
            }
        }
        que.pop_front();
    }
    delete[] visited;
}
void depthFirstUtil(vector<int> adj[], bool visited[], int n)
{
    if(visited[n] == false)
    {
        visited[n] = true;
        cout << n << " ";
        for(int i = 0; i < adj[n].size(); i ++)
        {
            depthFirstUtil(adj, visited, adj[n][i]);
        }
    }
}
void depthFirstTraversal(vector<int> adj[], int V, int n)
{
    bool visited[V];
    for(int i = 0; i < V; i ++)
    {
        visited[i] = false;
    }
    depthFirstUtil(adj, visited, n);
}
int main()
{
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    //printGraph(adj, V);
    //breadthFirstTraversal(adj, V, 3);
    depthFirstTraversal(adj, V, 1);
    return 0;
}
