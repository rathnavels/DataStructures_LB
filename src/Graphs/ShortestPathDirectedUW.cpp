//Rathinavel Sankaralingam
//Apr 16, 2020


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// This works for directed acyclic graph
// This doesn't work for cyclic graphs

static vector<vector<int>> adj;

static void addEdge(int u, int v)
{
  adj[u].push_back(v);
}

void findShortestPathLength(int start, int current, int end, vector<bool> &visited, vector<int> &lengths, int prevLen)
{
  prevLen++;
  lengths[current] = min(lengths[current],prevLen);
  
  for (int i = 0; i < adj[current].size(); i++)
      findShortestPathLength(start, adj[current][i], end, visited, lengths, lengths[current]);
  
}

void runShortestPathDirectedUW()
{
  int N = 7;
  adj.resize(N);

  addEdge(0,1);
  addEdge(0,3);
  addEdge(1,3);
  addEdge(1,4);
  addEdge(2,0);
  addEdge(2,5);
  addEdge(3,4);
  addEdge(3,5);
  addEdge(3,6);
  addEdge(4,6);
  addEdge(6,5);

  vector<bool> visited(N,false);
  int start = 2;
  int end = 3;
  vector<int> lengths(N,INT_MAX);
  int previousLength = -1;
  
  findShortestPathLength(start, start, end, visited, lengths, previousLength);

  for(int i=0; i<lengths.size(); i++)
  cout << lengths[i] << "\t";
  
}