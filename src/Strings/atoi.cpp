//Rathinavel Sankaralingam
//Feb 24, 2020



#include <iostream>
#include <string>
#include <vector>
using namespace std;

void runStringSearching()
{
  string str = "abcdofilakalagamcdocdofin";
  string ptn = "cdofi";

  int strSize = str.size();
  int ptnSize = ptn.size();

  std::vector<int> indices;

  for(int i=0; i<str.size()-ptnSize; i++)
  {
    int copyOfi = i;
    if(str[i] == ptn[0])
    {
      int charItr = 0;
      while(str[i] == ptn[charItr])
      {
        charItr++;
        i++;

       /* if(str[i]=='\0')
          break;*/
      }

      if(charItr == ptnSize)
        indices.push_back(copyOfi);
      else
        i = copyOfi;
    }
  }

  for(int i : indices)
  {
    cout << i << "\t";
  }

  std::cout << "\n" <<  "Done";
}