//Rathinavel Sankaralingam
//Mar 10, 2020

// Tower of Hanoi

#include <iostream>
#include <string>

using namespace std;

void towerOfHanoiHelper(int n, char source, char destination, char buffer);

void runTowerOfHanoi()
{
  int n = 4;
  
  towerOfHanoiHelper(n,'A','C','B');
}

void towerOfHanoiHelper(int n, char source, char destination, char buffer)
{
  if(n == 1)
  {
    cout << "Move disk 1 from rod " << source << " To " << destination << "\n";
    return;
  }

  towerOfHanoiHelper(n-1,source,buffer,destination);

  cout << "Move disk " << n << " from rod " << source << " To " << destination << "\n";

  towerOfHanoiHelper(n-1,buffer,destination,source);
}