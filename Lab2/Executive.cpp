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
  std::ifstream myfile;
  myfile.open(data);
  std::string name = "0";
  int goals = 0;
  bucketSize = 7; //constant bucket size
  arr = new Node*[bucketSize];
  for (int i = 0; i < bucketSize; i++) {
    arr[i] = new Node();
  }
  myfile>>name;
  name = name.substr(0, name.size()-1);
  myfile>>goals;
  Node* ptr = new Node(name, goals);
  int newHash = goals % bucketSize;
  arr[newHash]->setNext(ptr);
  std::cout << arr[newHash]->getNext()->getEntry() << '\n';
  while(std::getline(myfile, name, ',')){
    myfile>>name;
    name = name.substr(0, name.size()-1);
    myfile>>goals;
    if(myfile.eof()){
      break;
    }

    Node* ptr = new Node(name, goals);
    int newHash = goals % bucketSize;
    if (arr[newHash]->getNext() == nullptr) {
      std::cout << "empty" << '\n';
      arr[newHash]->setNext(ptr);
      std::cout << arr[newHash]->getNext()->getEntry() << '\n';
    }else{
      while (arr[newHash]->getNext() != nullptr) {
        arr[newHash] = arr[newHash]->getNext();
      }
      arr[newHash]->setNext(ptr);
      std::cout << arr[newHash]->getNext()->getEntry() << '\n';
    }

    //List->addFront(ptr);

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

void Executive::addRecord(Node* ptr, int newHash){
  if (arr[newHash]->getNext() == nullptr) {
    std::cout << "empty" << '\n';
    arr[newHash]->setNext(ptr);
    std::cout << arr[newHash]->getNext()->getEntry() << '\n';
  }else{
    while (arr[newHash]->getNext() != nullptr) {
      arr[newHash] = arr[newHash]->getNext();
    }
    arr[newHash]->setNext(ptr);
    std::cout << arr[newHash]->getNext()->getEntry() << '\n';
  }

}

void Executive::printTable(){
  for (int i = 0; i < bucketSize; i++) {
    while (arr[i]->getNext() != nullptr) {
      std::cout << arr[i]->getNext()->getEntry() << " -> ";
      arr[i] = arr[i]->getNext();
    }
    std::cout << '\n';
  }

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
      std::cout << "1) Add Player" << '\n';
      std::cout << "2) Remove Player" << '\n';
      std::cout << "3) Print Player List" << '\n';
      std::cout << "4) Player With Goal Equal To..." << '\n';
      std::cout << "5) Player with Number of Goals Greater than..." << '\n';
      std::cout << "6) Player with Number of Goals Less than..." << '\n';
      std::cout << "7) Exit" << '\n';
      std::cout << "Make a choice: ";
      std::cin >> choice;
      int finalChoice = checkInput(choice);
      if (finalChoice == 1) {
        std::string name = "0";
        int goal = 0;
        std::cout << "===============================================================" << '\n';
        std::cout << "===============================================================" << '\n';
        std::cout << "Type in the name of the player you would like to enter: ";
        std::cin >> name;
        std::cout << '\n' << "Type in the number of the goals the above player has: ";
        std::cin >> goal;
        Node* ptr = new Node(name, goal);
        int newHash = goal % bucketSize;
        addRecord(ptr, newHash);

      }
      else if (finalChoice == 2)
      {

      }
      else if (finalChoice == 3)
      {

          printTable();
      }
      else if (finalChoice == 4)
      {

      }
      else if (finalChoice == 5)
      {


      }
      else if (finalChoice == 6)
      {

      }

      else if(finalChoice == 7){
        break;
      }
      else if (finalChoice >= 12)
      {
        std::cout << "\nMake another choice" << '\n';
      }

  }
}
