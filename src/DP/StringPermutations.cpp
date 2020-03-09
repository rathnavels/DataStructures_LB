//Rathinavel Sankaralingam
//Mar 09, 2020

// String to Integer

#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<string> genPermutations(string str);
string insertCharAt(string word, char c, int i);

void runStringPermutations()
{
  string str = "abcd";

  vector<string> retStr = genPermutations(str);

  for(string s : retStr)
    std::cout << s << endl;
}

vector<string> genPermutations(string str)
{
  vector<string> permutations; 
  
  if(str.length() == 0)
  {
    permutations.push_back("");
    return permutations;
  }

  char first = str[0];

  string remaining = str.substr(1);
  vector<string> words = genPermutations(remaining);

  for(string word : words)
  {
    for(int i = 0; i<=word.length(); i++)
    {
      string s = insertCharAt(word,first,i);
      permutations.push_back(s);
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
