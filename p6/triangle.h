#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<iostream>
#include"grid.h"
#include"shape.h"
using namespace std;

class Triangle : public Shape
{
   public:
     Triangle(int, int);
     void draw(Grid &Grid);

 //  protected:
    // m_size;
};
#endif
