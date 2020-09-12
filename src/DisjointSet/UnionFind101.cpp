//Rathinavel Sankaralingam
//Aug 29, 2020


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

static class DisjointSet
{
  unordered_map<int, int> parent;

public:
  
  void makeSet(vector<int> const &universe)
  {
    for (int i : universe)
      parent[i] = i;
  }

  int Find(int i)
  {
    //if(parent[i] == i)
    //  return i;
    //
    //return Find(parent[i]);

    while (1)
    {
      if(parent[i] == i)
        return i;
      else
        i = parent[i];
    }
  }

  void Union (int a, int b)
  {
    int x = Find(a);
    int y = Find(b);

    parent[x] = y;
  }
    
};

void printSets(vector<int> const &universe, DisjointSet &ds)
{
  for (int i : universe)
  {
    cout << ds.Find(i) << "\t";
  }
  cout << endl;
}


void runUnionFind101()
{
  vector<int> universe = {1,2,3,4,5,6,7};
  
  DisjointSet ds;

  ds.makeSet(universe);
  printSets(universe,ds);

  ds.Union(4,3);
  printSets(universe, ds);

  ds.Union(2,1);
  printSets(universe, ds);

  ds.Union(1,3);
  printSets(universe, ds);

}