// dstack.h
// Skinner, Mitch
// mskinner93
#ifndef DSTACK_H_
#define DSTACK_H_

class Dstack
{
   public:
     void push(double);
     bool pop(double &);
     bool empty();
     int size();
     ~Dstack();

   private:
     class Node
     {
	public:
           Node(double value,Node *next)
	   {m_value = value; m_next = next;}
	   double m_value;
	   Node *m_next;
     };
     Node* m_head = NULL;
     int m_size = 0;
};
#endif
