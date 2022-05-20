//find middle node of the linked list


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*head=0, *newnode, *temp;

int main()
{
	int x;
	cout<<"How many elements do you wants to enter ?"<<endl;
	cin>>x;
	cout<<"Enter the elements"<<endl;
	
	for(int i=0;i<x;i++)
	{
		newnode = (struct node*) malloc(sizeof(struct node));
		cin>>newnode->data;
		newnode->next=0;
		if(head == 0)
		{
			head = newnode;
			temp = newnode;
		}
		else
		{
			temp->next  =newnode;
			temp = newnode;
		}
	}
	temp = head;
	if(x%2 == 0)
	{
		for(int i=1;i<x/2;i++)
		{
			temp = temp->next;
		}
		cout<<"Middle node : "<<temp->data<<" and "<<temp->next->data<<endl;
	}
	else
	{
		for(int i=1;i<=x/2;i++)
		{
			temp = temp->next;
		}
		cout<<"Middle node : "<<temp->data<<endl;
	}
return 0;
}
	
	
	
