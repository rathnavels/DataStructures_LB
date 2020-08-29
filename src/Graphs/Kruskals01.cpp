//Rathinavel Sankaralingam
//June 2, 2020


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 10;
int id[MAX], nodes, edges;
pair<int, pair<int, int>> p[MAX];

void initialize()
{
  for (int i = 0; i < MAX; i++)
  {
    id[i] = i;
  }
}

int root(int x)
{
  while (id[x] != x)
  {
    id[x] = id[id[x]];
    x = id[x];
  }

  return x;
}

void union1(int x, int y)
{
  int p = root(x);
  int q = root(y);

  id[p] = id[q];
}

int kruskal01(pair<int, pair<int, int>> p[])
{
  int x, y;
  
  int cost, minCost=0;

  for (int i = 0; i < edges; i++)
  {
    x = get<0>(get<1>(p[i]));       //  p[i].second.first
    y = get<1>(get<1>(p[i]));       //  p[i].second.second

    cost = get<0>(p[i]);

    if (root(x) != root(y))
    {
      minCost+=cost;
      union1(x,y);
    }
  }
  return minCost;
}

void runKruskals01()
{

  initialize();
  
  nodes = 5;
  edges = 7;

  p[0] = make_pair(1, make_pair(0, 1));
  p[1] = make_pair(7, make_pair(0, 2));
  p[2] = make_pair(5, make_pair(1, 2));
  p[3] = make_pair(4, make_pair(1, 3));
  p[4] = make_pair(3, make_pair(1, 4));
  p[5] = make_pair(6, make_pair(2, 4));
  p[6] = make_pair(2, make_pair(3, 4));

  sort(p,p+edges);

  cout << kruskal01(p);
  
}