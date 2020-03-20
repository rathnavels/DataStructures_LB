//Rathinavel Sankaralingam
//Mar 12, 2020


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void runMinNumOfCoins()
{
  vector<int> coins = {186,419,83,408};

  int amount = 6249;

  vector<int> minWays(amount+1, amount+1);
  minWays[0] = 0;

  for(int denom : coins)  
  {
    for(int i=denom; i<minWays.size(); i++)
    {
      minWays[i] = min(minWays[i], 1 + minWays[i-denom]);
    }
  }

  std::cout << ((minWays[amount] == amount+1) ? -1 : minWays[amount]);
}