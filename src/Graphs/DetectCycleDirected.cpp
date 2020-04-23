//Rathinavel Sankaralingam
//April 14, 2020


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

static vector<vector<int>> adj;
static int N = 4;

static void addEdge(int u, int v)
{
  adj[u].push_back(v);
}

static enum Status
{
  UNVISITED = -1,
  STACKED,
  VISITED
};


bool isCyclic()
{
  vector<int> visited(N,-1);

  stack<int> stk;
  stk.push(0);
  visited[0] = STACKED;
  
  while (!stk.empty())
  {
    int top = stk.top();

    if(adj[top].size() == 0)
    { 
      visited[top] = VISITED;
      stk.pop();
      top = stk.top();
    }
    int visitedCount = 0;
    for (int i = 0; i < adj[top].size(); i++)
    {
      if(visited[adj[top][i]] == UNVISITED)
      { 
        stk.push(adj[top][i]);
        visited[adj[top][i]] = STACKED;
      }
      else if(visited[adj[top][i]] == STACKED)
        return true;
      else
      { 
        visitedCount++;
        if(visitedCount == adj[top].size())
          return true;
      }
    }
  }

  return false;
}


void runDetectCycleDirected()
{
  adj.resize(N);
  
  addEdge(0, 2);
  addEdge(0, 3);
  addEdge(2, 4);
  //addEdge(1, 2);
  addEdge(2, 3);

  bool retValue = false;

  if(isCyclic())
    cout << "True";
  else
    cout << "False";
  
}