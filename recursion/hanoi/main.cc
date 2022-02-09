#include <iostream>
using namespace std;

/* 
(N-1) from S -> I
N from S -> D
(N-1) from I -> D
*/

void hanoi(int N, char S, char I, char D) {

    static int count = 0;

    //(I): Base case
    if(N ==1) {
        cout << "Move [" << ++count << "] " << N << " from " << S << " ---> " << D << '\n';
    }
    //(II): Drive N towards base case
    else {
        hanoi(N-1, S, D, I);
        cout << "Move [" << ++count << "] " << N << " from " << S << " ---> " << D << '\n';
        hanoi(N-1, I, S, D);
    } 

}

int main() {
    int N;
    char S = 'S', I = 'I', D = 'D';

    cout << "Give me # of discs: " << '\n';
    cin >> N;

    hanoi (N, S, I, D);

    return 0;
}