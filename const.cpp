#include <iostream>

using namespace std;

constexpr double square_num(double x)
{
  return x * x;
}

int main()
{
  const int x = 42; // this cannot be changed now
  constexpr double ce = square_num(x); // this works because x is const
  // ce can be evaluated in compile time
  
  cout << ce << '\n';
  return 0;
}
  
