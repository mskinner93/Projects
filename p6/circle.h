#ifndef CIRCLE_H
#define CIRCLE_H

#include<iostream>
#include"grid.h"
#include"shape.h"
using namespace std;

class Circle: public Shape
{
     public:
       Circle(int,int);
       void draw(Grid &Grid);
};
#endif
