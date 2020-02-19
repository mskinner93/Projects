// dstack.cpp
// Skinner, Mitch
// mskinner93
#include <iostream>
using namespace std;
#include "dstack.h"

void Dstack::push(double value)
{
   m_head = new Node(value, m_head);
   m_size++;
}

bool Dstack::pop(double &value)
{
 if(m_head==NULL)
 {
   return false;
 }
 value = m_head->m_value;
 Node* temp = m_head;
 m_head = m_head->m_next;
 delete temp;
 m_size--;
 return true;
}

bool Dstack::empty()
{
 if(m_head == NULL)
 {
   return true;
 }

 else
 {
   return false;
 }
}
int Dstack::size()
{
 return m_size;
}

Dstack::~Dstack()
{
   Node *ptr = m_head;
    while(ptr != NULL)
    {
	Node *temp;
	temp = ptr;
	ptr = ptr->m_next;
	delete temp;
    }
}
