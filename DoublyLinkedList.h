#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

using namespace std;

template <class Type>
struct NodeType {  
  T data;
  NodeType<Type> *next;
  NodeType<Type> *back;  
};

template <class Type>
class DoublyLinkedList {
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  void insertItem(T &item);
  void deleteItem(T &item);
  int lengthIs() const;
  void print();
  void printReverse();
  //deleteSubsection
  //mode
  //swapAlternate
private:
  NodeType<T> *head;
  NodeType<T> *tail;
};

#endif
