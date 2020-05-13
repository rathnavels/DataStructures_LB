//Rathinavel Sankaralingam
//May 11, 2020


#include <iostream>
#include <unordered_map>

using namespace std;

static class Trie
{
public:
  bool isEndOfWord;
  unordered_map<char, Trie*> mp;
};

Trie* getNode(void)
{
  Trie* node = new Trie;
  node->isEndOfWord = false;

  return node;
}

void insert(Trie*& root, const string &str)
{
  if (root == nullptr)
    root = getNode();

  Trie* crawl = root;

  for (int i = 0; i < str.length(); i++)
  {
    char x = str[i];

    if(crawl->mp.find(x) == crawl->mp.end())
      crawl->mp[x] = getNode();

    crawl = crawl->mp[x];
  }

  crawl->isEndOfWord = true;
}

bool search(Trie *root, string key)
{
  if(root == nullptr)
    return false;

  Trie* crawl = root;

  for (char c : key)
  {
    if(crawl->mp.find(c) == crawl->mp.end())
      return false;

    crawl = crawl->mp[c];
  }

  return  (crawl!=NULL && crawl ->isEndOfWord);
}

void runTrie03()
{
  string keys[] = { "the","a","tomoato","is","very","good","veg" };

  int n = sizeof(keys) / sizeof(keys[0]);

  Trie* root = nullptr;

  for (int i = 0; i < n; i++)
  {
    insert(root, keys[i]);
  }

  search(root, "the") ? cout << "True\n" : cout << "False\n";
  search(root, "veg") ? cout << "True\n" : cout << "False\n";
  search(root, "veggie") ? cout << "True\n" : cout << "False\n";
  search(root, "is") ? cout << "True\n" : cout << "False\n";
}