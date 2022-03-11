#include <iostream>
using namespace std;

// 1. Concept "chunk"
class Chunk {
public:
  int value;
  Chunk *next;
  
  Chunk() {
    value = -1;
    next = NULL;
  }

};

// 2. Class called "Stack"
// stack of chunks
// member functions to add, delete and display
class Stack {
public:
  Chunk *top;

  Stack() {
    top = NULL;
  }

  // 1. add: Push: adds new element to Stack
  void push(int x) {
    // step 1: go get us new chunk and put 'x' inside value portion
    Chunk *temp = new Chunk;
    temp->value = x;

    // step 2: to amke this new chunk "first" chunk
    // if stack is empty, make this first chunk. Else, move some pointers
    if(top == NULL) {
      top = temp; // that's it!
    }
    else {
      temp->next = top;
      top = temp;
    }

    /* if( top != NULL) {
      temp -> next = top;
    }
    top = temp */

    cout << "Just added new element: " << top -> value << endl;
  }

  // 2. delete: Pop: removes element (if any) from Stack
  void pop() {
    // step 1: check to see if stack is empty. If yes, nothing to do here.
    // step 2: if it's not empty, just get rid of first chunk
    if(top == NULL) {
      cout << "Nothing to delete. Empty stack. " << endl;
    }
    else {
      Chunk *temp;
      temp = top;
      top = top->next;
      cout << "About to delete: " << temp->value << endl;
      delete temp;
    }
  }
  // 3. display: displays content of Stack
  void display() {
    Chunk *temp;
    temp = top;
    if (top == NULL) {
      cout << "-----" << endl;
      cout << "Empty stack, nothing to display!" << endl;
      cout << "-----" << endl;
      return;
    }

    cout << "-------------------" << endl;
    while(temp != NULL) {
      cout << temp->value << " --> ";
      temp = temp->next;
    }
    cout << " NULL" << endl;
    cout << "-------------------" << endl;
  }
};

int main() {
  Stack S;
  int choice, value;

  while(1) {
    cout << "Press 1 to push to stack" << endl;
    cout << "Press 2 to pop from stack" << endl;
    cout << "Press 3 to display contents" << endl;
    cout << "Anything else to quit" << endl;
    cin >> choice;

    switch (choice) {
      case 1: cout << "Push what" << endl;
              cin >> value;
              S.push(value);
              break;

      case 2: S.pop();
              break;

      case 3: S.display();
              break;

      default: cout << "Goodbye!" << endl;
               exit(1);
    }
  }

}