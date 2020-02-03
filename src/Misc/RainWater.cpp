//Rathinavel Sankaralingam
//Jan 25, 2020


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void runRaintrap() 
{
    vector<int> height = {0,1,0,3,1,0,1,2,2,1,2,1};
    std::vector<std::vector<int>> pairs;
    int a,b;
    for(int i=0; i<height.size()-1;i++)    
    {
        int j = i+1;
        if(height[i] > height[j])
        {
            a = height[i];
            while(height[i] > height[j])
            {
                j++;

                if(j==height.size())
                  break;
            }

            if(j<height.size())
            {
              b = height[j];
              pairs.push_back({i,j});
              i = j;
              i--;
            }
        }
    }
    int rainWater = 0;
    for(int i=0; i<pairs.size(); i++)
    {
      
      int minHeight = std::min(height[pairs[i][0]],height[pairs[i][1]]);
      for(int k = pairs[i][0]; k < pairs[i][1]; k++)
      { 
        rainWater += (minHeight - height[k]);
      }
    }
    std::cout << "Rain Water is " << rainWater;
}