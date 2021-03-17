Gian Cella
gpc46003@uga.edu
-deleteSub() experiences a segmentation fault when deleting the entire list but works properly with every other case.

Contribution:
*~DoublyLinkedList();
*void print();
*int lengthIs() const;
*void deleteSub(T &lb, T &ub);
*void deleteItem(T &item);
*Split main.cpp and DoublyLinkedList.h

Eliza Sillesky
Eliza.Sillesky@uga.edu

Contribution:
*T mode();
*void swapAlt();
*void printReverse();
*DoublyLinkedList();
*void insertItem(T &item);
*Split main.cpp and DoublyLinkedList.h



Instructions:
Cella_Sillesky_assignment3$ make (uses the makefile to create .o files)
Cella_Sillesky_assignment3$ ./main int-input.txt (converts the text file to a list of integers)
Cella_Sillesky_assignment3$ ./main empty.txt (converts the text file to empty list)
Cella_Sillesky_assignment3$ ./main float-input.txt (converts the text file to a list of floating point numbers)
Cella_Sillesky_assignment3$ ./main string-input.txt (converts the text file to a list of std::strings)
Cella_Sillesky_assignment3$ make clean (removes .o files and main executable)



deleteSubsection Function:

void DoublyLinkedList<T>::deleteSub(T &lb, T &ub){
  NodeType<T> *lowerBound, *upperBound, *middleContent;
  if(head == nullptr || head->data > ub || tail->data < lb){
    return;  <--------------------------------------------------------- 1
  }
  lowerBound = head;  <------------------------------------------------ 1
  while(lowerBound != nullptr && lowerBound->data < lb){  <------------ n
    lowerBound = lowerBound->next; <----------------------------------- 1
  }
  if(lowerBound != nullptr){
    if(lowerBound->back == nullptr){
      head = head->next;  <-------------------------------------------- 1
      head->back = nullptr;  <----------------------------------------- 1
      delete lowerBound;  <-------------------------------------------- 1
      deleteSub(lb,ub);  <--------------------------------------------- n
      return; <-------------------------------------------------------- 1
    }
    else if(lowerBound->next == nullptr){
      tail = tail->back;  <-------------------------------------------- 1
      tail->next = nullptr;  <----------------------------------------- 1
      delete lowerBound;  <-------------------------------------------- 1
      deleteSub(lb,ub);  <--------------------------------------------- n
      return;  <------------------------------------------------------- 1
    }
    else if(lowerBound->back == nullptr && lowerBound->next == nullptr){
      head = nullptr;  <----------------------------------------------- 1
      tail = nullptr;  <----------------------------------------------- 1
      delete lowerBound;  <-------------------------------------------- 1
      return;  <------------------------------------------------------- 1
    }
    else{
      upperBound = tail;  <-------------------------------------------- 1
      while(upperBound != nullptr && upperBound->data > ub){  <-------- n
        upperBound = upperBound->back;  <------------------------------ 1
      }
      if(upperBound->next == lowerBound){
        return;  <----------------------------------------------------- 1
      }
      else{
        lowerBound->back->next = upperBound->next;  <------------------ 1
        while(lowerBound != upperBound){ <----------------------------- n
          middleContent = lowerBound;  <------------------------------- 1
          lowerBound = lowerBound->next;  <---------------------------- 1
          delete middleContent;  <------------------------------------- 1
        }
      }
      return;  <------------------------------------------------------- 1
    }
  }
}

Time Complexity: 
1+1+n+1+1+1+n+1+1+1+1+n+1+1+1+1+1+1+n+1+1+n(1+1+1)+1
=18+7n
Big-O (Worst Case):
If complexity is a polynomial, variable with highest exponent is the worst case scenario.
Notation would be O(n) which takes into account having to iterate through whole list.
There are a few minor while loops that are not nested but provide a single dimension.
The rest are if-else statements that do not change the complexity of the code.
Function deleteSub() was called recursively as well and is of n complexity.
Improvements:
Using Linear Search instead of Binary Searchc could increase the growth rate.
Instead of calling the function recursively use nested for or while loops.
Use 2 Node pointers instead of 3 would minimize memory usage.



mode Function:

