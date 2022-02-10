#include <iostream>
using namespace std;

//Amazon

//item: images (s), price, avail, seller, star, reviews, q&a
//cart: items, price, quantities
//account: name, CC ,addr, phone, email, isPrime ...

//Template for data. Factory
class item {
public:
  //Attributes: physical look and feel of this abstract data
  float price;
  float ratings;
  //Constructor: First time this item is created, what is default attribute?
  item() { 
    price = 10.00;
    ratings = 0.0;
  }
  //functions: what functions does this abstract type perform?
  void addToCart() { 
    cout << "Added to cart" << '\n'; 
  }

  void updatePrice(float newPrice) { 
    price = newPrice; 
  }

  void updateRatings(float newRating) { 
    ratings = newRating;
  
  }
};

int main() {
  //type name
  int x;
  item item1, item2; //10^6

  //pointers
  int *ptr;
  item *item_ptr;

  //pointer meet data
  ptr = &x;
  item_ptr = &item1;

  // =============================
  // A P P  S P A C E
  // =============================

  //dot operator
  cout << "Price of item1: " << item1.price << endl;
  cout << "Rating of item1: " << item1.ratings << endl;

  item1.addToCart();
  item1.updatePrice(12.50);
  item1.updateRatings(5.0);

  cout << "New price: " << item1.price << endl;
  cout << "New rating: " << item1.ratings << endl;

  // ==========================
  // HEAP
  // ==========================

  //1 have pointer
  //2 use pointer to get yourself "chunk" from heap
  //3 make sure don't lose address from here on!
  item *iptr;
  iptr = new item;
  cout << "Just created something in heap! Yay!!" << endl;
  cout << "Price: " << iptr->price << ", ratings: " << iptr->ratings << endl;
  iptr->price = 14.0;
  iptr->ratings = 4.9;
  cout << "New price: " << iptr->price << ", ratings: " << iptr->ratings << endl;
}