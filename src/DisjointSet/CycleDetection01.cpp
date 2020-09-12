//Rathinavel Sankaralingam
//Aug 30, 2020


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Edge
{
  int src, dst;
};

class Graph
{
public:

  vector<vector<int>> adjList;

  Graph(vector<Edge> &edges, int N)
  {
    adjList.resize(N+1);
    for (auto edge : edges)
    {
      adjList[edge.src].push_back(edge.dst);
    }
  }
};

class Main
{
  unordered_map<int ,int> parent;
  
public:
  void makeSet(int N)
  {
    for (int i = 1; i <= N; i++)
    {
      parent[i] = i;
    }
  }

  int find(int k)
  {
    if(parent[k] == k)
      return k;

    find(parent[k]);
  }

  void _union(int a, int b)
  {
    int A = find(a);
    int B = find(b);
    
    parent[A] = B;
  }
};

bool findCycle(Graph &gr, int N)
{
  Main ds;
  ds.makeSet(N);
  
  for (int u = 1; u <= N; u++)
  {
    int U = ds.find(u);
    for (int v : gr.adjList[u])
    {
      int V = ds.find(v);
      if(U == V)
        return true;
      else
        ds._union(U,V);
    }
  }
  return false;
}

void runCycleDetection()
{
  vector<Edge> edges =
  {
    {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
    {3, 5}, {8, 9}, {8, 12}, {9, 10}, {10, 11}, {11, 12}
    // edge (11, 12) introduces a cycle in the graph
  };

  // Number of nodes in the graph
  int N = 12;

  Graph graph(edges,N);
  
  if(findCycle(graph,N))
    cout << "Yes\n";
  else
    cout << "No\n";

  
}