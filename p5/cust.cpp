#include <iostream>
#include "cust.h"
#include "assert.h"
using namespace std;

Cust::Cust(string name, bool robber, int atime, int items)
{
	m_name = name;
	m_robber = robber;
	m_atime = atime;
	m_items = items;
}

bool Cust::is_robber()
{
  if(m_robber == true)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int Cust::get_time()
{
   return m_atime;
}

int Cust::get_items()
{
   return m_items;
}



void Cust::print(ostream &os)
{

   os<<m_name<<" " <<(m_robber ? "robber" : "shopper")<< " "<<m_atime<< " "<<m_items<<endl;
}



void Cust::print_entered(ostream &os, int clock)
{
  //assert(clock == m_atime);
  os << clock << ": " << m_name << " entered store" << endl;
}

void Cust::print_done_shopping(ostream &os, int clock)
{
  os << clock << ": " <<  m_name << " done shopping" << endl;
}

void Cust::print_started_checkout(ostream &os, int clock,int i)
{ 
  os << clock << ": " << m_name << " started checkout with checker "<< i <<endl;
}



void Cust::print_checker_robbed(ostream &os, int clock, int i, int amount_stolen)
{
  if(m_items == 1)
    {
       os <<clock << ": " << m_name << " stole $"<<amount_stolen<< " and "<<m_items<< " item from checker "<<i<<endl;
    }
  else
    {
       os <<clock << ": " << m_name << " stole $"<<amount_stolen<< " and "<<m_items<< " items from checker "<<i<<endl;
   }
}



void Cust::print_done_checkout(ostream &os, int clock, int i)
{
  if(m_items == 1)
   {
	os <<clock << ": " << m_name << " paid $"<<m_items*2<< " for " <<m_items<< " item to checker "<<i<<endl;
   }
   else
    {
        os <<clock << ": " << m_name << " paid $"<<m_items*2<< " for " <<m_items<< " items to checker "<<i<<endl;
    }
}
