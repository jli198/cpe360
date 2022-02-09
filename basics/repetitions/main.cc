#include <iostream>
using namespace std;

int main() {
  // type name
  int x = 10;
  int i = 0;

  cout << "Give me x: " << endl;
  cin >> x;

  // for
  for (int i = 10; i > 3; i = i - 2) {
    cout << "Spam" << endl;
  }

  // while
  while (x > 0) {
    cout << "Keep repearing myself" << endl;
    cout << "new x?" << endl;
    cin >> x;
  }

  return 0;
