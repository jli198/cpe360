#include <iostream>
using namespace std;

class Chunk{
  public:
    int value;
    Chunk *next;

    Chunk() {
      value = -1;
      next = NULL;
    }
};

//Q of chunks
class Queue{
public:
  Chunk *head;

  Queue() {
    head = NULL;
  }

  //+
  void enqueue(int x) {
    Chunk *temp = new Chunk;
    temp-> value = x;

    if(head == NULL) {
      head = temp;
    }
    else {
      temp->next = head;
      head = temp;
    }
  }

  //-
  void dequeue() {
    Chunk *follow, *chase;

    if(head == NULL) {
      cout << "Empty Queue, nothing to delete" << endl;
    }
    else if(head->next == NULL) {
      cout << "Lone chunk, deleting " << head->value << endl;
      delete head;
      head = NULL;
    }
    else {
      follow = chase = head;
      while(chase->next != NULL) {
        follow = chase;
        chase = chase->next;
      }
      follow-> next = NULL;
      cout << "About to delete: " << chase->value << endl;
      delete chase;

    }
  }

  void display() {
    Chunk *temp;

    if(head == NULL) {
      cout << "Empty Queue" << endl;
    }
    else {
      temp = head;
      cout << "--------------" << endl;
      while(temp != NULL) {
        cout << temp->value << " ---> ";
        temp = temp->next;
      }
      cout << " NULL" << endl;
      cout << "--------------" << endl;
    }
  }
};

int main() {
  Queue Q;
  int choice, value;

  while(1) {
    cout << "Press 1 to enqueue" << endl;
    cout << "Press 2 to dequeue" << endl;
    cout << "Press 3 to display" << endl;
    cin >> choice;
    switch (choice) {
      case 1: cout << "Enqueue what?" << endl;
              cin >> value;
              Q.enqueue(value);
              break;

      case 2: Q.dequeue();
              break;

      case 3: Q.display();
              break;
              
      default: cout << "Goodbye!" << endl; 
               exit (1);
    }
  }

  Q.enqueue(20);
  Q.dequeue();
  Q.display();
}