//Rathinavel Sankaralingam
//Jan 20, 2020

// String to Integer

#include <iostream>
#include <string>

void runAtoi()
{
  std::string str = "+349A756";
  bool IsNegative = false;
  int number = INT_MAX;
  for(char c : str)
  {
    if(IsNegative == false  && c == '-')
    {
      IsNegative = true;
    }
    else
    {
      if(c - 48 >= 0 && c - 48 <= 9)
      {
        if(number == INT_MAX)
          number = c - 48;
        else
          number = (number * 10) + (c-48);
      } 
      else
      {
        if(number != INT_MAX)
          break;   
      }
    }
  }

  if(number != INT_MAX)
    std::cout << "The number is " << (number * (IsNegative ? -1 : 1));
  else
    std::cout << "There is no number! Oopsss.";
}