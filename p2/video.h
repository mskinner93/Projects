#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
using namespace std;

class Video
{
    public:
        // public member functions go here
	Video(string title, string url, string comment, double length, int rating);
	~Video();
        void print();
	bool longer (Video *other);
	bool better(Video *other);//rating
	bool alpha(Video *other);//ABC
	
	
	
    private:
	string  m_title;
	string  m_url;
	string  m_comment;
	double m_length;
	int m_rating;
        // member variables go here
        // member function used only by other member functions go here

};

#endif



