#include "grid.h"

Grid::Grid()
{
  for(int y=0; y<24; y++)
 {
   for(int x=0; x<60; x++)
   {
        m_grid[x][y] = ' ';
   }
 }

}
void Grid::set(int x, int y, char ch)
{
 if(x<60 && y<24)
 { 
  m_grid[x][y] = ch;
 }
}

void Grid::print()
{
 for(int y=0; y<24; y++)
 {
   for(int x=0; x<60; x++)
   {
       cout<< m_grid[x][y];
   }
  cout<<endl;
 }
}
