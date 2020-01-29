/*@author Aaron Gearhart
@file LinkedList::.cpp
@date 9/19/2018
@brief This file is the cpp file for the linked list.  Contains method definitions to manipulate the list

*/

#include <stdexcept>
#include <iostream>
#include "LinkedList.h"


LinkedList::LinkedList()
{
  m_front = nullptr;
  m_length = 0;
  m_position = 0;

}


LinkedList::~LinkedList()
{
  clear();
}
bool LinkedList::ptrToBool(Node* node){
  if(node == nullptr){
    return true;
  }else{
    return false;
  }
}
void LinkedList::printAt(int pos){
  if (pos == 1) {
    std::cout << m_front->getEntry() << " is at position " << pos << '\n';
  }else if(pos > getLength()){
    std::cout << pos << " exceeds length of List" << '\n';
  }else{
    Node* temp = m_front;
    for (int i = 1; i <= pos; i++) {
      temp = temp->getNext();
    }
    std::cout << temp->getEntry() << " is at position " << pos << '\n';
  }
}

Node* LinkedList::findPrev(int point){
  if(m_front == nullptr){
    return nullptr;
  }else if(find(point)){
    Node* temp = m_front;
    while (temp != nullptr) {
      if (point == temp->getNext()->getEntry()) {
        return temp;
      }
      temp = temp->getNext();
    }
  }
  return nullptr;
}

Node* LinkedList::findNext(int point){
  return find(point)->getNext();
}

Node* LinkedList::find(int point){
  if(m_front == nullptr){
    return nullptr;
  }
  else if (point == m_front->getEntry()) {
    return m_front;
  }else{
    Node* temp = m_front;
    while (temp != nullptr) {
      if (point == temp->getEntry()) {
        return temp;
      }
      temp = temp->getNext();
    }
  }
  return nullptr;
}

void LinkedList::addFront(Node* node){
  if (m_front == nullptr) {
    m_front = node;
    m_front->setNext(nullptr);
  }else{
    Node* temp = node;
    temp->setNext(m_front);
    m_front = temp;

  }
  m_length++;

}

void LinkedList::printRev(Node* front){
  if (front == nullptr) {
    return;
  }else{
    printRev(front->getNext());
    std::cout << front->getEntry() << " ";
  }
}

void LinkedList::printAll(){
  if (getLength() ==1) {
    std::cout << m_front->getEntry() << '\n';
  }else{
    Node* temp = m_front;
    while(temp != nullptr) {
      std::cout << temp->getEntry() << ' ';
      temp = temp->getNext();
    }
  }
  std::cout << '\n';
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
  if(m_front == nullptr)
  {
    throw std::runtime_error("The list is empty");
  }
  else if(position>m_length){
    throw std::runtime_error("Position is out of range");
  }
  else if(position == 1)
  {

    newNode->setNext(m_front);
    m_front = newNode;

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


void LinkedList::removes(int value) throw(std::runtime_error)
{
  Node* ptr = nullptr;
  if (m_front->getEntry() == value && m_front->isFirst()) {
    ptr = m_front;
    m_front = m_front->getNext();
  }
  else{
    ptr = m_front;
    while (!ptr->isFirst() && value == ptr->getEntry()) {

    }
    Node* prevPtr = findPrev(value);
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
