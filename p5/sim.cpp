#include<iostream>
#include<string>
#include<fstream>
#include<assert.h>
#include"cust.h"
#include"pqueue.h"

using namespace std;

bool legal_int(char *str);
void run_simulation(Pqueue &arrival_q, int num_checkers, int break_duration,ostream & os);


int main(int argc, char *argv[])
{
  int num_checkers;
  int break_duration;

   if(argc != 5)
   {
     cerr<<"Error: invalid number of command line arguments."<<endl;
     return  1;
   }
//check if int bool legal int from lab 8
  if(legal_int(argv[1])== false || atoi(argv[1]) < 1)
   {
     cerr<<"Error: invalid number of checkers specified."<<endl;
     return 1;
   }

   else// (num_checkers >= 1)
   {
     num_checkers = atoi(argv[1]);
     
   }



//checkers break time
   if(legal_int(argv[2])== false)
   {

     cerr<<"Error: invalid checker break duration specified."<<endl;
     return 1;
   }

   else
   {
     break_duration = atoi(argv[2]);
   }



   ifstream my_ifile(argv[3], ios::in);
   if(!my_ifile)
   {
     cerr<<"Error: could not open input file <" <<argv[3] << ">." <<endl;
     return 1;
   }
   ofstream my_ofile(argv[4], ios::out);
   if(!my_ofile)
   {
     cerr<<"Error: could not open output file <" <<argv[4] << ">." <<endl;
     return 1;
   }

   Pqueue arrival_q;

   string name;
   string robber;
   int atime;
   int items;


 while(my_ifile >> name)
  {
   my_ifile >> robber;
   my_ifile >> atime;
   my_ifile >> items;

   Cust* new_cust = new Cust(name,(robber =="robber"? 1:0),atime,items);
   arrival_q.enqueue(new_cust, atime);

  }
   run_simulation(arrival_q, num_checkers, break_duration, my_ofile);
}

bool legal_int(char *str)
{
   while(str[0] != 0)
   {
     if(isdigit(str[0])==false)
     {
        return false;
     }
        str++;
   }
     return true;
}











void run_simulation(Pqueue &arrival_q, int num_checkers, int break_duration,ostream & os)
{
    Pqueue shopping_q;
    Pqueue checkout_q;
    
    int clock;
    int time_done_shopping;
    int num_customers = arrival_q.length();
    int checkers_break;
    

    struct Checker
    {
	int reg_total;
        int time_avail;
        Cust* m_cust;
    };
    // create an array of Checker structures
    Checker *checkers = new Checker[num_checkers];

    // now use a loop to initialized all elements of the Checker structures
    for(int i=0; i < num_checkers; i++)
    {
       checkers[i].reg_total = 250;
       checkers[i].time_avail = 0;
       checkers[i].m_cust = NULL;
    }

 for(clock = 1; num_customers > 0; clock++)
 {

    for(int i = 0; i < num_customers; i++)//gets arrival q to shopping queue
    {
      while(arrival_q.first_priority() == clock)
      {
	
	Cust *next_cust = arrival_q.dequeue();
        next_cust->print_entered(os, clock);
	time_done_shopping = (next_cust->get_time() + (next_cust->get_items() *3));
        shopping_q.enqueue(next_cust,time_done_shopping);
	
      }
    }

   for(int i = 0; i < num_customers; i++)//gets shopping queue to checking queue
   {
      while(shopping_q.first_priority() == clock)
      {
	Cust *enter_checkout = shopping_q.dequeue();
        enter_checkout->print_done_shopping(os, clock);
        checkout_q.enqueue(enter_checkout, 1);
      }
   }




  //check for open cashier
      for (int i = 0; i < num_checkers; i++)
      {
        if(clock == checkers[i].time_avail && checkers[i].m_cust != NULL)
        {
            if(checkers[i].m_cust->is_robber())
            {
	       int amount_stolen = checkers[i].reg_total;
	       checkers[i].m_cust->print_checker_robbed(os,clock,i,amount_stolen);
               checkers[i].reg_total = 0;
	       checkers_break = clock + break_duration;
	       checkers[i].time_avail= checkers_break;
            }
            else
            {
   	       int total_paid = checkers[i].m_cust->get_items()*2;
               checkers[i].reg_total += total_paid;
               checkers[i].m_cust->print_done_checkout(os,clock,i);

            }

         num_customers--;
         Cust* temp = checkers[i].m_cust;
         checkers[i].m_cust=NULL;
         delete temp;
         

        }
      }

  
//while there is an avaliable checker
     for(int i=0; i<num_checkers;i++)
     {
        if(checkers[i].m_cust == NULL && checkout_q.length() > 0  && checkers[i].time_avail <= clock) 
        {
           Cust* tmp_cust=checkout_q.dequeue();
           checkers[i].m_cust=tmp_cust;
           if(tmp_cust->is_robber()==true)
           {
              checkers[i].time_avail = clock + 7;
           }
           else
           {
              checkers[i].time_avail = tmp_cust->get_items()*2 +clock;
           }
           tmp_cust->print_started_checkout(os,clock,i);
           
         }
     
      }
  
 }//should be the end of the long for loop for the time

  for(int i=0;i<num_checkers;i++)
  {
   os<<"registers["<<i<<"] = $"<<checkers[i].reg_total<<endl;
  }
   os<<"time = "<<clock<<endl;

}

