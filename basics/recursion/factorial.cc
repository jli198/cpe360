#include <iostream>
using namespace std;

//recursion
int fact(int N) {
    // I: Answer to simplest instance of problem
    // "Base case" or "anchor value"
    if(N == 1) {
        return 1;
    }
    // II: Reducing original instance towards base case
    // exploiting pattern that is inherent in problem
    else {
        return N* fact(N-1);
    }
}

// Main() N = 4 -> 4*fact(3)?? -> 3*fact(2)?? -> 2*fact(1)?? -> N == 1 then sends it back chain
int main() {
    int N = 1;
    cout << "Fact is: " << fact(N) <<endl;
}