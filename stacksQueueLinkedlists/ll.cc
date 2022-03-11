#include <iostream>
using namespace std;

class Chunk {
public: 
  int value;
  Chunk *next;

  Chunk() {
    value = -1;
    next = NULL;
  }
};

class LL{
public:
  Chunk *head;
  int size;

  LL() {
    head = NULL;
    size = 0;
  }

  //1. Add: value + position
  void AddAtPos(int value, int pos) {
    if(pos <= size + 1) {
      Chunk *temp = new Chunk;
      temp->value = value;

      if(pos == 1) {
        //exactly like stack!
      }
      else{
      Chunk *help = head;
      for(int i = 1; i <= pos-1; i++)
        help = help->next;
      ///check all this!
      temp->next = help->next; //1
      help->next = temp;
      }
      size++;
      
    }
    else {
      cout << "Sorry, invalid position" << endl;
      return;
    }
  }
  //2. Remoe: position
  void removeFromPos(int pos) {
    
    if(pos <= size) {
      if (pos == size && size == 1) {
        //deleting lone chunk!
        delete head;
        head = NULL;
        size = 0;
      }
    
      if(pos == 1) {
        //exactly like stack!
      }
      else if(pos == size) {
        //like queue!
      }
      else {
        Chunk *chase, *follow;
        chase = follow = head;
        for(int i = 1; i <= pos; i++) {
          follow = chase;
          chase = chase->next;
        }
        follow-> next = chase-> next;
        delete chase;
      }
      size--;
    }
    else {

    }
  }
  //3. Display (ignore this today)
};