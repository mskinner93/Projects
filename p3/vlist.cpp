// main.cpp
// Skinner, Mitch
// mskinner93
#include "vlist.h"
#include "video.h"
Vlist::Vlist()
{
   m_head = NULL;
}
Vlist::~Vlist()
{
  Node *ptr = m_head;
    while (ptr != NULL)
    {
	Node *temp;
	temp = ptr;
	ptr = ptr->m_next;
	delete temp;
    }
}

void Vlist::insert(Video *videos)
{
    if(m_head==NULL || m_head->m_video->get_title() > videos->get_title())
    {
	m_head = new Node(videos,m_head);
    }

    else
    {
   Node *ptr = m_head;
     while(ptr->m_next != NULL && videos->get_title() > ptr-> m_next->m_video->get_title())
	{
	   ptr = ptr->m_next;
	}
     ptr->m_next = new Node(videos,ptr->m_next); 
    	
    }
}




void Vlist::print()
{
   Node *ptr = m_head;
   while(ptr!=NULL)
     {
	ptr->m_video->print();
	ptr = ptr->m_next;
	
     }
}



Video* Vlist::lookup(string title)
{
 Node *ptr = m_head;
 while(ptr != NULL)
 {
   if(ptr->m_video->get_title() == title)
	{
	   return ptr->m_video;
	   
	}
	ptr = ptr->m_next;
 }
   
   return NULL;
}




bool Vlist::remove(string title)
{
   if(m_head == NULL)
   {
     return false;
   }

   if(m_head->m_video->get_title() == title)
   {
     Node *tmp = m_head;
     m_head = m_head ->m_next;
     delete tmp;
     return true;
   }
  Node *ptr = m_head;
     while(ptr->m_next != NULL&& ptr->m_next->m_video->get_title() != title)
      {
	ptr = ptr->m_next;
      }

   if(ptr->m_next == NULL)
      {
	return false;
      }

   Node *tmp = ptr->m_next;
   ptr->m_next = ptr->m_next->m_next;
   delete tmp;
   return true;
}


