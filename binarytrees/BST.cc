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
    //check to see if tree is empty
    //if it is, then make this value root of tree
    if(root == NULL) {
      root = new TreeChunk;
      root->value = key;
      return;
    }

    //if you are here, your tree is not empty
    //which means have to go 'searching' for this value (key)
    //if we fall off tree in process, we have found right position!
    TreeChunk *fast, *slow;
    fast = slow = root;

    while(fast != NULL) {
      slow = fast; // set this to fast and let fast go ahead (left or right)

      if(fast->value == key) {
        //duplicate
        cout << "Sorry, not adding duplicates" << endl;
        return;
      }
      else if(key < fast->value) {
        //go left
        fast = fast->left;
      }
      else {
        //go right
        fast = fast->right;
      }
    }

    //now check to see if fast is NULL
    //that's godo news: we have found spot to add 'key'
    //slow will have address of new 'parent' to be

    if(fast == NULL) {
      TreeChunk *temp = new TreeChunk;
      temp->value = key;

      if(key < slow->value) {
        slow->left = temp;
      }
      else
        slow->right = temp;
    }
  }

  //2. Search for value (key)
  void searchBST(int key, TreeChunk *start) {
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

  int minValTree(TreeChunk *start) {
    if(start == NULL) {
      return -1;
    }

    while(start->left != NULL)
      start = start->left;
    return start->value;
  }

  /*
  int maxValTree(TreeChunk *start) {
    if(start == NULL) {
      return -1;
    }
    while (start->right != NULL) {
      start = start->right;
    }
    return start-> value;
  }
  */

  //3. Delete value (key)
  void deleteNode(int key, TreeChunk *start) {
    if(start == NULL) {
      cout << "Can't find this value, will not delete" << endl;
      return;
    }
    //step 1: search for value!
    TreeChunk *slow, *fast;
    slow = fast = start;
    
    while(key != fast->value && fast != NULL) {
      slow = fast;
      if(key > fast->value)
        fast = fast-> right;
      else
        fast = fast->left;
    }
    if (fast == NULL) {
      cout << "This value does not exist. Not deleting" << endl;
      return;
    }
    if(key == fast->value) {
      //found it! Yay
      //so let's figure out what case are we dealing with

      //Case I: leaf node, no children
      if(fast->left == NULL && fast->right == NULL) {
        cout << "---------------" << endl;
        cout << "Case I delete" << endl;
        if(slow->left == fast) {
          slow->left = NULL;
          cout << "About to delete: " << fast->value << endl;
          delete fast; 
        }
        else {
          slow->right = NULL;
          cout << "About to delete: " << fast->value << endl;
          delete fast;
        }
      }
      //Case II: node with exactly one child
      else if(fast->left == NULL && fast->right != NULL) {
        cout << "-----------------" << endl;
        cout << "Case II delete" << endl;
        if(slow->left == fast) {
          slow-> left = fast->right;
        }
        //what is slow->right == fast?
        else {
          slow->right = fast -> right;
        }
        cout << "About to delete: " << fast->value << endl;
        delete fast;
      }
      else if(fast->left == NULL && fast->right == NULL) {
        cout << "=================" << endl;
        cout << "Case II delete" << endl;
        if(slow->left == fast) {
          slow->left = fast->left;
        }
        else {
          slow->right = fast->left;
        }
        cout << "About to delete: " << fast->value << endl;
        delete fast;
      }
      //Case III: node with two children
      else {
        cout << "--------------------------" << endl;
        cout << "Case III delete. Fun fun fun" << endl;

        //1. breathe
        //2. don't actually delete this node
        //3. we'll find value to swap with this node
        //4. minValueRightSubtree
        int swap = minValTree(fast->right); //swap = 35
        fast->value = swap; //not valid BST, but hey we swapped!
        deleteNode(swap, fast->right);
      }
    }
  }

  //4. Display contents: (a) in--, (b) pre--, (c) post-- order
  void inOrder(TreeChunk *start) {
    if(start == NULL) {
      return;
    }
    else {
      //left, root, right
      inOrder(start->left);
      cout << start->value << " " << endl;
      inOrder(start->right);
    }
  }

  void preOrder(TreeChunk *start) {
    if(start == NULL)
      return;
    else {
      cout << start->value << " " << endl;
      preOrder(start->left);
      preOrder(start->right);
    }
  }
  void postOrder(TreeChunk *start) {
    if(start==NULL)
      return;
    else {
      postOrder(start->left);
      postOrder(start->right);
      cout << start->value << " " << endl;
    }
  }

};

int main() {
  int choice, value;
  BST tree;
  //jumpstart tree with values (like in slides)
  //30, 15, 60, 7, 22, 45, 17, 27, 75, 100, 1, 40, 50, 35, 42, 48, 55, 65
  tree.addValue(30);
  tree.addValue(15);
  tree.addValue(60);
  tree.addValue(7);
  tree.addValue(22);
  tree.addValue(45);
  tree.addValue(17);
  tree.addValue(27);
  tree.addValue(75);
  tree.addValue(100);
  tree.addValue(1);
  tree.addValue(40);
  tree.addValue(50);
  tree.addValue(35);
  tree.addValue(42);
  tree.addValue(48);
  tree.addValue(55);
  tree.addValue(65);
  
  while(1) {
    cout << "Press 1 to add new value" << endl;
    cout << "Press 2 to search" << endl;
    cout << "Press 3 for in-order" << endl;
    cout << "Press 4 for pre-order" << endl;
    cout << "Press 5 for post-order" << endl;
    cout << "Press 6 for deleting node" << endl;
    cin >> choice;

    switch(choice) {
      case 1: cout << "What value did you want to add?" << endl;
              cin >> value;
              tree.addValue(value);
              break;

      case 2: cout << "Search for what?" << endl;
              cin >> value;
              tree.searchBST(value, tree.root);
              break;
      
      case 3: tree.inOrder(tree.root);
              break;
      
      case 4: tree.preOrder(tree.root);
              break;

      case 5: tree.postOrder(tree.root);
              break;
      
      case 6: cout << "Delete what?" << endl;
              cin >> value;
              tree.deleteNode(value, tree.root);
              break;

      default: cout << "Goodbye!" << endl;
              exit(1);
    }
  }
}