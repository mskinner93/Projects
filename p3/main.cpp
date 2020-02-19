// main.cpp
// Skinner, Mitch
// mskinner93
#include<iostream>
#include<string>
#include "video.h"
#include "vlist.h"

using namespace std;

int main()
{

   Vlist videos;
  
   string title;
   string url;
   string comment;
   double length;
   int rating;

   int video_objects = 0;

   string command;

   while(getline(cin,command))
       {
	if(command == "insert")
	 {
	   getline(cin,title);
	   getline(cin,url);
	   getline(cin,comment);
	   cin>>length;
	   cin>>rating;

	   cin.ignore();
	   videos.insert(new Video(title,url,comment,length,rating));
	   video_objects++;
	 }

	else if(command == "lookup")
        {
		getline(cin,title);
		Video* video = videos.lookup(title);
                if(video==NULL)
                {
                  cerr<<"Title "<< "<"<<title<<">" <<" not in list."<<endl;
                }
                else
                {
		 
		 video->print(); 
                }

	}



	else if(command == "length")
	{
		cout<<video_objects<<endl;
			
	}
    
   	else if(command == "remove")
   	{
		getline(cin,title);
	    	
		
		if(videos.remove(title)==true)
		{
		 video_objects--;
		}
		else if(videos.remove(title)==false)
		{
		   cerr<<"Title " << "<" <<title<< ">"<<  " not in list, could not delete."<<endl;
		   
		}
		
   	}


   	else if(command == "print")
   	{
          videos.print();
   	}

	else
	{
		cerr<< "<" <<command<< ">" << " is not a legal command, giving up."<<endl;
		return 1;
	}
   }
}
