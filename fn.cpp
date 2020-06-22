#include <iostream>

using namespace std;

double square_num(double x)
{
  return x * x;
}

void output_sq(double x)
{
  cout << "The square of your number is " << square_num(x) << "\n";
}

int main()
{
  output_sq(4.2);
  return 0;
}
