//Rathinavel Sankaralingam
//April 02, 2020

// String to Integer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<vector<int>> adj;

static void addEdge(int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

static void DFSUtil(int u, vector<bool> &visited, vector<vector<int>> &adj)
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
static void DFS(int V)
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

  addEdge(0, 1);
  addEdge(0, 4);
  addEdge(1, 2);
  addEdge(1, 3);
  addEdge(1, 4);
  addEdge(2, 3);
  addEdge(3, 4);
  DFS(V);
  
}