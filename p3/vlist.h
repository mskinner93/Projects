// main.cpp
// Skinner, Mitch
// mskinner93
#ifndef VLIST_H
#define VLIST_H
#include"video.h"

#include <iostream>
using namespace std;

class Vlist
{
    public:
        Vlist();
        ~Vlist();
        //void insert(Video* vid);
	void insert(Video* videos);
        void print();
	Video* lookup(string title);
	bool remove(string title);
    private:
        class Node
        {
            public:
                // small functions can be inserted into the class definition
                // don't put large functions in the class definition
                Node(Video *video, Node *next)
                {m_video = video; m_next = next;}
		Video *m_video;
                Node *m_next;
        };
	Node* m_head;
};


#endif
