#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* next;
};

// we would like to declare the head node as global variable:
struct Node* head;

void InsertEnd(int num){
  // now we create a temp node for insertion:
  struct Node* tempNode = new struct Node;
  tempNode->data = num;
  tempNode->next = NULL;

  // verify if we are inserting to the empty list:
  if(head == NULL){
    head = tempNode;
    return;
  }

  // we want to get to the end of the list from the begining:
  struct Node* end = head;
  while(end->next!=NULL){
    end = end->next;
  }

  // point the last node to the newly created node:
  end->next = tempNode;
  tempNode = NULL;

  return;
};

void InsertFront(int num){
  // create a new node:
  struct Node* tempNode = new struct Node;
  tempNode->data = num;
  tempNode->next = NULL;

  // it really doesn't matter if the current list is empty...
  if(head!=NULL) tempNode->next = head;
  head = tempNode;
  tempNode = NULL;

  return;
}

void InsertPosition(int num, int position){
  // Insert node in between node -- list can not be empty
  // create a new temp node:
  struct Node* tempNode = new struct Node;
  tempNode->data = num;
  tempNode->next = NULL;

  // we have to travel through the list and insert the node:
  struct Node* current = head;
  for(int i = 0; i< position - 2; i++){
    current = current->next;
    cout << "Hello" << endl;

    // if we are out of range, return
    if(current == NULL){
      cout << "the insert position is invalid" << endl;
      return;
    }
  }

  if(position == 1){
    tempNode->next = current;
    head = tempNode;

  } 
  else{
    tempNode->next = current->next;
    current->next = tempNode;
  }
  tempNode = NULL;

  return;
};

void Print(){
  struct Node* current = head;
    cout << endl << "Now printing the list" << endl;
  while(current->next!=NULL){
    cout << current->data << "->";
    current = current->next;
  }
  cout << current->data << endl;
  return;
};

void DeleteNode(int position){
  struct Node* current = head;
  // if head node is to be deleted:
  if (position == 1){
    if (current->next == NULL){
      delete current;
      cout << "the list is now empty" << endl;
      return;
    }
    head = head->next;
    delete current;
    
    return;
  }
  // if 2nd node is to be deleted:
  if (position == 2){
    if (current->next == NULL){
      cout << "invalid position" << endl;
      return;
    }
    cout << "current->next->next is " << current->next->next->data;
    current->next = current->next->next;
    
    // move to the target node:
    // delete current->next;
    // delete current;

    return;
  }

  // if 3rd+ position is to be deleted:
  for (int i = 0; i < position - 2; i++){
    if (current == NULL){
      cout << "invalid position" << endl;
      return;
    }
    current = current->next;
  }
  if (current->next == NULL){
    cout << "invalid position" << endl;
    return;
  }
  current->next = current->next->next;
  
  // move to the target position:
  current = current->next;
  delete current;

  return;
};

int main() {
  head = NULL;
  int num, tempNum, deletePosition;
  cout << "How many numbers do you have?" << endl;
  cin >> num;
  for (int i = 0; i < num; i++){
    cout << "Please insert the " << i+1 << "th number. " << endl;
    cin >> tempNum;
    InsertFront(tempNum);
  }
  Print();

  // now I would like to insert "3" in the 3rd position
  InsertPosition(4, 1);
  Print();

  // now we want to ask user which node to delete:
  cout << "please enter a position that you want to delete: " << endl;
  cin >> deletePosition;
  DeleteNode(deletePosition); 
  Print();
  return 0;
} 