/*
We can create stack using two ways - Array and Linked List. 
In this file we create stack using array static allocation with push,pop,peek and display function in C/C++.
*/

#include <iostream>
#define N 100
using namespace std;
int stack[N];
int top = -1;

void push();
void pop();
void display();

int main()
{
	int x;
	do
	{
		cout<<"***Stack menu***"<<endl;
		cout<<"1.Push \n2.Pop \n3.Display \n4.Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>x;
		switch(x)
		{
			case 1:
				push();    //insert elements acc. to FIFO
				break;
			case 2:
				pop();     //delete element from top.
				break;
			case 3:
				display();    //display elements from top to empty stack.
				break;
		}
	}while(x!=4);
	return 0;
}

void push()
{
	int x;
	cout<<"Enter the data : ";
	cin>>x;
	if(top == N-1)
	{
		cout<<"Overflow stack"<<endl;
	}
	else
	{
		top++;
		stack[top] = x;
	}
}

void pop()
{
	if(top == -1)
	{
		cout<<"Underflow stack"<<endl;
	}
	else
	{
		cout<<"The popped element is : "<<stack[top]<<endl;
		top--;
	}
}

void display()
{
	cout<<"The stack is : "<<endl;
	for(int i = top;i>=0;i--) 
		cout<<stack[i]<<endl;
}

