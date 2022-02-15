#include <iostream>
using namespace std;

class chromeTab {
public:
  int length;
  int width;
  chromeTab *next;

  chromeTab() {
    length = 40;
    width = 20;
    next = NULL;
  }
};

int main() {
  //========
  // Creating and deleting chunks
  //========
  chromeTab *p;
  p = new chromeTab; //create new chunks
  delete p; //delete chunk 'p' is pointing to
            //VERY IMP: this only delets chunk, NOT p



  //1. Get pointer
  //2. Use that to get "new" tab from heap
  //3. Use that pointer to manipulate this nameless object
  chromeTab *ptr;
  ptr = new chromeTab;

  cout << "Just checking, L: " << ptr->length << ", w: " << ptr->width << endl;
  //change length to 80
  ptr->length = 80;
  ptr->width = 100;

  //I needed a new tab!?
  //pointer (1hs) = new chromeTab
  ptr->next = new chromeTab;
  ptr->next->length = 180;
  ptr->next->width = 200;

  //Third tab please!
  ptr->next->next = new chromeTab;
  //l = 200, w = 100
  ptr->next->next->length = 200;
  ptr->next->next->width = 100;

  //Fourth tab
  ptr->next->next->next = new chromeTab;
  //l = 10; w = 10
  ptr->next->next->next->length = 10;
  ptr->next->next->next->width = 10;

  // ptr = NULL;

  //I needed a new tab!?
  //new tab with L=180, W=200
  chromeTab *another;
  another = new chromeTab;

  another->length = 180;
  another->width = 200;
  cout << "Just checking, L: " << another->length << ", w: " << another->width
       << endl;

  

}