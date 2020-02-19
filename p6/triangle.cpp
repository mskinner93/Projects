#include"triangle.h"
Triangle::Triangle(int x, int y) : Shape(x,y)
{

}
void Triangle::draw(Grid &Grid)
{
	Grid.set(m_x+2, m_y, '+');//the top or tip of the triangle

   for(int x=m_x; x<m_x+5; x++)//the base of the triangle
   {
     Grid.set(x,m_y+2,'+');
     
   }
     Grid.set(m_x+1,m_y+1, '+');//the middle of the triangle
     Grid.set(m_x+3,m_y+1, '+');
}
