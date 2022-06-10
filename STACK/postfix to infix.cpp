/* postfix to infix */
// first we convert infix to postfix , Now we convert back from postfix to infix.

#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<cmath>
#define N 10

using namespace std;

string stack[N];
int top = -1;

void push(string x)
{
	if(top == N-1) cout<<"Overflow stack..."<<endl;
	else
	{
		cout<<"PUSH--->"<<x<<endl;
		top++;
		stack[top] = x;
	}
}

string pop()
{
		string x = stack[top];
		top--;
		cout<<"POP--->"<<x<<endl;
		return x;
}

int main()
{
	string a;
	cout<<"Enter the postfix Eq."<<endl;
	cin>>a;
	string op1,op2,R;
    
    int i,j=0;
    cout<<"STACK MEMORY"<<endl;
    for(i=0; a[i] !='\0'; i++)
    {
    	if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
    	{
    		string flag;
            flag=flag+a[i];
            push(flag);
		}
		else 
		{
			op2 = pop();
			op1 = pop();
			R = '('+op1+a[i]+op2+')';
			
			push(R);
		}
	}
	cout<<endl<<"Infix Eq. : "<<stack[top];
	return 0;
}
