//Rathinavel Sankaralingam
//Jan 10, 2020


#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative
ListNode* reverseKGroup01(ListNode* head, int k)
{
  if (k == 1 || !head)
    return head;

  int count = 0;
  ListNode* node = head;


  // Please note that the dummy is not connected to the head.
  ListNode* dummy = new ListNode(-1);

  while (node) { node = node->next; count++; }

  if (k > count) return head;

  int countCpy(count);

  ListNode* pre = dummy;
  ListNode* cur = head;
  ListNode* nxt = NULL;

  ListNode* localHead, *localTail, *prevLocalTail, *masterHead;

  while (count >= k)
  {
    localTail = cur;
    prevLocalTail = pre;

    for (int i = 0; i < k; i++)
    {
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }

    if (countCpy == count)
      masterHead = pre;

    localHead = pre;
    localTail->next = NULL;
    prevLocalTail->next = localHead;
    pre = localTail;

    count -= k;
  }
  pre->next = cur;
  return masterHead;
}


// Recursive
ListNode* reverseKGroup02(ListNode* head, int k)
{
  int rem = k;

  ListNode* curr = head;
  ListNode* next = NULL;
  ListNode* prev = NULL;
  while (curr != NULL && rem != 0)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    rem--;
  }

  if (rem > 0)
  {
    curr = prev;
    next = NULL;
    prev = NULL;
    while (curr != NULL && rem != 0)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  if (curr != NULL)
    head->next = reverseKGroup02(curr, k);

  return prev;
}

void runLeetCode25()
{
  
}