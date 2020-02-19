#ifndef GRID_H
#define GRID_H

#include<iostream>
using namespace std;

class Grid
{
   public:
     Grid ();
     void set(int x, int y, char ch);
     void print();

   private:
     char m_grid[60][24];
     


};
#endif
