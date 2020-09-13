#include <iostream>
#include <memory>

using namespace std;

class Abs {
public:
  virtual void say() const = 0;
};

class A : public Abs {
public:
  void say() const override {
    cout << "Yahoo I'm A\n";
  }
};

class B : public A {
public:
  void say_b() {
    cout << "I am B and this is what my parent class says\n";
    say();
  }
};

int main()
{
  unique_ptr<Abs> pa { new A() };
  pa->say();
  unique_ptr<Abs> pb { new B() };
  pb->say();
  
  // pb->say_b();
  // pb of type unique_ptr<Abs> has no idea about say_b
  // this is because type info has been lost
  B& br = dynamic_cast<B&>(*pb);
  br.say_b();
}
