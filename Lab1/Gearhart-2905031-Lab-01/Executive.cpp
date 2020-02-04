/*@author Aaron Gearhart
@file Executive.cpp
@date 2/3/2020
@brief This file is the cpp file for the executive class.  Contains method definitions to let the user interact with the program

*/

#include <string>
#include <iostream>
#include "Executive.h"
#include <fstream>
#include <typeinfo>
#include <regex>
//cout << typeid(variable).name() << endl;



Executive::Executive(char* &data)
{
  int position = 0;
  std::ifstream myfile;
  myfile.open(data);
  int point = 0;
  size = 0;
  List = new LinkedList();
  while (!myfile.eof()) {
    myfile>>point;
    size++;
    if(myfile.eof()){
      break;
    }
    Node* ptr = new Node(point);



    List->addFront(ptr);





  }

}

int Executive::checkInput(std::string input){
    std::regex integer("[0-9]+");
    while (!regex_match(input, integer)) {
      std::cout << "Make a different choice ([0-9]+) : ";
      std::cin >> input;
    }

    return stoi(input);
}

void Executive::run(){

    std::string choice = "0";

    //menu
    int finalChoice = 0;
    while(finalChoice != 11)
    {std::cout << '\n' << '\n';
      std::cout << "===============================================================" << '\n';
    std::cout << "===============================================================" << '\n';
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
      int finalChoice = checkInput(choice);
      if (finalChoice == 1) {
        if (List->isEmpty()) {
          std::cout << "List is empty" << '\n';
        }
        else{
          std::cout << "List is not empty" << '\n';
        }

      }
      else if (finalChoice == 2)
      {
        std::cout << "The length is " << List->getLength() << '\n';
      }
      else if (finalChoice == 3)
      {
        std::string num = "0";
        std::cout << "Pick a number to be inserted: ";
        std::cin>>num;
        int num2 = checkInput(num);
        bool check = List->ptrToBool(List->find(num2));
        Node* ptr = new Node(num2);
        ptr->setFirst(check);
        List->addFront(ptr);
        std::cout << num2 << " was added to the list" << '\n';

      }
      else if (finalChoice == 4)
      {
        std::string num = "0";
        std::cout << "Pick a number to be Deleted: ";
        std::cin>>num;
        int num2 = checkInput(num);
        if (List->find(num2)) {
          List->removes(num2);
          std::cout << num2 << " has been removed" << '\n';
        }else{
          std::cout << "The number you typed in is not found" << '\n';
        }
      }
      else if (finalChoice == 5)
      {

        List->unique(List->getLength()-1);
        std::cout << "\nThe List is now full of unique numbers" << '\n';
      }
      else if (finalChoice == 6)
      {
        std::string num = "0";
        std::cout << '\n' << "Type in a number to find in the file: ";
        std::cin >> num;
        int num2 = checkInput(num);
        if (List->find(num2) != nullptr) {
          std::cout << num2 << " exists in the file" << '\n';
        }else{
          std::cout << num2 << " was not found" << '\n';
        }
      }
      else if (finalChoice == 7)
      {
        std::string num = "0";
        std::cout << '\n' << "Type in a number to find in the file: ";
        std::cin >> num;
        int num2 = checkInput(num);
        if(!List->find(num2)){
          std::cout<<num2 << " is not found"<< '\n';

        }
        else if(List->findNext(num2) != nullptr){
         std::cout<<List->findNext(num2)->getEntry() << " is after " << num2 << '\n';
        }
        else{
          std::cout<< "nullptr is after " << num2 << '\n';
        }

      }
      else if (finalChoice == 8)
      {
          List->printAll();
      }
      else if (finalChoice == 9)
      {
        std::cout << "\nList Printed in reverse" << '\n';
        List->printRev(List->getFront());
        std::cout << '\n';
      }
      else if (finalChoice == 10)
      {
        std::string pos = "0";
        std::cout << '\n' << "Type in a position to print the element: ";
        std::cin >> pos;
        int pos2 = checkInput(pos);
        List->printAt(pos2);
      }
      else if(finalChoice == 11){
        break;
      }
      else if (finalChoice >= 12)
      {
        std::cout << "\nMake another choice" << '\n';
      }

  }
}
