//Rathinavel Sankaralingam
//Jan 10, 2020


#include <iostream>

// Input : a = 10, b = 20 and c = 30
// Output : a = 30, b = 10 and c = 20

// Swap three variables without using temporary variable

void runSwapThree1()
{
  int a = 10, b = 20, c = 30;

  a = a+b;
  b = a-b;
  a = a-b;

  a = a+c;
  c = a-c;
  a = a-c;
  
  std::cout  << a << "\t" << b << "\t" << c << "\n";
  
}

void runSwapThree2()
{
  int a = 10, b = 20, c = 30;

  a = a+b+c;
  b = a-b-c;
  c = a-b-c;
  a = a-b-c;
  
 std::cout  << a << "\t" << b << "\t" << c;
}