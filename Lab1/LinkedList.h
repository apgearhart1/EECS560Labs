/*@author Aaron Gearhart
@file LinkedList.h
@date 9/19/2018
@brief This file is the header file for the linked list.  Contains methods to manipulate the list

*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

#include <stdexcept>
#include <string>


class LinkedList
{
private:
  Node* m_front;
  int m_length = 0;
  int m_position;

public:
  /* @pre none
  * @post The LinkedList object is created
  * @param none
  * @throw none
  **/
  LinkedList();
  /* @pre none
  * @post The clear function is called
  * @param none
  * @throw none
  **/
  ~LinkedList();
  /* @pre none
  * @post prints at a given position
  * @param pos - position of list to be printed
  * @throw none
  **/
  void printAt(int pos);
  /* @pre none
  * @post checks to see if an integer exists and then returns the next pointer
  * @param point - integer from file
  * @throw none
  **/
  Node* findNext(int num);
  /* @pre none
  * @post checks to see if an integer exists and returns that pointer
  * @param point - integer from file
  * @throw none
  **/
  Node* find(int point);
  /* @pre none
  * @post Adds a node to the front of the LinkedList
  * @param point - integer from file
  * @throw none
  **/
  void addFront(int point);
  /* @pre none
  * @post prints all the elements in reverse order
  * @param none
  * @throw none
  **/
  void printRev();
  /* @pre none
  * @post prints all the elements in a row
  * @param none
  * @throw none
  **/
  void printAll();
  /* @pre none
  * @post checks to see if the list is empty and returns true or false
  * @param none
  * @throw none
  **/
  bool isEmpty() const;
  /* @pre none
  * @post The list length is returned
  * @param none
  **/
  int getLength() const;
  /* @pre The position is between 1 and the list's length
  * @post A new object is created and the entry at the given position is inserted
  * @param position:  1<= position <= length
  * @param entry: A new entry to put in the list
  * @throw std::runtime_error if the position is invalid.
  **/
  void insert(int position, int entry) throw (std::runtime_error);
  /* @pre The position is between 1 and the list's length
  * @post A node at the given position is removed
  * @param position:  1<= position <= length
  * @throw std::runtime_error if the position is invalid.
  **/
  void removes(int position) throw (std::runtime_error);

  /* @post The entire list is cleared out
  * @param none
  * @throw none
  **/
  void clear();

  /* @pre The position is between 1 and the list's length
  * @post The entry at the given position is returned
  * @param position:  1<= position <= length
  * @throw std::runtime_error if the position is invalid.
  **/
  int getEntry(int position) const throw (std::runtime_error);

  /* @pre The position is between 1 and the list's length
  * @post The entry at the given position is replaced with the new entry
  * @param position:  1<= position <= length
  * @param newEntry: A new entry to put in the list
  * @throw std::runtime_error if the position is invalid.
  **/
  void replace(int position, int newEntry) throw (std::runtime_error);
  /* @pre The string is url that the user will navigate to
  * @post The entry at the given position is replaced with the new entry
  * @param position:  1<= position <= length
  * @param newEntry: A new entry to put in the list
  * @throw std::runtime_error if the position is invalid.
  **/
  void addBack(int entry) throw (std::runtime_error);
  /* @pre none
  * @post The front pointer is returned
  * @param none
  **/
  Node* getFront() const;
  /* @pre var add can be any number
  * @post sets the length of the list by passing in an integer
  * @param add - integer being added to the overall length
  **/
  void setLength(int add);
  /* @pre var position is the current position that the node is
  * @post returns the entry at the requested position
  * @param position - current position that the node is at
  * @return entry at the position
  **/
  int getNodeAt(int position);
  /* @pre position
  * @post sets the current position from Chrome.h
  * @param position - current position that the node is at
  * @return none
  **/
  void setPosition(int position);
  /* @pre var position is the current position that the node is
  * @post returns the entry at the requested position
  * @param position - current position that the node is at
  * @return pointer at the position
  **/
  Node* getPtrAt(int position);




};

#endif
