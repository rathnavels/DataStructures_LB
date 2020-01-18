//Rathinavel Sankaralingam
//Jan 18, 2020


// Input : 11, 13, 21, 3 42, 5
// output :
// 11 -- 13
// 13 -- 21
// 21 -- 42
// 3 -- 42
// 42 -- -1
// 5 -- -1

#include <iostream>
#include <vector>

void runNextGreaterElement()
{
  std::vector<int> elements = {4, 5, 2, 25, 7, 32, 8, 6};

  for(int i=0; i<elements.size(); i++)
  {
    int j = 0;
    for(j=i+1; j<elements.size(); j++)
      {
        if(elements[j] > elements[i])
        {
          std::cout << elements[i]  << "\t" << elements[j] << "\n";
          break;
        }
      }
      if(j == elements.size())
        std::cout << elements[i] << "\t"  << "-1" << "\n";
  }
}