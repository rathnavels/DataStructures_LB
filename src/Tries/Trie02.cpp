//Rathinavel Sankaralingam
//May 07, 2020


#include <iostream>
#include <memory>

using namespace std;

#define ALPHABET_SIZE 26

static class TrieNode
{
public:
  shared_ptr<TrieNode> children[ALPHABET_SIZE];

  bool isEndOfWord;

  TrieNode()
  {
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
      children[i] = shared_ptr<TrieNode>();
    }
    isEndOfWord = false;
  }
};

class Interface
{
  public:

    Interface(){}
    virtual ~Interface(){}

    virtual int c2i(char) = 0;
    virtual void insertWord(string&) = 0;
    virtual bool deleteWord(string&) = 0;
    virtual bool searchWord(string&) = 0;
    virtual bool isEmptyNode(shared_ptr<TrieNode>) const = 0;
    
};

class Trie : public Interface
{
  shared_ptr<TrieNode> root;
  int totalWords;

  public:
    Trie()
    {
      root = shared_ptr<TrieNode>(new TrieNode());
    }

    ~Trie(){}

    int c2i(char a)
    {
       return static_cast<int> (a - 'a');
    }

    void insertWord(string &str)
    {
      auto crawl = root;
      for (int i = 0; i < str.size(); i++)
      {
        int index = c2i(str[i]);
        if (crawl->children[index] == shared_ptr<TrieNode>(nullptr))
        {
          crawl->children[index] = shared_ptr<TrieNode>(new TrieNode());
        }
        crawl = crawl->children[index];
      }
      crawl->isEndOfWord = true;
    }

    bool searchWord(string &str)
    {
      auto crawl = root;
      for (int i = 0; i < str.size(); i++)
      {
        int index = c2i(str[i]);
        if(crawl->children[index] == shared_ptr<TrieNode>(nullptr))
          return false;
        
        crawl = crawl->children[index];
      }
      return (crawl != NULL && crawl->isEndOfWord);
    }

    bool partDelete(string &str, shared_ptr<TrieNode> &checkout)
    {
      if(checkout == nullptr)
        return false;

      if (str.size() == 0)
      {
        if(checkout->isEndOfWord == true)
        {   
          checkout->isEndOfWord = false;
          return true;
        }
        return false;
      }

      string part = str.substr(1);

      int index = c2i(str[0]);
      if (partDelete(part, checkout->children[index]))
      {
        if (isEmptyNode(checkout->children[index]))
        {
          checkout->children[index].reset();
          checkout->children[index] = nullptr;
        }
        return true;
      }
      else
        return false;

    return false;
    }

    bool deleteWord(string &str)
    {
      if (partDelete(str,root))
        return true;

      return false;
    }

    bool isEmptyNode(shared_ptr<TrieNode> check) const
    {
      for (int i = 0; i < ALPHABET_SIZE; i++)
      {
        if(check->children[i] != nullptr || check->isEndOfWord)
          return false;
      }
      return true;
    }
};


void runTrie02()
{
  shared_ptr<Trie> myTrie(new Trie());
  
  string word0 = "geeks";
  string word1 = "geeksfor";
  string word2 = "geeksforgeeks";
  string word3 = "nothing";
  string word4 = "wow";

  myTrie->insertWord(word1);
  myTrie->insertWord(word2);
  myTrie->insertWord(word3);
  myTrie->insertWord(word4);
  myTrie->deleteWord(word1);

  cout << (myTrie->searchWord(word2) ? "True" : "False");
  
}