#include <iostream>

using namespace std;

struct Vector {
  double* elem;
  int sz;
};

void vector_init(Vector& v, int s)
{
  v.sz = s;
  v.elem = new double[s];
}

int main()
{
  Vector v;
  vector_init(v, 10);

  for (auto i = 0; i < 10; ++i) 
    cin >> v.elem[i];

  double sum = 0;
  for (auto i = 0; i < 10; ++i)
    sum += v.elem[i];
  
  cout << sum << '\n';
  return 0;
}

      
