#ifndef POINT_H
#define POINT_H

#include<iostream>
#include"grid.h"
#include"shape.h"
using namespace std;

class Point: public Shape
{
   public:
     Point(int x, int y, char ch);
     void draw(Grid &Grid);

   protected:
     char m_char;

};
#endif
