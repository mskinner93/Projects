#ifndef SQUARE_H
#define SQUARE_H

#include<iostream>
#include"grid.h"
#include"shape.h"
using namespace std;

class Square: public Shape
{
   public:
     Square(int x, int y, int size);
     void draw(Grid &Grid);

   protected:
    int  m_size;
};
#endif
