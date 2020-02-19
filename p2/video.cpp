#include <iostream>
#include "video.h" 
using namespace std;
// example of how functions are specified
Video::Video(string title, string url, string comment, double length, int rating)
{
	m_title = title;
	m_url = url;
	m_comment = comment;
	m_length = length;
	m_rating = rating;
}

void Video::print()
{
    cout<<m_title<<", " <<m_url<< ", " <<m_comment<< ", " <<m_length<<", ";

   for(int i = 0; i < m_rating; i++)
	{
	   cout<<"*";
	}
	cout<<endl;
}

bool Video::longer(Video *other)
{
  return this->m_length > other->m_length;
}

bool Video::better(Video *other)
{
  return m_rating < other->m_rating;
}

bool Video::alpha(Video *other)
{
  return m_title > other->m_title;
}

