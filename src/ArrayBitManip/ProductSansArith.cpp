//Rathinavel Sankaralingam
//Jun 22, 2020


#include <iostream>
using namespace std;

int add(int a , int b);

void runProductSansArith()
{
  int a = 3, b = -2;

  cout << add(a,b) << endl;

  int sum = 0;

  while (a)
  {
    if(a & 1)
      sum = add(sum,b);
    
    a >>= 1;
    b <<= 1;
  }

  cout << sum;
}

int add(int a, int b)
{
  int carry = 0;
  while (b)
  {
    carry   = a & b;
    a       = a ^ b;
    b       = carry << 1;
  }
  return a;
}