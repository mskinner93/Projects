#include"circle.h"
Circle::Circle(int x, int y) : Shape(x,y)
{

}
void Circle::draw(Grid &Grid)
{
   for(int x=m_x; x<m_x+2; x++)
   {
     Grid.set(x+1,m_y, 'o');
     Grid.set(x+1,m_y+3, 'o');
   }


     Grid.set(m_x,m_y+1, 'o');
     Grid.set(m_x+3,m_y+1,'o');
     Grid.set(m_x,m_y+2, 'o');
     Grid.set(m_x+3,m_y+2,'o');

  

   
}
