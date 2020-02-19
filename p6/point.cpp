#include"point.h"
Point::Point(int x, int y, char letter) : Shape(x,y)
{
   m_char = letter;
}

void Point::draw(Grid &Grid)
{
   Grid.set(m_x, m_y, m_char);
}
