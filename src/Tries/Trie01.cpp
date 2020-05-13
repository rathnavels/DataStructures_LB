//Rathinavel Sankaralingam
//May 7, 2020


// Trie

#include <iostream>
#include <string>

using namespace std;

#define ALPHABET_SIZE 26

static class TrieNode
{
public:
  class TrieNode *children[ALPHABET_SIZE];

  bool isEndOfWord;
};

TrieNode *getNode(void)
{
  TrieNode* pNode = new TrieNode;

  pNode->isEndOfWord = false;

  for(int i=0; i < ALPHABET_SIZE; i++)
    pNode->children[i] = NULL;

  return pNode;
}

void insert(TrieNode *root, string key)
{
  TrieNode *pCrawl = root;
  
  for (int i = 0; i < key.size(); i++)
  {
    int index = key[i] - 'a';
    if(!pCrawl->children[index])
      pCrawl->children[index] = getNode();

    pCrawl = pCrawl->children[index];
  }
  pCrawl->isEndOfWord = true;  
}

bool search(TrieNode *root, string key)
{
  TrieNode* pCrawl = root;
  
  for (int i = 0; i < key.length(); i++)
  {
    int index = key[i] - 'a';
    if(!pCrawl->children[index])
      return false;

    pCrawl = pCrawl->children[index];
  }

  return (pCrawl != NULL && pCrawl->isEndOfWord);
}


void runTrie01()
{
  string keys[] = {"the","a","tomoato","is","very","good","veg"};

  int n = sizeof(keys) / sizeof(keys[0]);

  TrieNode* root = getNode();
  
  for (int i = 0; i < n; i++)
  {
    insert(root,keys[i]);
  }
  
  search(root, "the") ? cout << "True\n" : cout << "False\n";
  search(root, "veg") ? cout << "True\n" : cout << "False\n";
  search(root, "veggie") ? cout << "True\n" : cout << "False\n";
  search(root, "is") ? cout << "True\n" : cout << "False\n";
}