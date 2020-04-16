//Rathinavel Sankaralingam
//April 14, 2020


#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> adj;
static int N = 4;

static void addEdge(int u, int v)
{
  adj[u].push_back(v);
}

bool isCyclicUtil(int i, vector<bool> &visited, vector<bool> &recStack)
{
  if (visited[i] == false)
  {
    visited[i] = true;
    recStack[i] = true;

    for (int j = 0; j < adj[i].size(); i++)
    {
      if(!visited[adj[i][j]] && isCyclicUtil(adj[i][j],visited,recStack))
        return true;
      else if(recStack[adj[i][j]])
        return true;
    }
  }
  recStack[i] = false;
  return false;
}


bool isCyclic()
{
  vector<bool> visited(N,false);
  vector<bool> recStack(N, false);

  for(int i=0; i<N; i++)
    if(isCyclicUtil(i,visited,recStack))
      return true;

  return false;
}


void runDetectCycleDirected()
{
  adj.resize(4);
  

  addEdge(0, 1);
  addEdge(1, 2);
  addEdge(2, 3);
  //addEdge(3, 0);

  bool retValue = false;

  if(isCyclic())
    cout << "True";
  else
    cout << "False";
  
}