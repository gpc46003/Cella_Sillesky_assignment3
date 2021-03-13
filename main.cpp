#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char *argv[]) {
  
  string command;
  string line; //line from input text
  string token; //individual elements
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
    
    if(listType == "i") {  
     
      DoublyLinkedList<int> list;
      getline(inputFile, line); //converts file to string   
      istringstream iss(line);
            
      if(line != " ") { //if file not empty     
        while(getline(iss, token, ' ')){           
          int item = stoi(token);
          list.insertItem(item); //added to list          
        }
      } 
      do {     
	cout << "\nEnter a command: ";
	cin >> command;
	cout << endl;

	if(command == "q") { //exit safely
	  cout << "Quitting program...\n" << endl; 
	  exit(1);        
	}
	else if(command == "i") { 
	  int item;    
	  cout << "Item to insert: ";
	  cin >> item;
	  cout << endl;
	  list.insertItem(item); //insert reference
	  list.print(); 
	}
	else if(command == "d") {  
	  int item;    
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
	  //cout << "Mode: " << list.mode() << endl;
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
    else if(listType == "f") {

      DoublyLinkedList<float> list;
      getline(inputFile, line); //converts file to string   
      istringstream iss(line);

      if(line != " ") { //if file not empty
	while(getline(iss, token, ' ')){   
	  float item = stof(token);
	  list.insertItem(item); //added to list
	}
      }

      do {     
	cout << "\nEnter a command: ";
	cin >> command;
	cout << endl;

	if(command == "q") {
	  cout << "Quitting program...\n" << endl; 
	  exit(1);        
	}
	else if(command == "i") { 
	  float item;    
	  cout << "Item to insert: ";
	  cin >> item;
	  cout << endl;
	  list.insertItem(item); 
	  list.print(); 
	}
	else if(command == "d") {  
	  float item;    
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
	  //cout << "Mode: " << list.mode() << endl;
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
    else if(listType == "s") {

      DoublyLinkedList<std::string> list;
      getline(inputFile, line); //converts file to string   
      istringstream iss(line);

      if(line != " ") { //if file not empty
	while(getline(iss, token, ' ')){   
	  std::string item = token;
	  list.insertItem(item); //added to list
	}
      }

      do {     
	cout << "\nEnter a command: ";
	cin >> command;
	cout << endl;

	if(command == "q") {
	  cout << "Quitting program...\n" << endl; 
	  exit(1);        
	}
	else if(command == "i") { 
	  std::string item;    
	  cout << "Item to insert: ";
	  cin >> item;
	  cout << endl;
	  list.insertItem(item); 
	  list.print(); 
	}
	else if(command == "d") {  
	  std::string item;    
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
    else {
      cout << "Invalid Input" << endl;
      exit(1);
    }
  }
}
