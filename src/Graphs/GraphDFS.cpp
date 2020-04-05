//Rathinavel Sankaralingam
//April 02, 2020

// String to Integer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<vector<int>> adj;

void addEdgeDFS(int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void DFSUtil(int u, vector<bool> &visited, vector<vector<int>> &adj)
{
  visited[u] = true;
  cout << u << "\t";

  for (int i = 0; i < adj[u].size(); i++)
  {
    if(visited[adj[u][i]] == false)
      DFSUtil(adj[u][i],visited,adj);
  }
}

// DFS
void DFS(int V)
{
  vector<bool> visited(V,false);

  for (int u = 0; u < V; u++)
  {
      if(!visited[u])
        DFSUtil(u,visited,adj);
  }
}

void runGraphDFS()
{
  int V = 5;
  adj.resize(5);

  addEdgeDFS(0, 1);
  addEdgeDFS(0, 4);
  addEdgeDFS(1, 2);
  addEdgeDFS(1, 3);
  addEdgeDFS(1, 4);
  addEdgeDFS(2, 3);
  addEdgeDFS(3, 4);
  DFS(V);
  
}