/*@author Aaron Gearhart
@file Executive.h
@date 9/19/2018
@brief This file is the header file for the executive class.  Contains method declarations for the user menu
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Node.h"
#include <string>
#include <iostream>
#include "LinkedList.h"


class Executive
{
public:
  //Executive();
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

private:
  //Node<T>* history;
  //void interact();
  int position;
  LinkedList* List;


};

#endif
