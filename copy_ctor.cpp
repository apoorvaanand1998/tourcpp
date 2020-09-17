#include <iostream>

using namespace std;

class Vector {
private:
  double* elem;
  int sz;
public:
  Vector(int s) : sz {s}, elem {new double[s]}
  {
    for (int i = 0; i < s; ++i)
      elem[i] = 0;
  }

  //copy ctor
  Vector(const Vector& v) : sz {v.sz}, elem {new double[v.sz]}
  {
    for (int i = 0; i < v.sz; ++i)
      elem[i] = v.elem[i];
  }

  //copy assignment
  Vector& operator=(const Vector& v)
  {
    sz = v.sz;
    delete[] elem;
    elem = new double[v.sz];
    for (int i = 0; i < v.sz; ++i)
      elem[i] = v.elem[i];
    return *this;
  }
  
  ~Vector()
  {
    delete[] elem;
  }

  double& operator[](int i)
  {
    return elem[i];
  }

  int size()
  {
    return sz;
  }
};

int main()
{
  Vector v(4);
  v[0] = 1;
  v[1] = 2;
  
  for (int i = 0; i < v.size(); ++i)
    cout << v[i] << ' ';
  cout << '\n';

  /*
  Vector vc(v);
  vc[1] = 3;

  cout << vc[1] << ' ' << v[1] << '\n';
  */
  // above causes error because of memberwise copying
  // in default copy constructor

  Vector vc(v);
  vc[1] = 3; // this shouldn't cause an issue

  cout << vc[1] << ' ' << v[1] << '\n';

  Vector va(7);
  // testing out copy assignment
  va = v;

  for (int i = 0; i < va.size(); ++i)
    cout << va[i] << ' ';
  cout << '\n';
}

  
    
