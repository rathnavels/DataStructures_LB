//Rathinavel Sankaralingam
//Apr 12, 2020


#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> adj;

bool IsConnected = false;

static void addEdge(int u, int v)
{
  adj[u].push_back(v);
}

bool findIfConnected(int start, int end, vector<bool> &visited)
{
  if(start == end)
    return true;

  if (visited[start] == true)
    return false;

  visited[start] = true;
  
  for (int i = 0; i < adj[start].size(); i++)
  {
    if(visited[adj[start][i]] == false)
      IsConnected |= findIfConnected(adj[start][i],end,visited);
  }
  
  return IsConnected;
}

void runStartToEnd()
{
  adj.resize(7);
  int N = 6;

  addEdge(1,3);
  addEdge(1,6);
  addEdge(2,4);
  addEdge(3,2);
  addEdge(5,6);
  addEdge(6,2);

  vector<bool> visited(N+1,false);
  int start = 1;
  int end = 4;
  if(findIfConnected(start,end,visited))
    cout << "Yes";
  else
    cout << "No";

}