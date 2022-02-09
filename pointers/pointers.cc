#include <iostream>
using namespace std;

int main() { 
  int x = 5;
  int y = 0;
  float pi = 3.14;

  //1. we're going to create new kind of variable
  int *pal; //nothing in here at this point in time

  cout << "Value of x " << x << endl;
  cout << "Address of variable: " << &x << endl;
  cout << "Address of y: " << &y << endl;

  //2. pal to "point" to x
  pal = &x; //pal now has addr of x. It is essentially "pointing" to x
  
  //3. going to get pal to go change value of x
  // let's say that wanted to add 10 to value of x
  *pal = *pal + 10; // x = x + 10

  //final act: let's go see x
  cout << "Value of x now: " << x << endl;

  return 0;
}