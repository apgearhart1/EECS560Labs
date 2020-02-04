/*@author Aaron Gearhart
@file Node.h
@date 9/19/2018
@brief This file is the header file for the Node object.  Contains methods to manipulate the each node in the list.

*/


#ifndef NODE_H
#define NODE_H
#include <string>

class Node
{
private:

  std::string m_entry;
  int m_goal;
  Node* m_next;

public:
  /* @pre none
  * @post Returns the value of goals
  * @param none
  * @throw none
  **/
  int getGoal()const;
  /* @pre entry is the website url
  * @post The current position is given an entry
  * @param entry is a templated variable, for the url
  * @throw none
  **/
  void setGoal(int entry);
  /* @pre none
  * @post Returns the value at the current position
  * @param none
  * @throw none
  **/
  std::string getEntry()const;
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
  void setEntry(std::string entry);
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
  /* @pre none
  * @post The Node object is created with an entry inside
  * @param entry - name of player
  * @param goal - how many goals the player has
  * @throw none
  **/
  Node(std::string entry, int goal);



};

#endif
