#include"pqueue.h"
#include"cust.h"
Pqueue::Pqueue()
{
   m_head = NULL;
}

Pqueue::~Pqueue()
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

void Pqueue::enqueue(Cust* cust, int prio)
{
if (m_head == NULL || m_head->m_prio > prio)
 {
    m_head = new Node(cust, prio,m_head);
    m_size++;
 }

 else
 {
 Node *ptr = m_head;
  while(ptr->m_next!=NULL && ptr->m_next->m_prio<=prio)
  {
	ptr= ptr->m_next;
  } 

   ptr->m_next = new Node(cust, prio,ptr->m_next);
   m_size++;
 }
}

Cust* Pqueue::dequeue()
{
   if(m_head == NULL)
   {
     return NULL;
   }

   else
   {
     Node *temp = m_head;
     Cust *cust = m_head->m_cust;
     m_head = m_head->m_next;
     delete temp;
     m_size--;
     return cust;
   }
}

bool Pqueue::empty()
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

int Pqueue::length()
{
  return m_size;
}

int Pqueue::first_priority()
{
   if(m_head == NULL)
   {
      return -1;
   }

   else
   {
    return m_head->m_prio;
   }
}
