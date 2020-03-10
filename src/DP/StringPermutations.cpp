//Rathinavel Sankaralingam
//Mar 09, 2020

// String to Integer

#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;

set<string> genPermutations(string str);
string insertCharAt(string word, char c, int i);

void runStringPermutations()
{
  string str = "abcd";

  set<string> retStr = genPermutations(str);

  for(string s : retStr)
    std::cout << s << endl;
}

set<string> genPermutations(string str)
{
  set<string> permutations; 
  
  if(str.length() == 0)
  {
    permutations.insert("");
    return permutations;
  }

  char first = str[0];

  string remaining = str.substr(1);
  set<string> words = genPermutations(remaining);

  for(string word : words)
  {
    for(int i = 0; i<=word.length(); i++)
    {
      string s = insertCharAt(word,first,i);
      permutations.insert(s);
    }
  }
  return permutations;
}

string insertCharAt(string word, char c, int i)
{
  string start = word.substr(0,i);
  string end = word.substr(i);

  return start + c + end;
}
