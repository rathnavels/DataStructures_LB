//Rathinavel Sankaralingam
//Apr 29, 2020


#include <iostream>
#include<list>
#include<unordered_map>

using namespace std;

class LRUCache
{
private:
  list<int> dq;
  unordered_map<int, list<int>::iterator> mp;
  int csize;

public:
  LRUCache(int);
  void refer(int);
  void display();
  
};

LRUCache::LRUCache(int csz) : csize(csz){}

void LRUCache::refer(int key)
{
  if (mp.find(key) == mp.end())
  {
    if (dq.size() == csize)
    {
      int last = dq.back();
      dq.pop_back();
      mp.erase(last);
    }
  }
  else
    dq.erase(mp[key]);

  dq.push_front(key);
  mp[key] = dq.begin();
}

void LRUCache::display()
{
  cout << "\n";
  for(auto itr = dq.begin(); itr!=dq.end(); itr++)
      cout << *itr << "\t";
}


void runLRUCache()
{
  LRUCache lc(4);
  lc.refer(1);
  lc.refer(2);
  lc.refer(3);
  lc.refer(2);
  lc.display();

  lc.refer(4);
  lc.refer(5);
  lc.refer(6);
  lc.refer(2);
  lc.display();

  vector<int> k = {1,2,3};

  cout << "\n" << k.capacity();

  
}