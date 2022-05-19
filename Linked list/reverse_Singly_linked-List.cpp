//Reverse a singly LL

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
}*head=0, *newnode, *temp;


void reverse();

int main()
{
	char c;
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
	reverse();  //for reversed singly linked list
	temp = head;
	while(temp!=0)
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	return 0;
}

void reverse()
{
	struct node *prevnode, *nextnode, *currentnode;
	prevnode = 0;
	currentnode = nextnode = head;
	while(nextnode != 0)
	{
		nextnode = nextnode->next;
		currentnode->next = prevnode;
		prevnode = currentnode;
		currentnode = nextnode;
	}
	head = prevnode;
}
