/* infix  to  posfix using stack*/
// we convert infix equation into postfix equations using stack. It is the one of the application of Stack.

#include <iostream>
#include <cstring>
#include <stdlib.h>
#define N 10
using namespace std;
char stack[N];
int top = -1;
char postfix[30];

void push(char x)
{
	if(top == N-1)
	{
		cout<<"Overflow stack";
	}
	else
	{
		top++;
		cout<<"PUSH : "<<x<<endl;
		stack[top] = x;
	}
}

char pop()
{
		cout<<"POP : "<<stack[top]<<endl;
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


int main()
{
	string s;
	int j = 0, i;
	cout<<"Enter the Infix Eq."<<endl;
	cin>>s;
	int n = s.length();  //function of library cstring. 
	 
    // declaring character array says 'a'
    char a[n + 1];
 
    // copying the contents of the string 's' to char array 'a'
    strcpy(a, s.c_str());
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
    
    //put onto stacks
    
	int x,y;
	
	for(i=0; i<n; i++)
	{
		if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))   //characters(operand)
		{
			postfix[j] = a[i];j++;
		}
		else if(a[i] == '(')  //open-brackets
		{
			push(a[i]);
		}
		else if(a[i] == ')')  //close-brackets
		{
			while(stack[top] != '(')
			{	postfix[j] = pop();j++;	}
			top--;
		}
		else  // symbols(operators)
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
					postfix[j] = pop();
					j++;
					x = precedence(a[i]);
					y = precedence(stack[top]);
					if(x>y) push(a[i]);
					else if(x == y) 
					{
						if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '|' || a[i] == '&')  // L TO R FOR +,-,*,/
						{
							postfix[j] = pop();
							j++;
							push(a[i]);   
						}
						else     // R to L for ^ and other 
						{
							push(a[i]);
						}
					}
				}
			}
			else if(x == y)  //equal
			{
				if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '|' || a[i] == '&')  // L TO R FOR +,-,*,/
				{
					postfix[j] = pop();
					j++;
					push(a[i]);   
				}
				else     // R to L for ^ and other 
				{
					push(a[i]);
				}
				
			}
		}
   }
while(top != -1)
{
	postfix[j] = stack[top];
	top--;j++;
}
cout<<endl<<"Postfix Eq. are\n";  
for(i=0; i<n; i++)
cout<<postfix[i];  
return 0;
}

//Example for conversion - try yourself !!

// InfixEquation :-    k+l-m*n+(o^p)*w/u/v*t+q