T DoublyLinkedList<T>::mode() {
  NodeType<T> *temp;
  NodeType<T> *modeNode;
  NodeType<T> *placeHolder;
  temp = head;  <----------------------------------- 1
  placeHolder = head;  <---------------------------- 1
  int counter = 0;  <------------------------------- 1
  int mode = 0;  <---------------------------------- 1
  int bigMode = 0;  <------------------------------- 1

  while (placeHolder->next != nullptr) {  <--------- n
    temp = head;  <--------------------------------- 1
    mode = 0;  <------------------------------------ 1
    counter = 0;  <--------------------------------- 1
    while (temp != nullptr) {  <-------------------- n
      if (placeHolder->data == temp->data) {
	      counter++;  <------------------------- 1
	      mode = counter; <--------------------- 1
      }      
      temp = temp->next;  <------------------------- 1	
    }
    if (bigMode < mode) {
      bigMode = mode;  <---------------------------- 1
      modeNode = placeHolder;  <-------------------- 1
    }
    placeHolder = placeHolder->next; <-------------- 1
  }
  return modeNode->data;  <------------------------- 1
}

Time Complexity: 
1+1+1+1+1+n(1+1+1+n(1+1+1)+1+1+1)+1
=6+n(1+1+1+n+n+n+1+1+1)
=6+n+n+n+n^2+n^2+n^2+n+n+n
=3n^2+6n+6
Big-O (Worst Case):
If complexity is a polynomial, variable with highest exponent is the worst case scenario.
Notation would be O(n^2) which takes into account having to iterate through whole list.
Improvements:
Using Binary Search can improve the complexity instead of Linear Search.
Starting from tail instead of head could also alter the results.



swapAlternative Function:

void DoublyLinkedList<T>::swapAlt() {   
 NodeType<T> *temp = head->next;
  NodeType<T> *tempHead;

  if (head == nullptr || head->next == nullptr ) { <------------------------- 1
    return;  <---------------------------------------------------- 1        
  }                   
  //insert beginning                                                               
  if (lengthIs() < 3) {   <--------------------------------------- 1

    head->back = temp;    <------------------------------------- 1
    head->next = temp->next; <-------------------------------------1
    temp->next = head; <------------------------------------- 1
    temp->back = nullptr; <------------------------------------- 1
    tempHead = head; <------------------------------------- 1
    head = temp; <------------------------------------- 1
    temp = tempHead; <------------------------------------- 1


  } else { <------------------------------------- 1

    head->back = temp; <------------------------------------- 1
    head->next = temp->next; <------------------------------------- 1
    temp->next = head; <------------------------------------- 1

    head->next->back = head; <------------------------------------- 1
    temp->back = nullptr; <------------------------------------- 1

    tempHead = head; <------------------------------------- 1

    head = temp; <------------------------------------- 1
    temp = tempHead; <------------------------------------- 1

    temp = temp->next->next; <------------------------------------- 1

    // 4 in list              
	  if (lengthIs() % 2 == 0 && temp->next == NULL) { <------------------------------------- 1
      NodeType<T> *tempTail = tail->back; 
      cout << "" << endl;
      tail->next = tempTail; <------------------------------------- 1

      tail->back = tempTail->back; <------------------------------------- 1

      tempTail->back = tail; <------------------------------------- 1

      tempTail->next = nullptr; <------------------------------------- 1

      tail->back->next = tail; <------------------------------------- 1

      tail = tail->next; <------------------------------------- 1

      temp = nullptr; <------------------------------------- 1
    } else {  <------------------------------------- 1

      while (temp != nullptr) { <------------------------------------- n

        //middle 
	      temp->next->back = temp->back; <------------------------------------- 1
        temp->back->next = temp->next; <------------------------------------- 1
        temp->next = temp->back; <------------------------------------- 1


        temp->back = temp->back->back; <------------------------------------- 1
        temp->back->next = temp; <------------------------------------- 1
        temp->next->back = temp; <------------------------------------- 1

        temp = temp->next->next->next; <------------------------------------- 1

        //back of list if list is even                                              
        if (lengthIs() % 2 == 0 && temp->next == NULL) { <------------------------------------- 1
          NodeType<T> *tempTail = tail->back; <------------------------------------- 1

          tail->next = tempTail; <------------------------------------- 1

          tail->back = tempTail->back; <------------------------------------- 1

          tempTail->back = tail; <------------------------------------- 1
		tempTail->next = nullptr; <------------------------------------- 1

          tail->back->next = tail; <------------------------------------- 1

          tail = tail->next; <------------------------------------- 1

          temp = nullptr; <------------------------------------- 1
        }

      }
    }
  }

Time complexity:  1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 +n(1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1)
= 16n + 49
Big-O (Worst Case):
If complexity is a polynomial, variable with highest exponent is the worst case scenario.
Notation would be O(n) which takes into account having to iterate through whole list.

Improvements: Instead of having two of the same if statements to handle the swap at the end of the list, reduce it to one.
