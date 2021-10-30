#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* next;
};

// we would like to declare the head node as global variable:
struct Node* head;

void Insert(int num){
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

int main() {
  head = NULL;
  int num, tempNum;
  cout << "How many numbers do you have?" << endl;
  cin >> num;
  for (int i = 0; i < num; i++){
    cout << "Please insert the " << i+1 << "th number. " << endl;
    cin >> tempNum;
    Insert(tempNum);
  }
  Print();
  return 0;
} 