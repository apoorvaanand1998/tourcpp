#include <iostream>

using namespace std;

class complex {
private:
  double re, im;
public:
  complex(double r, double i) :re {r}, im {i} {}
  complex(double r) :re {r}, im {0} {}
  complex() :re {0}, im {0} {}

  double real() const { return re; }
  void real(double d) { re = d; }
  double imag() const { return im; }
  void imag(double d) { im = d; }

  complex& operator+=(complex z)
  {
    re += z.re;
    im += z.im;
    return *this;
  }

  complex& operator-=(complex z)
  {
    re -= z.re;
    im -= z.im;
    return *this;
  }

  void print_val()
  {
    cout << real() << ", " << imag() << endl;
  }
};

int main()
{
  complex c { 42, 42 };
  c.print_val();

  complex d { 1, 2 };
  c += d;
  c.print_val();

  return 0;
}
  
