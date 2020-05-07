//Rathinavel Sankaralingam
//Jan 10, 2020


#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists)
  {
    ListNode *mergedList = new ListNode(-1);
    int totalCount = 0;
    int N = lists.size();

    for (int i = 0; i < N; i++)
    {
      ListNode *node = lists[i];
      while (node) { node = node->next; totalCount++; }
    }


    ListNode *node = mergedList;
    ListNode *newNode;
    int index;
    while (totalCount--)
    {
      int currentMin = INT_MAX;

      for (int i = 0; i < N; i++)
      {
        if (lists[i] && lists[i]->val < currentMin)
        {
          currentMin = lists[i]->val;
          newNode = lists[i];
          index = i;
        }
      }
      lists[index] = lists[index]->next;

      node->next = newNode;
      node = newNode;
    }

    return mergedList->next;
  }
};

void runLCHard23()
{

}