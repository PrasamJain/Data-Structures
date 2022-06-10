/* infix  to  prefix using stack*/
#include <iostream>
#include <cstring>
#include <stdlib.h>
#define N 10
using namespace std;
char stack[N];
int top = -1;
char prefix[30];

void push(char x)
{
	if(top == N-1)
	{
		cout<<"Overflow stack";
	}
	else
	{
		cout<<"push :" <<x<<endl;
		top++;
		stack[top] = x;
	}
}

char pop()
{
	cout<<"pop : "<<stack[top]<<endl;
	char ch = stack[top];
	top--;
	return ch;
}

void peek()
{
	if(top == -1)
	{
		cout<<"Stack Empty\n";
	}
	else
	{
		cout<<"The top element is  : "<<stack[top]<<endl;
	}
}

int precedence (char ch)
{
  switch (ch)
    {
    case '|':
    	return 1;
    case '&':
    	return 2;	
    case '+':
    case '-':
      	return 3;

    case '*':
    case '/':
      	return 4;

    case '^':
      	return 5;
    }
  return -1;
}

void reverse(char a[],int n)
{
    int j = n-1 , i;
	char temp;
	for (i = 0; i < j; i++,j--)
    {
    	temp = a[i];
        a[i] = a[j];
        a[j] = temp;
	}
}
int main()
{
	string s;
	cout<<"Enter the Infix Eq."<<endl;
	cin>>s;
	int n = s.length();  //function of library cstring. 
	 
    // declaring character array says 'a'
    char a[n + 1];
 
    // copying the contents of the string 's' to char array 'a'
    strcpy(a, s.c_str());
   
    int j , i;
    //reverse the infix eq.
    reverse(a,n);
    
	cout<<"\n\nThe Reverse of Given string is:\n";
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
    //put onto stacks
    
	int x,y;
	j=0;
	for(i=0; i<n; i++)
	{
		if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))   //characters
		{
			prefix[j] = a[i];j++;
		}
		else if(a[i] == '(')  //brackets
		{
			while(stack[top] != ')')
			{	prefix[j] = pop();j++;	}
			top--;
		}
		else if(a[i] == ')')  //brackets
		{
			push(a[i]);
		}
		else  // symbols
		{
			x = precedence(a[i]);
			y = precedence(stack[top]);
			if(x>y)  // hightest 
			{
				push(a[i]);
			}
			else if(x<y)  //lowest
			{
				while(x<y)
				{
					prefix[j] = pop();
					j++;
					x = precedence(a[i]);
					y = precedence(stack[top]);
					if(x>y) push(a[i]);
					else if(x == y) 
					{
						if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '|' || a[i] == '&')  // L TO R FOR +,-,*,/
						{
							push(a[i]);   
						}
						else     // R to L for ^ and other 
						{
							prefix[j] = pop();
							j++;
							push(a[i]);
						}
					}
				}
			}
			else if(x == y)  //equal
			{
				if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '|' || a[i] == '&')  // L TO R FOR +,-,*,/
				{
					push(a[i]);   
				}
				else     // R to L for ^ and other 
				{
					prefix[j] = pop();
					j++;
					push(a[i]);
				}
				
			}
		}
   }
       
while(top != -1)
{
	prefix[j] = stack[top];
	top--;j++;
}
reverse(prefix,n);
cout<<endl<<"prefix Eq. are\n"; 
for(i=0; i<n; i++)
	cout<<prefix[i]<<" "; 
    return 0;
}

//k+l-m*n+(o^p)*w/u/v*t+q
