/*@author Aaron Gearhart
@file Executive.h
@date 2/3/2020
@brief This file is the header file for the executive class.  Contains method declarations for the user menu
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Node.h"
#include <string>
#include <iostream>
//#include "LinkedList.h"


class Executive
{
public:
  /**
  * @pre input - string given by user
  * @post returns an integer version of the string given
  */
  int checkInput(std::string input);

  /**
  * @pre data is the text file argument
  * @post starts the program, reads in the file, and breaks down the contents of the file into different commands
  */
  Executive(char* &data);



  /**
  * @pre none
  * @post The user interface is run after the object is constructed
  * @param none
  */
  void run();

  /**
  * @pre none
  * @post Hashes and adds new record to the hashtable
  * @param ptr - pointer to node record
  */
  void addRecord(Node* ptr, int newHash);
  /**
  * @pre none
  * @post Prints the contents in the table
  * @param none
  */
  void printTable();


private:
  //Node<T>* history;
  //void interact
  //LinkedList* List
  int bucketSize;
  Node** arr;


};

#endif
