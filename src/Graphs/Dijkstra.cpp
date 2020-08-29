//Rathinavel Sankaralingam
//May 16, 2020


#include <iostream>
#include <vector>
using namespace std;

#define V 9

int minDistance(int dist[], bool sptSet[])
{ 
  int min = INT_MAX, minIndex;

  for (int v = 0; v < V; v++)
  {
    if (sptSet[v] == false && dist[v] <= min)
    {
      min = dist[v], minIndex = v;
    }
  }
  return minIndex;
}

void print(int dist[])
{
  for(int i=0; i < V; i++)
    std::cout << i << "\t" << dist[i] << "\n";
}

void dijkstra(int graph[V][V], int src)
{
  int dist[V];
  
  bool sptSet[V];
  
  for (int i = 0; i < V; i++)
  {
    dist[i] = INT_MAX, sptSet[i] = false;
  }

  dist[src] = 0;

  for (int count = 0; count < V - 1; count++)
  {
    int u = minDistance(dist,sptSet);
    
    sptSet[u] = true;

    for (int v = 0; v < V; v++)
    {
      if(!sptSet[v] && graph[u][v]){}
    }
  }
}

void runDijkstra()
{
  
}