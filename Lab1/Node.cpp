/*@author Aaron Gearhart
@file Node.cpp
@date 9/19/2018
@brief This file is the cpp file for the Node class.  Contains method definitions to manipulate each node.

*/

#include "Node.h"

Node::Node(){

  m_entry = 0;
  m_next = nullptr;
}


Node::Node(int entry){

  m_entry = entry;
  m_next = nullptr;
}


int Node::getEntry() const
{
  return m_entry;
}


Node* Node::getNext() const
{
  return m_next;
}



void Node::setEntry(int entry)
{
  m_entry = entry;
}


void Node::setNext(Node* next)
{
  m_next = next;
}
