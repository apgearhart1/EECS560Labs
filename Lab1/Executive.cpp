/*@author Aaron Gearhart
@file Executive.cpp
@date 9/19/2018
@brief This file is the cpp file for the executive class.  Contains method definitions to let the user interact with the program

*/

#include <string>
#include <iostream>
#include "Executive.h"
#include <fstream>
#include <typeinfo>
//cout << typeid(variable).name() << endl;



Executive::Executive(char* &data)
{
  int position = 0;
  std::ifstream myfile;
  myfile.open(data);
  int point = 0;
  List = new LinkedList();
  while (!myfile.eof()) {
    myfile>>point;
    if(myfile.eof()){
      break;
    }

    bool check = List->ptrToBool(List->find(point));
    Node* ptr = new Node(point);
    ptr->setFirst(check);
    List->addFront(ptr);


  


  }

}





void Executive::run(){

    int choice = 0;

    //menu

    while(choice != 11)
    {
      std::cout << "\nChoose one operation from the options below" << '\n';
      std::cout << "1) isEmpty()" << '\n';
      std::cout << "2) Length" << '\n';
      std::cout << "3) Insert" << '\n';
      std::cout << "4) Delete" << '\n';
      std::cout << "5) Delete Duplicates" << '\n';
      std::cout << "6) Find" << '\n';
      std::cout << "7) Find Next" << '\n';
      std::cout << "8) Print" << '\n';
      std::cout << "9) Reverse List" << '\n';
      std::cout << "10) Print At" << '\n';
      std::cout << "11) Exit" << '\n';
      std::cout << "Make a choice: ";
      std::cin >> choice;

      if (choice == 1) {
        std::cout << List->isEmpty() << '\n';

      }
      else if (choice == 2)
      {
        std::cout << "The length is " << List->getLength() << '\n';
      }
      else if (choice == 3)
      {
        int num = 0;
        std::cout << "Pick a number to be inserted: ";
        std::cin>>num;
        bool check = List->ptrToBool(List->find(num));
        Node* ptr = new Node(num);
        ptr->setFirst(check);
        List->addFront(ptr);
        std::cout << num << " was added to the list" << '\n';

      }
      else if (choice == 4)
      {
        int num = 0;
        std::cout << "Pick a number to be Deleted: ";
        std::cin>>num;
        if (List->find(num)) {
          List->removes(num);
          std::cout << num << " has been removed" << '\n';
        }else{
          std::cout << "The number you typed in is not found" << '\n';
        }
      }
      else if (choice == 5)
      {

      }
      else if (choice == 6)
      {
        int num = 0;
        std::cout << '\n' << "Type in a number to find in the file: ";
        std::cin >> num;
        if (List->find(num) != nullptr) {
          std::cout << num << " exists in the file" << '\n';
        }else{
          std::cout << num << " was not found" << '\n';
        }
      }
      else if (choice == 7)
      {
        int num = 0;
        std::cout << '\n' << "Type in a number to find in the file: ";
        std::cin >> num;
        if(!List->find(num)){
          std::cout<<num << " is not found"<< '\n';

        }
        else if(List->findNext(num) != nullptr){
         std::cout<<List->findNext(num)->getEntry() << " is after " << num << '\n';
        }
        else{
          std::cout<< "nullptr is after " << num << '\n';
        }

      }
      else if (choice == 8)
      {
          List->printAll();
      }
      else if (choice == 9)
      {
        std::cout << "\nList Printed in reverse" << '\n';
        List->printRev(List->getFront());
        std::cout << '\n';
      }
      else if (choice == 10)
      {
        int pos = 0;
        std::cout << '\n' << "Type in a position to print the element: ";
        std::cin >> pos;
        List->printAt(pos);
      }
      else if (choice >= 12)
      {
        std::cout << "\nMake another choice" << '\n';
      }

  }
}
