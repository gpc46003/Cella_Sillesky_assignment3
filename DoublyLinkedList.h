#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <sstream>
#include <list>

using namespace std;

template <class T>
struct NodeType {  
  T data;
  NodeType<T> *next;
  NodeType<T> *back;  
};

template <class T>
class DoublyLinkedList {
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  void print();
  void printReverse();
  int lengthIs() const;
  void insertItem(T &item);
  void deleteItem(T &item);
  //void deleteSub();
  //T mode();
  //void swapAlt();
private:
  NodeType<T> *head;
  NodeType<T> *tail;
};
