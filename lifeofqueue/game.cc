#include <iostream> //random function may not work on Linux machines; call <stdlib.h>
#include<stdlib.h> 
#include<time.h>
using namespace std;

class Customer {
public:
  int in_time;
  int out_time;
  int order_time;
};

class Queue {
public:
  Customer *head;
  Queue() {
  }

  void enqueue(int in_time, int order_time) {
    
  }

  void dequeue() {
  }
};

int main() {
  int TIME = 0, generator;
  int cumulative_time = 0;
  int customer_count = 0;
  //as many variables as need
  srand(time(NULL));
  
  // store hours, every minute of that day
  while(TIME < 1020) {
    //1. should add new customer to Q at this minute?
    if(TIME > 0 && TIME <= 120) {
      //8 am through 10 am
      generator = rand()%100 + 1;
      if(generator <= 30) {
        generator = rand()%6 + 1;
        cout << "New customer arrived at time: " << TIME << " with order time: " << generator << endl;
        //Q.enqueue(TIME, generator);
      }
    }
    //else if(all other time slots)

    //2. is customer going to place order this minute?
    
    //3. is customer ready to depart store at this minute?
    TIME++;
  }

}