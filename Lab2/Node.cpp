/*@author Aaron Gearhart
@file Node.cpp
@date 9/19/2018
@brief This file is the cpp file for the Node class.  Contains method definitions to manipulate each node.

*/

#include "Node.h"

Node::Node(){

  m_entry = "0";
  m_next = nullptr;
  m_goal = 0;
}

Node::Node(std::string entry, int goal){

  m_entry = entry;
  m_next = nullptr;
  m_goal = goal;

}

int Node::getGoal() const{
  return m_goal;
}

void Node::setGoal(int goal){
  m_goal = goal;
}




std::string Node::getEntry() const
{
  return m_entry;
}


Node* Node::getNext() const
{
  return m_next;
}



void Node::setEntry(std::string entry)
{
  m_entry = entry;
}


void Node::setNext(Node* next)
{
  m_next = next;
}
