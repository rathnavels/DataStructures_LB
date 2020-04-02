//Rathinavel Sankaralingam
//April 02, 2020

// String to Integer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<pair<int,int>>> adj;

void addEdge(int u, int v, int weight)
{
  adj[u].push_back(make_pair(v,weight));
}

void DFSUtil(int u, vector<bool> &visited, vector<vector<pair<int, int>>> &adj)
{
  visited[u] = true;
  cout << u << "\t";

  for (int i = 0; i < adj[u].size(); i++)
  {
    if(visited[adj[u][i].first] == false)
      DFSUtil(adj[u][i].first,visited,adj);
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

void runGraphWeightedDFS()
{
  int V = 4;
  adj.resize(V);

  addEdge(0,1,10);
  addEdge(0,3,2);
  addEdge(0,2,3);
  addEdge(1,3,7);
  addEdge(2,3,6);
  
  
  
  DFS(V);
  
}