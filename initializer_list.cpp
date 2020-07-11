#include <iostream>

using namespace std;

class Vector {
private:
  double* elem;
  int sz;
public:
  Vector(initializer_list<double> lst)
    : elem { new double[lst.size()] }, sz { static_cast<int>(lst.size()) }
  {
    copy(lst.begin(), lst.end(), elem);
  }
  
  Vector(int n) : elem { new double[n] }, sz { n }
  {
    for (auto i = 0; i != n; ++i)
      elem[i] = 0;
  }

  ~Vector()
  {
    delete[] elem;
  }

  double& operator[](int n)
  {
    return elem[n];
  }

  int size()
  {
    return sz;
  }
};

int main()
{
  auto n = 5;
  
  Vector v0 = { 1, 1, 42 };
  cout << v0.size() << endl;
  // above should be 3
  
  Vector v1(n);
  cout << v1.size() << endl;

  {
    Vector v2(2*n);
    cout << v2.size() << endl;
    cout << v1.size() << endl;
  }

  cout << v1.size() << endl;
  // cout << v2.size() << endl;
  // above should give error

  return 0;
}
