//Rathinavel Sankaralingam
//April 5, 2020


#include <iostream>
#include <set>

using namespace std;

void runGraphUsingSet()
{
  set<int>* settu = new set<int>[6];

  settu[0].insert(5);
  settu->insert(2);
  settu->insert(10);
  settu[2].insert(6);
  settu->insert(3);
  settu[1].insert(9);

  for(auto k : *settu)
    cout << k << "\t";
    
}