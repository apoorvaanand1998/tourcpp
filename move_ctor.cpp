#include <iostream>
#include <stdexcept>

class Vector {
private:
  double* elem;
  int sz;
public:
  Vector(int n) : sz { n }, elem { new double[n] }
  {
    for (int i = 0; i < n; ++i)
      elem[i] = 0;
  }

  Vector(Vector&& v) : sz { v.sz }, elem { v.elem }
  {
    v.sz = 0;
    v.elem = nullptr;
  }

  Vector& operator=(Vector&& v)
  {
    delete[] elem;
    sz = v.sz;
    elem = v.elem;
    v.sz = 0;
    v.elem = nullptr;
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

Vector operator+(Vector& a, Vector& b)
  {
    if (a.size() != b.size())
      throw std::length_error { "Vectors should be of same length "}; // Should probably be another type of error

    Vector res(a.size());

    for (int i = 0; i < a.size(); i++)
      res[i] = a[i] + b[i];

    return res;
  }

int main()
{
  Vector a(5);
  for (int i = 0; i < a.size(); ++i)
    a[i] = i+1;

  Vector b(std::move(a));
  for (int i = 0; i < b.size(); ++i)
    std::cout << b[i] << ' ';
  std::cout << '\n';
  
  Vector c(5);
  for (int i = 0; i < c.size(); ++i)
    c[i] = c.size() - i;

  Vector d(5);
  d = b+c;

  for (int i = 0; i < d.size(); ++i)
    std::cout << d[i] << ' ';
  std::cout << '\n';
  
  return 0;
}
