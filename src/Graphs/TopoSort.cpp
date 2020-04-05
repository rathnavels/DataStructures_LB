//Rathinavel Sankaralingam
//April 2, 2020


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

static vector<vector<int>> adj;

static void addEdge(int u, int v)
{
  adj[u].push_back(v);
}

void topoSortHelper(int vertex, stack<int> &stk, vector<bool> &visited)
{
  if(visited[vertex]==true)
    return;
  else
    visited[vertex] = true;

  for (int i = 0; i < adj[vertex].size(); i++)
  {
    if (visited[adj[vertex][i]]==false)
      topoSortHelper(adj[vertex][i],stk,visited);
  }

  stk.push(vertex);
}


void runTopoSort()
{
  int V = 6;
  adj.resize(V);

  addEdge(2, 3);
  addEdge(3, 1);
  addEdge(4, 0);
  addEdge(4, 1);
  addEdge(5, 2);
  addEdge(5, 0);

  vector<bool> visited(V,false);
  stack<int> stk;

  for(int i=0; i<V; i++)
  { 
    if(visited[i]==false)
      topoSortHelper(i,stk,visited);
  }

  while(!stk.empty())
  { 
    cout << stk.top() << "\t";
    stk.pop();
  }
  
}