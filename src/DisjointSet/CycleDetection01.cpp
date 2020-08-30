//Rathinavel Sankaralingam
//Aug 30, 2020


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Edge
{
  int src, dest;
};

class Graph
{
  public:
    vector<vector<int>> adjList;

    Graph(vector<Edge> const &edges, int N)
    {
      adjList.resize(N+1);

      for (auto edge : edges)
        adjList[edge.src].push_back(edge.dest);
    }
};

static class DisjointSet
{
  private:
    unordered_map<int, int> parent;

  public:

    void makeSet(int N)
    {
      for(int i=1; i<=N; i++)
        parent[i] = i;
    }

    int Find(int i)
    {
      if(parent[i] == i)
        return i;

      return Find(parent[i]);
    }

    void Union(int a, int b)
    {
      int x = Find(a);
      int y = Find(b);

      parent[x] = y;
    }
};

bool findCycle(Graph const &graph, int N)
{
  DisjointSet ds;

  ds.makeSet(N);

  for (int u = 1; u <= N; u++)
  {
    for (int v : graph.adjList[u])
    {
      int x = ds.Find(u);
      int y = ds.Find(v);

      if(x == y)
        return true;
      else
        ds.Union(x,y);
    }
  }
  return false;
}

void runCycleDetection()
{
  vector<Edge> edges = 
  {
    {1,2}, {1,7}, {1,8}, {2,3}, {2,6}, {3,4},
    {3,5}, {8,9}, {8,12}, {9,10}, {9,11}, {11,12}
  };

  int N = 12;

  Graph graph(edges, N);
    
  if (findCycle(graph, N))
    cout << "Cycle Found";
  else
    cout << "No Cycle";
  
}