//Rathinavel Sankaralingam
//Jan 25, 2020

// String to Integer

#include <iostream>
#include <string>
#include <algorithm>

class List
{
  public:
  int val;
  List* next;
  List(){}
  List(int _val) : val(_val), next(NULL){}
  List(int _val, List* node) : val(_val), next(node){}
};

List *head, *list;

// ---------------------------------------------------------
// printList
// ---------------------------------------------------------
void printList()
{
  List *node = head;
  std::cout << "The list is\n";
  while(node)
  {
    std::cout << node ->val << "  ";
    node = node->next;
  }
  std::cout << "\n";
}

// ---------------------------------------------------------
// InsertAtBeginning
// ---------------------------------------------------------
void InsertAtBeginning(int num)
{
  List *node = new List;
  node -> val = num;
  node -> next = head;
  head = node;
  printList();
}

// ---------------------------------------------------------
// InsertAtEnd
// ---------------------------------------------------------
void InsertAtEnd(int num)
{
  List *node = new List(num);
  auto traverseNode = head;
  
  while(traverseNode->next!=NULL)
    traverseNode = traverseNode->next;

  if(traverseNode->next == NULL)  
    traverseNode->next = node;

  printList();
}

// ---------------------------------------------------------
// searchByValue
// ---------------------------------------------------------
void searchByValue(int num)
{
  List *node = head;
  while(node)
  {
    if(node->val == num)
      break;
    node = node->next;
  }
  if(node == NULL)
    std::cout << "The value not found:\n";
  else
    std::cout << "Value found\n";
}

// ---------------------------------------------------------
// searchByIndex
// ---------------------------------------------------------
void searchByIndex(int idx)
{
  auto node = head;
  int i=0;
  int valueAtIdx;
  while(node)
  {
    if(i == idx)
    {
      valueAtIdx = node->val;
      break;
    }
    node = node->next;
    i++;
  }
  if(node)
  {
    std::cout << "The value at " << idx << "th index is " << valueAtIdx << "\n";
  }
  else
  {
    std::cout << "The index is out of bounds\n";
  }
}

// ---------------------------------------------------------
// deleteByValue
// ---------------------------------------------------------
void deleteByValue(int val)
{
  if(head->val == val)
  {
    head = head->next;
    printList();
    return;
  }

  auto node = head->next;
  auto prev = head;
  
  while(node)
  {
    if(node->val == val)
    {
      prev->next = node->next;
    }
    prev = node;
    node = node->next;
  }

  printList();
}

// ---------------------------------------------------------
// deleteByIndex
// ---------------------------------------------------------
void deleteByIndex(int idx)
{

  if(idx == 0)
  {
    head = head->next;
    printList();
    return;
  }

  auto node = head->next;
  auto prev = head;
  int i = 1;
  while(node)
  {
    if(i==idx)
    {
      prev->next = node->next;
      break;
    }
    i++;
    prev = node;
    node = node->next;
  }

  printList();
}

// ---------------------------------------------------------
// reverseIteration
// ---------------------------------------------------------
void reverseIteration()
{
  if(head == NULL || head->next == NULL)
    return;

  auto curr = head->next;
  auto prev = head;
  prev->next = NULL;
  while(curr->next)
  {
    auto temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  curr->next = prev;
  head = curr;
  printList();
}


// ---------------------------------------------------------
// printInReverse
// ---------------------------------------------------------
void printInReverse(List *node)
{
  if(node == NULL)
    return;

  printInReverse(node->next);

  std::cout << node->val << "\t";
}



// ---------------------------------------------------------
// sort
// ---------------------------------------------------------
void sort()
{ 
  // This is selection sort
  for(auto node = head; node->next!=NULL; node=node->next)
  {
    for(auto nxt = node->next; nxt!=NULL; nxt=nxt->next)
    {
      if(node->val > nxt->val)      
      {
        std::swap(node->val,nxt->val);
      }
    }
  }
  std::cout << "Sorting has happened\n";
  printList();
}


void reverseUtil(List *curr, List *prev, List** head)
{
  if(!curr->next)
  {
    *head = curr;
    curr->next = prev;
    return;
  }
  
  auto next = curr->next;
  curr->next = prev;
  reverseUtil(next,curr,head);
}

// ---------------------------------------------------------
// reverseRecursion
// ---------------------------------------------------------
void reverseRecursion()
{
  if(!head)
    return;
  
  reverseUtil(head, NULL, &head);

}


// ---------------------------------------------------------
// createList
// ---------------------------------------------------------
void createList()
{
  head = new List(5);
}

// ---------------------------------------------------------
// sizeOfLinkedList
// ---------------------------------------------------------
void sizeOfLinkedList()
{
  int i = 0;
  auto node = head;
  while(node)
  {
    i++; 
    node = node->next;
  }
  std::cout << "The size of the Linked List is " << i << "\n";
}


void runLinkedList()
{
  createList();

  printList();

  InsertAtBeginning(4);
  InsertAtEnd(6);
  InsertAtBeginning(3);
  InsertAtEnd(7);
  InsertAtBeginning(4);
  InsertAtBeginning(3);
  InsertAtEnd(7);
  
  reverseIteration();
  InsertAtBeginning(8);
  InsertAtEnd(2);
  InsertAtBeginning(12);
  sort();


  reverseRecursion();
  printList();
  reverseRecursion();
  printList();

  std::cout << std::endl;
  std::cout << "Printing in Reverse\n";
  
  printInReverse(head);

}





