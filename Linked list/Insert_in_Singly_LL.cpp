// There are three Possible Ways to Inserting a new element into a singly linked list.
/*      - Insertion at beginning. 
	- Insertion at end of the list
	- Insertion after specified node.
*/
// In this solution we perform Insertion using Switch Case.



#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int count = 0;
struct node
{
	int data;
	struct node *next;
}*head=0, *newnode, *temp;


//function declaration
void beginning();
void end();
void any_position();

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
		count++;
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
	cout<<"For inserting an elements Press:-\n1 for Insert at beginning"<<endl;
	cout<<"2 for Insert at End"<<endl<<"3 for Insert after given location"<<endl<<"4 for No Insertion"<<endl;
	cin>>x;
	switch(x)
	{
		case 1:
			beginning();
			break;
		case 2:
			end();
			break;
		case 3:
			any_position();
			break;
		default:
			cout<<"Thanks"<<endl;
	}
	temp=head;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	} 
	cout<<endl<<"the length of the linked list is : "<<count;
	return 0;
}

// Function definition
void beginning()
{
	newnode = (struct node*) malloc(sizeof(struct node));
	cout<<"Enter the data you want to insert : ";
	cin>>newnode->data;
	newnode->next = 0;
	if(head == 0)
	{
		head = newnode;
		temp = newnode;
		count++;
	}
	else
	{
		newnode->next = head;
		head = newnode;
		count++;
	}
}

void end()
{
	newnode = (struct node*) malloc(sizeof(struct node));
	cout<<"Enter the data you want to insert : ";
	cin>>newnode->data;
	newnode->next = 0;
	temp = head;
	if(head == 0)
	{
		head = newnode;
		temp = newnode;
		count++;
	}
	else
	{
		while(temp->next!=0)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		count++;
	}	
}

void any_position()
{
	int pos;
	newnode = (struct node*) malloc(sizeof(struct node));
	cout<<"Enter position : ";
	cin>>pos;
	if(pos>count || pos < 0)
	{
		cout<<"Invalid position !!\n"<<endl;
	}
	else if(pos == 1)
	{
		beginning();
		count++;
	}
	else if(pos >= 2)
	{
		temp = head;
		for(int i=1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		cout<<"Enter the data you want to insert : ";
		cin>>newnode->data;
		newnode->next = temp->next;
		temp->next = newnode;
		count++;
	}
}
