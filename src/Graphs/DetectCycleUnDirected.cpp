//Rathinavel Sankaralingam
//April 17, 2020


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> adj;
static int N = 4;

static enum Status
{
  UNVISITED = -1,
  QUEUED,
  VISITED
};

static void addEdge(int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

bool isCyclic(vector<int> &visited)
{
  queue<int> que;

  que.push(0);
  visited[0] = QUEUED;
  while (!que.empty())
  {
    int val = que.front(); que.pop();
    visited[val] = VISITED;

    int size = adj[val].size();
    for(int i=0; i<size; i++)
    { 
      if(visited[adj[val][i]] == UNVISITED)
      { 
        que.push(adj[val][i]);
        visited[adj[val][i]] = QUEUED;
      }
      else if(visited[adj[val][i]] == QUEUED)
        return true;
    }
  }
  return false;
}

void runDetectCycleUnDirected()
{
  int N = 5;
  adj.resize(N);
  vector<int> visited(N,UNVISITED);

  addEdge(0, 3);
  addEdge(1, 2);
  addEdge(1, 0);
  addEdge(3, 4);
  addEdge(2, 0);
  //addEdge(3, 4);
  
  if(isCyclic(visited))
    cout << "True";
  else
    cout << "False";
  
}