#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"bst.h"

using namespace std;

void print_from_vector(vector<string> vec);

int main()
{
   Tree bst;
   string command;
   string title;

   while(cin>>command)
    {

       if(command == "echo")
       {
	string comment;
	cin.ignore();
	getline(cin,comment);
	cout<<comment<<endl;
       }

       else if(command == "insert")
       {
	cin.ignore();
	getline(cin,title);
	if(bst.insert(title)==false)
	{
	   cerr<<"insert <"<<title<<"> failed. String already in tree.\n";
	}
       }

       else if(command == "print")
       {
	  vector<string> vec;
	  bst.print(vec);
	  print_from_vector(vec);
	  
       }

       else if(command == "breadth")
       {
	 vector<string> vec;
	 bst.breadth(vec);
	 print_from_vector(vec);
       }

       else if(command == "size")
       {
	 bst.size();
	 cout<<bst.size()<<endl;
       }

       else if(command == "find")
       {
	 cin.ignore();
	 getline(cin,title);
	 if(bst.find(title)==true)
         {
	   cout<<"<"<<title<<"> is in tree.\n";
	 }
	 else
	 {
	   cout<<"<"<<title<<"> is not in tree.\n";
	 }
       }

       else if(command == "distance")
       {
	  bst.average();
	  cout<<"Average distance of nodes to root = "<<bst.average()<<endl;
       }

       else if(command == "balanced")
       {
	  if(bst.balanced() == false)
	  {
	    cout<<"Tree is not balanced.\n";
	  }
	  else
	  {
	    cout<<"Tree is balanced.\n";
	  }
       }
       else if(command == "rebalance")
       {
	   bst.rebalanced();
       }
       else
       { 
	   cerr<<"Illegal command <"<<command<<">.\n";
           getline(cin, command);
       }

     }
 return 0;

}


void print_from_vector(vector<string> vec)
{

  cout<<"{";
  for(unsigned int i=0; i<vec.size(); i++)
  {  
     if(i != 0)
     {
     cout<< ", ";
     }
     cout<<vec[i];
  }

  cout<<"}"<<endl;
}

