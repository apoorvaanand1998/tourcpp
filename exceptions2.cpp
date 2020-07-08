#include <iostream>
#include <stdexcept>

using namespace std;

class Vector {
public:
  Vector(int s);
  double& operator[](int i);
  int size() noexcept;
private:
  double* elem;
  int sz;
};

Vector::Vector(int s) // implementing a class invariant
{
  if (s < 0) {
    throw length_error("Constructor: Negative Size");
  }
  elem = new double[s];
  sz = s;
}

double& Vector::operator[](int i)
{
  if ((i < 0) || (i >= size())) {
    throw out_of_range("Vector::operator[]");
  }
  return elem[i];
}

int Vector::size() noexcept // function guarantees there'll be no error
{
  return sz;
}

int main()
{
  try {
    Vector v(-5);
    // should cause length_error
  }
  catch (length_error& err) {
    cerr << err.what() << '\n';
  }
  catch (bad_alloc& err) {
    cerr << err.what() << '\n';
  }
  return 0;
}
