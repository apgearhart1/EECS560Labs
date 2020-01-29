/*@author Aaron Gearhart
@file Node.h
@date 9/19/2018
@brief This file is the header file for the Node object.  Contains methods to manipulate the each node in the list.

*/


#ifndef NODE_H
#define NODE_H



class Node
{
private:

  int m_entry;
  Node* m_next;
  bool m_first;

public:
  /* @pre none
  * @post sets the m_first variable to true/false as needed
  * @param check - T/F variable to indicate the node is first or not
  * @throw none
  **/
  void setFirst(bool check);
  /* @pre none
  * @post Returns true/false if this node is first to enter in the list
  * @param none
  * @throw none
  **/
  bool isFirst() const;
  /* @pre none
  * @post Returns the value at the current position
  * @param none
  * @throw none
  **/
  int getEntry()const;
  /* @pre none
  * @post Returns the next object at the current position
  * @param none
  * @throw none
  **/
  Node* getNext()const;
  /* @pre entry is the website url
  * @post The current position is given an entry
  * @param entry is a templated variable, for the url
  * @throw none
  **/
  void setEntry(int entry);
  /* @pre next is the pointer to the next node in the list
  * @post The next object in chain from the current position is set
  * @param next is the pointer to the next object
  * @throw none
  **/
  void setNext(Node* next);
  /* @pre none
  * @post The default node object is created without a parameter
  * @param none
  * @throw none
  **/
  Node();
  /* @pre Entry is the website url
  * @post The Node object is created with an entry inside
  * @param Templated entry: the website url
  * @throw none
  **/
  Node(int entry);



};

#endif
