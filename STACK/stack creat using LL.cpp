// create stack using dynamic memory allocation or LL

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

