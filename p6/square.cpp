#include"square.h"


Square::Square(int x, int y, int size) :Shape(x,y)
{
   m_size = size;
}

void Square::draw(Grid &Grid)
{
   for(int y = m_y; y<m_y + m_size; y++)
   {
	Grid.set(m_x, y, '*');
	Grid.set(m_x+m_size-1, y, '*');
   }

   for(int x = m_x; x<m_x + m_size; x++)
   {
	Grid.set(x, m_y, '*');
	Grid.set(x,m_y+(m_size-1),'*');
   }

}
