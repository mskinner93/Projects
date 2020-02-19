#ifndef CUST_H
#define CUST_H

#include <iostream>
using namespace std;

class Cust
{
   public:
     Cust(string name, bool robber, int atime, int items);
     bool is_robber();
     int get_time();
     int get_items();
     void print(ostream &os);
     void print_entered(ostream & os, int clock);
     void print_done_shopping(ostream & os, int clock);
     void print_started_checkout(ostream & os, int clock,int i);
     void print_checker_robbed(ostream & os, int clock, int i, int amount_stolen);
     void print_done_checkout(ostream & os, int clock,int i);

   private:
     string m_name;
     bool m_robber;
     int m_atime;
     int m_items;
      
};

#endif
