//Rathinavel Sankaralingam
//April 02, 2020

// String to Integer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<pair<int,int>>> adj;

void addEdgeDFSWeighted(int u, int v, int weight)
{
  adj[u].push_back(make_pair(v,weight));
}

void weightedDFSUtil(int u, vector<bool> &visited, vector<vector<pair<int, int>>> &adj)
{
  visited[u] = true;
  cout << u << "\t";

  for (int i = 0; i < adj[u].size(); i++)
  {
    if(visited[adj[u][i].first] == false)
      weightedDFSUtil(adj[u][i].first,visited,adj);
  }
}

// DFS
void weightedDFS(int V)
{
  vector<bool> visited(V,false);

  for (int u = 0; u < V; u++)
  {
      if(!visited[u])
        weightedDFSUtil(u,visited,adj);
  }
}

void runGraphWeightedDFS()
{
  int V = 4;
  adj.resize(V);

  addEdgeDFSWeighted(0,1,10);
  addEdgeDFSWeighted(0,3,2);
  addEdgeDFSWeighted(0,2,3);
  addEdgeDFSWeighted(1,3,7);
  addEdgeDFSWeighted(2,3,6);
  
  weightedDFS(V);
}