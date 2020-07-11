#include <iostream>

using namespace std;

void print_whats_read(istream& is)
{
  for (double d; is >> d; )
    cout << d << '\n';
}

int main()
{
  print_whats_read(cin);

  return 0;
}
