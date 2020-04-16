//Rathinavel Sankaralingam
//Apr 16, 2020


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> adj;

static void addEdge(int u, int v)
{
  adj[u].push_back(v);
}

void findShortestPathLength(int start, vector<bool> &visited, vector<int> &lengths, int prevLen)
{
  prevLen++;
  lengths[start] = min(lengths[start],prevLen);
  for (int i = 0; i < adj[start].size(); i++)
  {
    findShortestPathLength(adj[start][i],visited,lengths,lengths[start]);
  }
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
  int start = 4;
  int end = 5;
  vector<int> lengths(N,INT_MAX);
  int previousLength = -1;
  
  findShortestPathLength(start, visited, lengths, previousLength);

  cout << "Shortest Length is " << lengths[end];
  
}