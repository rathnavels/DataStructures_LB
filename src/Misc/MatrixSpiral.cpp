//Rathinavel Sankaralingam
//Jan 10, 2020

// Print Matrix in a spiral


#include <iostream>

void runMatrixSpiral()
{
  const int rows = 6;
  const int cols = 5;
  int a[rows][cols] = {{1,2,3,4,5},
                 {6,7,8,9,10},
                 {1,2,3,4,5},
                 {6,7,8,9,10},
                 {1,2,3,4,5},
                 {6,7,8,9,10}};
   
  bool left=false,right=true,up=false,down=false;

  int x=0; 
  int y=0;
  
  int maxX = cols;
  int maxY = rows;
  int minX = 0;
  int minY = 0;

  for(int i=0; i<30; i++)
  {
    std::cout << a[x][y];
    if(right)
      y++;
    if(down)
      x++;
    if(up)
      x--;
    if(left)
      y--;
    if(y == maxX)
    {
      y--;
      x++;
      right = false;
      down = true;
    }
    if(x == maxY)
    {
      x--;
      y--;
      down = false;
      left = true;
    }
    if(left && y == minX)
    {
      up = true;
      left = false;
    }
    if(up && x == minY)
    {
      up = false;
      right = true;
      minX++;
      minY++;
      maxX--;
      maxY--;
      x = minX;
      y = minY;
    }
  }
}