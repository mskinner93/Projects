#include<iostream>
using namespace std;

int main()
{

int input;
const int MAX = 100;
int numChart[MAX];
int count =0; 


while(count < MAX)
{
 cin>>input;
    if(input ==0)
    {
    break;
    }
   numChart[count]=input;
   count++;
}
//finds largest num
int biggestNum = 0;

for (int e=0;e<=MAX;e++)
{
	if(numChart[e]>biggestNum)
	biggestNum=numChart[e];
}


for (int row=biggestNum;row>=1;row--)
{
   for (int col=0;col<=MAX;col++)
   {
	if(numChart[col]>=row)
	cout<<'*';
	
	else
	cout<<" ";
	//cout<<endl;
   }
	cout<<endl;
}
return 0;
}

