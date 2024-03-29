#include <iostream>
using std::cout;

class Base {
public:
  virtual void fooVirtual() const { cout << "Base class virtual function\n"; }
  void fooNotVirtual() const { cout << "Base class non-virtual function\n"; }
};

class Derived : public Base {
public:
  void fooVirtual() const override { cout << "Base class virtual function\n"; }
  void fooNotVirtual() const { cout << "Base class non-virtual function\n"; }
};

int main() {
  Base b;
  Derived d;

  //  1) A base class pointer to the base class object.
  Base *bPb = &b;

  //  2) A base class pointer to the derived class object.
  Base *bPd = &d;

  //  3) A derived class pointer to the derived class object.
  Derived* dPd = &d;

  //  4) A base class reference to the base class object.
  Base& bRb = b;
  //  5) A base class reference to the derived class object. 
  Base& bRd = d;
  //  6) A derived class reference to the derived class object.
  Derived& dRd = d;

  cout << "Calling non-virtual function from Base class pointer to base: ";
  bPb->fooNotVirtual();

  cout << "Calling virtual function from Base class pointer to base: ";
  bPb->fooVirtual();

  //Call both functions from pointers 2-6
  cout << "\nBase pointer to Derived____________\n";
  cout << "Calling non-virtual: ";
  bPd->fooNotVirtual();
  cout << "Calling virtual: ";
  bPd->fooVirtual();

  cout << "\nDerived pointer to Derived____________\n";
  cout << "Calling non-virtual: ";
  dPd->fooNotVirtual();
  cout << "Calling virtual: ";
  dPd->fooVirtual();
  
  cout << "\nBase reference to Base____________\n";
  cout << "Calling non-virtual: ";
  bRb.fooNotVirtual();
  cout << "Calling virtual: ";
  bRb.fooVirtual();

  cout << "\nBase reference to Derived____________\n";
  cout << "Calling non-virtual: ";
  bRd.fooNotVirtual();
  cout << "Calling virtual: ";
  bRd.fooVirtual();

  cout << "\nDerived reference to Derived____________\n";
  cout << "Calling non-virtual: ";
  dRd.fooNotVirtual();
  cout << "Calling virtual: ";
  dRd.fooVirtual();
  return 0;
}