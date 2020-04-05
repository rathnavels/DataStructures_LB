//Rathinavel Sankaralingam
//April 2, 2020


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static vector<vector<int>> adj;

static void addEdgeBFS(int u, int v)
{
  adj[u].push_back(v);
}

void BFS(int V)
{
  vector<bool> visited(V,false);
  queue<int> Q;

  Q.push(2);

  while (!Q.empty())
  {
    int k = Q.front();
    Q.pop();

    if(visited[k]==false)
      cout << k << "\t";

    visited[k] = true;

    for (int i = 0; i < adj[k].size(); i++)
    {
        if(visited[adj[k][i]]==false)
          Q.push(adj[k][i]);
    }
  }
}

void runGraphBFS()
{
  int V = 5;
  adj.resize(5);

  addEdgeBFS(0, 1);
  addEdgeBFS(0, 2);
  addEdgeBFS(1, 2);
  addEdgeBFS(2, 0);
  addEdgeBFS(2, 3);
  addEdgeBFS(3, 3);

  BFS(V);
}