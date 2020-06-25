#include <iostream>

using namespace std;

class Vector {
private:
  int sz;
  double* elem;
public:
  Vector(int s) :elem {new double[s]}, sz {s} {}
  double& operator[](int i) { return elem[i]; }
  int size() { return sz; }
};

int main()
{
  Vector v(10);

  for (auto i = 0; i < v.size(); ++i)
    cin >> v[i];

  double sum = 0;
  for (auto i = 0; i < v.size(); ++i)
    sum += v[i];

  cout << sum << '\n';
  return 0;
}
  
