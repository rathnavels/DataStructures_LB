//Rathinavel Sankaralingam
//Feb 18, 2020

//Move Zeros To End
#include <iostream>
#include <vector>

using namespace std;
void print(std::vector<int> &arr);

void runMoveZeroToEnd02()
{
  vector<int> nums= {3,0,52,0,0,1,0,7,2,8,9,6,0};
  
  int lastNonZeroFound = 0;
        for(int cur = 0; cur < nums.size(); cur++)
        {
            if(nums[cur]!=0)
                swap(nums[lastNonZeroFound++],nums[cur]);
        }

  print (nums);
  
}

