/*prefix evalution*/

#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<cmath>
#define N 10

using namespace std;

int stack[N];
int top = -1;

void push(int x)
{
	if(top == N-1) cout<<"Overflow stack..."<<endl;
	else
	{
		top++;
		stack[top] = x;
	}
}

int pop()
{
		int x = stack[top];
		top--;
		return x;
}

int main()
{
	string s;
	int j=0,op1,op2,R;
	cout<<"Enter the prefix equation (sperated by comma[,])"<<endl;
	cin>>s;
	int n = s.length();  //function of library cstring. 
	
	char a[n-1];
	strcpy(a, s.c_str());
	
	for(int i=0;i<n;i++)
	{
		if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '^')
		{
			op2 = pop();  //type conversion
			op1 = pop();
			if (a[i] == '+')
			{
				R = op1 + op2;
				push(R);
			}
			else if (a[i] == '-')
			{
				R = op1 - op2;
				push(R);
			}
			else if (a[i] == '*')
			{
				R = op1 * op2;
				push(R);
			}
			else if (a[i] == '/')
			{
				R = op1 / op2;
				push(R);
			}
			else if (a[i] == '^')
			{
				R = pow(op1,op2);
				push(R);
			}
		}
		else if(a[i] == ',')
			continue;
		else
		{
			push(a[i] - '0');   //ascii of character '0' is 48. So, we subtract 48 from ascii of other character like:-
							    // '3'(char) ascii is 51 so, '3' - '0' i.e 51-48 = 3(int).
			if(a[i+1] != ',')
			{
				int x= pop();
				x = x*10 + (a[i+1] - '0');
				push(x);
				i++;
			}
		}
	}
cout<<endl<<"result : "<<stack[top];
return 0;
}
