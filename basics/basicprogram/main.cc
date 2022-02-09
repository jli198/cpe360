#include <iostream>
using namespace std;

int main() {
    //type name
    int x = 10;
    float pi = 3.14; 
    cout << "Saying hello" << endl;

    cout << "Give me number: " << endl;
    cin >> x;

    x = x + 10;

    cout << "Added 10 to that number, and it looks like: " << x << endl;

    return 0;

}