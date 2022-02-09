#include <iostream> 
using namespace std;

//SIGNATURE:
// 1. What does it return (type)?
// 2. Name of function
// 3. Arguments: What does this function need to do what it does

void sayHello() {
    cout << "Saying hello" << endl;
}

void oddAndPrint(int x, int y) {
    int res = x + y;
    cout << "Here it is: " << res << endl;
    return;
}

int add(int x, int y) {
    return x + y;
}

int factorial(int N) {
    if(N < 0)
        return -1;
    else {
        int x = 1;
        for(int i = N; i > 0; i--)
            x *= i;
        return x;
    }
    
}
/* N! = N*(N-1)*...*1
-----------------
N! = N*(N-1)!
(N-1)! = (N-1) * (N-2)!
1! = 1 */


int main (){

    //type name
    int x;
    int y = 10;
    int z; 

    cout << "Give me x: " << endl;
    cin >> x;

    sayHello();
    sayHello();

    oddAndPrint(x, y);

    z = add(x,y);

    cout << "Returned this: " << z << endl;

    cout << "Adding 10 to 20, and then 30 to 40, and then, adding them all together: " << add(add(10,20), add(30,40)) << endl;  

    cout << factorial(5);
    
    return 0;

    

    
}