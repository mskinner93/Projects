#include<iostream>
#include<string>
#include "video.h"

using namespace std;

int main()
{

   const int MAX = 100;
   Video *videos[MAX];
  
   int num_videos = 0;
   string title;
   string url;
   string comment;
   double length;
   int rating;

   string sorting_input;
   getline(cin, sorting_input);
   if (sorting_input != "rating" && sorting_input != "length" && sorting_input != "title")
   {
     cerr << sorting_input << " is not a legal sorting method, giving up." <<endl;
       return 1;
   }

/*  for (int i = 0; i < MAX; i++)
    {
      videos[i] = NULL;
    }
*/
   while(getline(cin,title))
	{
	   getline(cin,url);
	   getline(cin,comment);
	   cin>>length;
	   cin>>rating;

	   cin.ignore();
	   videos[num_videos] = new Video(title, url, comment, length, rating);
	   num_videos++;
	}


	if(num_videos > MAX)
	{
	   cerr <<"Too many videos, giving up." <<endl;
		return 1;
	}

	if(sorting_input == "length")
	{
	bool longer(Video *other);
	for (int last = num_videos -1; last > 0; last--)
          for (int cur = 0; cur < last; cur++)
             if (videos[cur]->longer(videos[cur+1]))
                swap(videos[cur], videos[cur+1]);
	}

	else if(sorting_input == "rating")
        {
        bool better(Video *other);
        for (int last = num_videos -1; last > 0; last--)
          for (int cur = 0; cur < last; cur++)
             if (videos[cur]->better(videos[cur+1]))
                swap(videos[cur], videos[cur+1]);
        }

        else if(sorting_input == "title")
        {
        bool alpha(Video *other);
        for (int last = num_videos -1; last > 0; last--)
          for (int cur = 0; cur < last; cur++)
             if (videos[cur]->alpha(videos[cur+1]))
                swap(videos[cur], videos[cur+1]);
        }

	for(int i = 0; i < num_videos; i++)
	{
	   videos[i]->print();
	}

}
   
