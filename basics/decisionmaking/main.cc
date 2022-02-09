#include <iostream>
using namespace std;

int main() {
    //type name
    int x = 10;

    cout << "Give me x: " << endl;
    cin >> x;

    if(x > 10) {
        cout << "Its more than 10" << endl;
    }
    else if( x >= 10 && x <= 20) {
        cout << "It's between 10 and 20" << endl;
    }
    else {
        cout << "Definitely more than 20" << endl;
    }

    return 0;
}