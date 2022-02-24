#include <iostream>
using namespace std;

class chunk{
public:
  int value;
  chunk *next;
  chunk *back;

  chunk() {
    value = -1;
    next = NULL;
  }
};

//PURPOSE of this lecture is to do three things well:
//1: Add chunk in front, middle and end
//2: Remove chunk from front, middle, and end
//3: Display values in train of chunks

int main() {
  //Phase-0 jumpstart: get three chunks that are knitted together
  //<pointer> = new <type>
  chunk *ptr, *temp;
  ptr = new chunk;
  ptr-> next = new chunk;
  ptr-> next-> next = new chunk;

  //Phase-1: let's add something new to front, middle, and end
  //front first
  temp = new chunk;
  ptr = temp;
  temp -> next = ptr; //1
  ptr = temp; //2

  //add to middle
  temp = new chunk;
  temp -> next = ptr->next->next; //1
  ptr-> next-> next = temp; //2

  //add to end
  temp = new chunk;
  ptr -> next -> next -> next -> next -> next = temp;

  //Phase-2: Now lets do opposite
  //Remove chunk from front, middle and end
  //grab addr of thing want to delete. Next isolate it (re-organize structure, and finally delete chunk)

  //remove from front
  temp = ptr; //1
  ptr = ptr-> next; //2
  delete temp; //this deletes whenever temp is pointing to

  //remove from middle
  temp = ptr-> next-> next; //1
  ptr-> next -> next = ptr->next-> next-> next; //2
  delete temp;

  //remove last chunk
  //temp = ptr->next->next->next;
  //ptr->next->next->next = NULL;
  //delete temp;
  delete ptr-> next-> next-> next;
  ptr-> next-> next-> next = NULL;
  //ptr->next->next = NULL;

  temp->next = ptr->next;
}