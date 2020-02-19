#ifndef SHAPE_H
#define SHAPE_H

#include<iostream>
#include"grid.h"
using namespace std;

class Shape
{
   public:
     Shape(int x, int y);
     virtual void draw(Grid &Grid ) = 0;

   protected:
     int m_x;
     int m_y;

};
#endif
