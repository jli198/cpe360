#include <iostream>
using namespace std;

class TreeChunk {
public:
  int value;
  TreeChunk *left;
  TreeChunk *right;

  TreeChunk() {
    value = 0;
    left = right = NULL;
  }
};

class BST{
public:
  TreeChunk *root;

  BST() {
    root = NULL;
  }

  //1. Add values
  void addValue(int key) {

  }
  //2. Search for value (key)
  void searchBST(int key, TreeChunk *start) { // NOT TreeNode
    if(start == NULL) {
      cout << "Value not found in this tree" << endl;
    }
    else {
      if(key == start->value) {
        cout << "Yes! Found it!!" << endl;
      }
      else if(key > start->value) {
        searchBST(key, start->right);
      }
      else {
        searchBST(key, start->left);
      }
    }
  }

  //3. Delete value (key)


  //4. Display contents: (a) in--, (b) pre--, (c) post-- order
};

int main() {
  BST tree;
}