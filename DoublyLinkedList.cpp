#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using std::ios;
using namespace std;

//Post-Condition: the list is created.
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = nullptr; //null head
  tail = nullptr; //null current position
}

//Pre-Condition: the list is created.
//Post-Condition: all nodes are freed
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  NodeType<T> *temp; //pointer to delete the node
  while(head != nullptr) {
    temp = head;
    head = head->next;
    delete temp;
  }
  tail = nullptr;
}

//Pre-Condition: the list exists.
//Post-Condition: items in the list are printed to standard output.
template <class T>
void DoublyLinkedList<T>::print() {
  NodeType<T> *temp; //pointer to traverse the list
  temp = head; //set current to point to the first node
  while(temp != nullptr) {
    cout << temp->data << " "; //output info
    temp = temp->next;
  }
  cout << endl;
}

//Pre-Condition: the list exists.
//Post-Condition: items in the list are printed to standard output in reverse order.
template <class T>
void DoublyLinkedList<T>::printReverse() {
  NodeType<T> *temp; //pointer to traverse the list
  temp = tail; //set current to point to the last node
  
  while(temp != nullptr) {

    cout << temp->data << " "; //output info
    temp = temp->back;
  }
}

//Pre-Condition: the list exists.
//Post-Condition: return the length instance variable.
template <class T>
int DoublyLinkedList<T>::lengthIs() const {
  NodeType<T> *temp = head; //temporary pointer
  int counter = 0;
  if(temp == nullptr) {
    return counter;
  }
  else{
    while(temp != nullptr) { //iterate
      counter++; //increment
      temp = temp->next; //next item
    }
    return counter;
  }
}

//Pre-Condition: the list exists and item is initialized
//Post-Condition: the item is inserted into the list, maintaining sorted order. If the
//item is already in the list, don’t insert the new item and print “Item already exists”
template <class T>
void DoublyLinkedList<T>::insertItem(T &item) {
  NodeType<T> *temp;
  NodeType<T> *node = new NodeType<T>;
  node->data = item;
  node->next = nullptr;
  node->back = nullptr;
  
  // if list is empty 
  if(head == NULL) {
    head = node;
    tail = node;  
  }
  //insert middle
  else if(head->data >= item) { 
    node->next = head; 
    node->next->back = node; 
    head = node; 
  }
  //insert end
  else { 
    temp = head; 
    while(temp->next != NULL && temp->next->data < node->data) {
      temp = temp->next; 
    }
    node->next = temp->next; 
    if (temp->next != NULL) {
      node->next->back = node; 
    }
    temp->next = node; 
    node->back = temp;
    tail = node;
  }
}

//Pre-Condition: the list exists and item is initialized.
//Post-Condition: the node that contains item is removed from the list. If the item is
//not present in the list, print the message that is shown in the example output
template <class T>
void DoublyLinkedList<T>::deleteItem(T &item) {

}

template <class T>
T DoublyLinkedList<T>::mode() {
  NodeType<T> *temp;
  NodeType<T> *modeNode;
  NodeType<T> *placeHolder;
  temp = head;
  placeHolder = head;
  int counter = 0;
  int mode = 0;
  int bigMode = 0;

  //iterate
  while (placeHolder->next != NULL) {

    temp = head;
    mode = 0;
    counter = 0;
    while (temp != NULL) {

      // get numb
      if (placeHolder->data == temp->data) {
	counter++;
	mode = counter;
      }      
      temp = temp->next; 		
    }
    if (bigMode < mode) {
      bigMode = mode;
      modeNode = placeHolder;
  }
  placeHolder = placeHolder->next;
}
  
  return modeNode->data;

}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
