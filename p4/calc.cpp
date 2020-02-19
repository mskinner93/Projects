// calc.cpp
// Skinner, Mitch
// mskinner93
#include <iostream>
using namespace std;
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include "dstack.h"

bool isOperator(char ch);
void error();

int main()
{
   double value;
   Dstack stack;

  while(cin.peek() !=EOF)
  {
    if(isdigit(cin.peek()) || cin.peek() == '.')
    {
        cin >> value;
        if(cin.peek() == '.' || cin.good() == false)
        {
          error();
        }
        stack.push(value);
    }

    else if(isspace(cin.peek()))
    {
       cin.ignore();
    }

    else
    {
	char ch;
	cin>> ch;
	if(stack.size()>1 && isOperator(ch)==true)
	{
           double sum, value1, value2;
           stack.pop(value2);
           stack.pop(value1);

	   switch(ch)
	   {
           case '+':
     	   sum = value1 + value2;
           stack.push(sum);
           break;
     	
     	   case '-':
           sum = value1 - value2;
           stack.push(sum);
           break;

     	   case '*':
           sum = value1 * value2;
           stack.push(sum);
           break;

           case '/':
           sum = value1 / value2;
           stack.push(sum);
           break;

           case '^':
           sum = pow(value1, value2);
           stack.push(sum);
           break;

           default:
           error();
           break;
           }
        }

        else
        {
          error();
        }
    }
  }

 if (stack.size()==1)
 {
     stack.pop(value);
     cout<<value<<endl;
 }

 else
 {
   error();
 }

}
   
    bool isOperator (char ch)
    {
      if(ch == '+' || '-' || '*' || '/' || '^')
      {
        return true;
      }

      else
      {
        return false;
      }
     }

    void error()
    {
        cerr<<"Error: Invalid expression."<<endl;
        exit(1);
    }
