//Rathinavel Sankaralingam
//Jan 25, 2020


#include <iostream>
#include <vector>

void runPetrolPump()
{
  std::vector<std::vector<int>> pumpInfo = {{3,4},{8,9},{6,1},{5,7},{3,4}};

  int startPoint =-1;
  for(int i=0; i<pumpInfo.size(); i++)
  {
    int turns = pumpInfo.size();
    int currIdx = i;
    int availableFuel = pumpInfo[i][0];

    if(availableFuel < pumpInfo[currIdx][1])
        continue;

    while(turns > 0)
    {
       currIdx = currIdx % pumpInfo.size();
       int nxtIdx = (currIdx + 1) % pumpInfo.size();
       
       availableFuel = availableFuel - pumpInfo[currIdx][1];
       availableFuel += pumpInfo[nxtIdx][0];

       turns--;
       currIdx++;
    }
    if(turns == 0)
    {
      startPoint = i;
      break;
    }
  }
  std::cout  << "The race should start at " << startPoint;
}