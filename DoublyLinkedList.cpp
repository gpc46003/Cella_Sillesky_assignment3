#include "DoublyLinkedList.h"

using std::ios;
using namespace std;

//Post-Condition: the list is created.
//Coded by: Eliza
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = nullptr; //null head
  tail = nullptr; //null current position
}

//Pre-Condition: the list is created.
//Post-Condition: all nodes are freed
//Coded by: Gian
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
//Coded by: Gian
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
//Coded by: Eliza
template <class T>
void DoublyLinkedList<T>::printReverse() {
  NodeType<T> *temp; //pointer to traverse the list
  temp = tail; //set current to point to the last node  
  while(temp != nullptr) {
    cout << temp->data << " "; //output info
    temp = temp->back;
  }
  cout << endl;
}

//Pre-Condition: the list exists.
//Post-Condition: return the length instance variable.
//Coded by: Gian
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
//Coded by: Eliza
template <class T>
void DoublyLinkedList<T>::insertItem(T &item) {
  NodeType<T> *temp;
  NodeType<T> *node = new NodeType<T>;
  node->data = item;
  //if list is empty 
  if(head == nullptr) {
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
    while(temp->next != nullptr && temp->next->data < node->data) {
      temp = temp->next; 
    }
    node->next = temp->next; 
    if (temp->next != nullptr) {
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
//Coded by: Gian
template <class T>
void DoublyLinkedList<T>::deleteItem(T &item) {
  NodeType<T> *temp = head;
  if(head == nullptr){ // if list is empty
    cout << "You cannot delete from an empty list" << endl;
    return;
  }
  if (head->data == item) { //delete first element
    head = head->next; //head = second element
    return;
  }
  while (temp != nullptr) {
    //find item to delete
    if (temp->data == item) {
      temp->back->next = temp->next; 
      delete temp;
      return;
    }
    temp = temp->next;
  }
  //no item to delete
  if (temp == nullptr) {
    cout << "Item not in list!" << endl;
  }   
}

//This function will return the mode for the current list. 
//You should NOT use any type of array to implement this function.
//Because the list is sorted, you should be able to find the mode without using an array.
//Coded by: Eliza
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
  while (placeHolder->next != nullptr) {
    temp = head;
    mode = 0;
    counter = 0;
    while (temp != nullptr) {
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

//This function will take input from the
//user for the lower and upper bound (both inclusive) for a range of values
//that you will delete from the list
//Coded by: Gian
template <class T>
void DoublyLinkedList<T>::deleteSub(T &lb, T &ub){
  NodeType<T> *lowerBound, *upperBound, *middleContent;
  if(head == nullptr || head->data > ub || tail->data < lb){ //do nothing
    return;
  }
  lowerBound = head;
  while(lowerBound != nullptr && lowerBound->data < lb){ //iterates until lb is found
    lowerBound = lowerBound->next;
  }
  if(lowerBound != nullptr){
    //first elements in list
    if(lowerBound->back == nullptr){
      head = head->next;
      head->back = nullptr;
      delete lowerBound;
      deleteSub(lb,ub); //repeat until none left
      return;
    }
    //last elements in list
    else if(lowerBound->next == nullptr){
      tail = tail->back;
      tail->next = nullptr;
      delete lowerBound;
      deleteSub(lb,ub); //repeat until none left
      return;
    }
    //only element in list
    else if(lowerBound->back == nullptr && lowerBound->next == nullptr){
      head = nullptr;
      tail = nullptr;
      delete lowerBound;
      return;
    }
    else{
      //middle elements
      upperBound = tail;
      while(upperBound != nullptr && upperBound->data > ub){ //iterates until ub is found
        upperBound = upperBound->back;
      }
      //upper bound and lower bound are the same
      if(upperBound->next == lowerBound){
        return;
      }
      else{
        lowerBound->back->next = upperBound->next;
        //delete all values between bounds
        while(lowerBound != upperBound){
          middleContent = lowerBound;
          lowerBound = lowerBound->next;
          delete middleContent; //remove middle sublist
        }
      }
      return;
    }
  }
}

//This function will swap every other node in the list. 
//For example: swaps nodes 1 and 2, nodes 3 and 4, nodes 5 and 6 etc
//Implement this function by changing pointers to nodes only. Do not
//copy the item type objects inside nodes and swap them to implement this function.
//Coded by: Eliza
void swapAlt() {   

}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
