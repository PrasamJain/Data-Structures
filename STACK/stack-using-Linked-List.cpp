/*  STACK IMPLEMENTATION & THEIR BASIC OPERATIONs
 
In this file we create stack using Dynamic memory allocation OR linked list with push,pop,peek and display function in C/C++.
To implement a stack using singly linked list concept, all the linked list operations are performed based on Stack operations LIFO.

A stack contains a top pointer. which is “head” of the stack where pushing and popping items happens at the head of the list. 
First node have null in link field and second node have first node address and so on and last node address in “top” pointer.

#Advantages . . .

In using array will put a restriction to the maximum capacity of the array which can lead to stack overflow. 
Here each new node will be dynamically allocate. so overflow is not possible.

*/


#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *link;
};
struct node *top = 0;

void push(int x);
void pop();
void display();

int main()
{
	int x,data;
	do
	{
		cout<<"***Stack menu***"<<endl;
		cout<<"1.Push \n2.Pop \n3.Display \n4.Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>x;
		switch(x)
		{
			case 1:
				cout<<"Enter the data : ";
				cin>>data;
				push(data);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
		}
	}while(x!=4);
	return 0;
}

void push(int x)
{
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->link = top;
	top = newnode;
}

void pop()
{
	struct node* temp;
	temp = top;
	if(top == 0) 
		cout<<"Underflow stack!!"<<endl; 
	else
	{
		cout<<"popped element is :"<<temp->data<<endl;
		top = temp->link;
		free(temp);
	}
}

void display()
{
	struct node* temp;
	temp = top;
	if(top == 0) 
		cout<<"Underflow stack!!"<<endl; 
	else
	{
		while(temp!=0)
		{
			cout<<temp->data;
			temp = temp->link;
		}
	}
}

