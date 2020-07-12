#include <iostream>
#include <list>

using namespace std;

class Container {
public:
  virtual double& operator[](int i) = 0;
  virtual int size() const = 0;
  virtual ~Container() { }
};

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

  int size() const
  {
    return sz;
  }
};

class Vector_container : public Container {
private:
  Vector v;
public:
  Vector_container(int n) : v(n) { }
  Vector_container(initializer_list<double> il) : v {il} { }
  ~Vector_container() { }

  double& operator[](int i) override { return v[i]; }
  int size() const override { return v.size(); }
};

class List_container : public Container {
private:
  list<double> ld;
public:
  List_container() { }
  
  List_container(initializer_list<double> il) : ld { il } { }

  ~List_container() { }

  double& operator[](int i)
  {
    for (auto& x : ld) {
      if (i == 0)
	return x;
      --i;
    }
    throw out_of_range("List Container");
  }

  int size() const
  {
    return ld.size();
  }
};

void use(Container& c)
{
  /* use() does not know which child class of 
   Container will be passed to it, it doesn't
   matter to it because it uses Container's 
   interface and find's the right functions to 
   call using the virtual function table */
  
  const int sz = c.size();

  for (int i = 0; i != sz; ++i)
    cout << c[i] << '\n';
}

void v()
{
  Vector_container vc = { 1, 2, 3, 4, 5 };

  use(vc);
}

void l()
{
  List_container lc = { 5, 4, 3, 2, 1 };

  use(lc);
}

int main()
{
  v();
  l();
  // should print 1 to 5 and then 5 to 1
  return 0;
}
