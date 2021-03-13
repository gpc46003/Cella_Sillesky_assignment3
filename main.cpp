#include "DoublyLinkedList.h"

using namespace std;
  string command;
  string line; //line from input text
  string token; //individual elements


template <class T>
void runCommands(DoublyLinkedList<T> list){
  do {     
    cout << "\nEnter a command: ";
    cin >> command;
    cout << endl;

    if(command == "q") {
      cout << "Quitting program...\n" << endl; 
      exit(1);        
    }
    else if(command == "i") { 
      T item;    
      cout << "Item to insert: ";
      cin >> item;
      cout << endl;
      list.insertItem(item); 
      list.print(); 
    }
    else if(command == "d") {  
      T item;    
      cout << "Item to delete: ";
      cin >> item;
      cout << endl;
      //list.deleteItem(); 
      list.print();   
    }
    else if(command == "l") { 
      cout << "The length is: " << list.lengthIs() << endl;  
    }
    else if(command == "p") {
      list.print();     
    }
    else if(command == "b") {
      int lb, ub; 
      cout << "Enter lower bound: ";
      cin >> lb;
      cout << endl;
      cout << "Enter upper bound: ";
      cin >> ub;
      cout << endl;
      cout << "Original List: ";
      list.print();
      //list.deleteSub();
      cout << "Modified List: ";       
      list.print();
    }
    else if(command == "m") { 
      list.print();
      cout << "Mode: " << list.mode() << endl;
    }
    else if(command == "r") {  
      list.printReverse();  
    }
    else if(command == "s") {
      cout << "Original List: ";
      list.print();
      //list.swapAlt();
      cout << "Swapped List: ";       
      list.print();  
    }
    else {
      cout << "Invalid command, try again!" << endl; //wrong command    
    }
  } 
  while(command != "q"); //repeat until user types 'q'
   
}


int main(int argc, char *argv[]) {
  
  DoublyLinkedList<std::string> stringList;
  DoublyLinkedList<int> intList;
  DoublyLinkedList<float> floatList;
  ifstream inputFile(argv[1], ios::in); 

  if(!inputFile){ //error if file not found 
    cout << "Failed to open the input file" << endl;
    exit(1);    
  } 
  else {      

    string listType;
    cout << "\nEnter list type (i - int, f - float, s - std::string): ";
    cin >> listType;
    cout << endl;
    cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m), printReverse (r), swapAlt (s), quit (q)" <<endl;   

    if(listType == "s" || listType == "i" || listType == "f") {

      if (listType == "s") {
	getline(inputFile, line); //converts file to string   
	istringstream iss(line);

	if(line != " ") { //if file not empty
	  while(getline(iss, token, ' ')){   
	    string item = token;
	  stringList.insertItem(item); //added to list
	  }
	}
	runCommands(stringList);
      }	
      
      else if (listType == "i") { //int
	getline(inputFile, line); //converts file to string   
	istringstream iss(line);

	if(line != " ") { //if file not empty     
	  while(getline(iss, token, ' ')){           
	    int item = stoi(token);
	    intList.insertItem(item); //added to list          
	  }
	}
	runCommands(intList);
      }

      else if (listType == "f") { //float
	getline(inputFile, line); //converts file to string   
	istringstream iss(line);

	if(line != " ") { //if file not empty
	  while(getline(iss, token, ' ')){   
	    float item = stof(token);
	    floatList.insertItem(item); //added to list
	  }
	}
	runCommands(floatList);
      }
    }
    else {
      cout << "Invalid Input" << endl;
      exit(1);
    }
  }
}
