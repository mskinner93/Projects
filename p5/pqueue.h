#ifndef PQUEUE_H
#define PQUEUE_H
#include"cust.h"
#include<iostream>
using namespace std;

class Pqueue
{
   public:
      Pqueue();
      ~Pqueue();
      Cust* dequeue();
      void enqueue(Cust* cust, int prio);
      bool empty();
      int length();//like the size
      int first_priority();//prints the first person in line

   private:
	class Node
	{
	   public:
	     Node(Cust *cust, int prio, Node *next)
	     {m_cust = cust; m_prio = prio; m_next = next;}
	     Cust *m_cust;
	     int m_prio;
	     Node *m_next;
	};
	Node* m_head;
	int m_size =0; 
};
#endif
   
