#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* next;
};

int main() {
  struct Node* myNode;
  myNode = new struct Node;
  myNode->data = 3;
  myNode->next = NULL;
  cout << "the number inside my node is " << myNode->data << endl;

  // let us create a new node
  struct Node* temp = new struct Node;
  temp->data = 4;
  temp->next = NULL;

  myNode->next = temp;

  // now I want to insert a node at the beginning of the list:
  temp = new struct Node;
  temp->data = 2;
  temp->next = myNode;
  myNode = temp;
  
  // print the next node
  cout << "now we print all the nodes in the list " << endl;
  temp = myNode;
  while(temp != NULL){
    cout << temp->data << endl;
    temp = temp->next;
  }

}