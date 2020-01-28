/*@author Aaron Gearhart
@file LinkedList::.cpp
@date 9/19/2018
@brief This file is the cpp file for the linked list.  Contains method definitions to manipulate the list

*/

#include <stdexcept>

#include "LinkedList.h"


LinkedList::LinkedList()
{
  m_front = nullptr;
  //m_front = new Node<std::string>();
  m_length = 0;
  m_position = 0;

}


LinkedList::~LinkedList()
{
  clear();
}


bool LinkedList::isEmpty() const
{
  if(m_length < 1)
  {
    return true;
  }
  else
  {
    return false;
  }

}


int LinkedList::getLength() const
{
  return m_length;
}


void LinkedList::insert(int position, int entry) throw (std::runtime_error)
{
  Node* newNode = new Node(entry);
  if(m_length < 1)
  {
    throw std::runtime_error("The list is empty");
  }
  else if(position>m_length){
    throw std::runtime_error("Position is out of range");
  }
  else if(position == 1)
  {
    m_front = newNode;
    m_front->setNext(newNode);
    //m_front = newNode;
  }
  else if(position == m_length)
  {
    Node* temp = new Node(entry);
    m_front = temp;
    m_front->setNext(temp);

  }
  else{
    Node* prevPtr = getPtrAt(position-1);
    newNode->setNext(prevPtr->getNext());
    prevPtr->setNext(newNode);

  }
  m_length++;

}


void LinkedList::removes(int position) throw(std::runtime_error)
{
  Node* ptr = nullptr;
  if (position == 1) {
    ptr = m_front;
    m_front = m_front->getNext();
  }
  else{
    Node* prevPtr = getPtrAt(position-1);
    ptr = prevPtr->getNext();
    prevPtr->setNext(ptr->getNext());
  }
  ptr->setNext(nullptr);
  delete ptr;
  ptr = nullptr;
  m_length--;
}


void LinkedList::clear()
{
  Node* temp1 = m_front;
  Node* temp2 = m_front;

  int count = 1;
  while (count < m_length) {
    temp2 = temp1->getNext();
    delete temp1;
    temp1 = temp2;
    count++;
  }
  m_length = 0;
  m_front = nullptr;
}


int LinkedList::getEntry(int position) const throw(std::runtime_error)
{
  if(m_length < 1)
  {
    throw std::runtime_error("The list is empty");
  }

  else{
    Node* temp = m_front;
    for (int i = 0; i <= position-1; i++) {
      temp = temp->getNext();
    }
    int entry = temp->getEntry();
    return(entry);
  }
}


void LinkedList::replace(int position, int newEntry) throw(std::runtime_error)
{
  if(m_length < 1)
  {
    throw std::runtime_error("The list is empty");
  }
  else{
    Node* temp = m_front;
    for (int i = 1; i < position; i++) {
      temp = temp->getNext();
    }
    temp->setEntry(newEntry);
  }
}


void LinkedList::addBack(int entry) throw(std::runtime_error)
{
  //if(m_length < 1)
//  {
//    throw std::runtime_error("This list is empty");
//  }
//  else{

    if(m_length == 0)
    {
      Node* temp = new Node(entry);
      m_front = temp;
      m_front->setNext(temp);
      m_length++;

    }
    else{
      Node* temp = m_front;
      int count = 1;
      while (count < m_length) {
        temp = temp->getNext();
        count++;
      }
      Node* temp2 = new Node(entry);
      temp2->setNext(temp);
      m_length++;
    }


  //}
}


Node* LinkedList::getFront() const
{
  return m_front;
}


void LinkedList::setLength(int add)
{
  m_length = m_length + add;

}


int LinkedList::getNodeAt(int position)
{
  Node* currentPtr = m_front;
  for (int i = 1; i < position; i++) {
    currentPtr = currentPtr->getNext();
  }
  return(currentPtr->getEntry());
}


void LinkedList::setPosition(int position)
{
  m_position = position;
}


Node* LinkedList::getPtrAt(int position)
{
  Node* currentPtr = m_front;
  for (int i = 1; i < position; i++) {
    currentPtr = currentPtr->getNext();
  }
  return(currentPtr);
}
