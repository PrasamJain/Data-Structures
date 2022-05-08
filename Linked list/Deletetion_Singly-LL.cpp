							/******* DELETION ON SINGLY LINKED LIST ***********/


// There are three Possible Ways to Deleting a new element into a singly linked list.
/*      - Deletion at beginning. 
	- Deletion at end of the list
	- Deletion after specified node.
*/
// In this solution we perform Insertion using Switch Case.


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*head=0, *newnode, *temp;


void delete_beginning();
void delete_end();
void delete_any_position();


int main()
{
	int x;
	cout<<"Enter the number of elements do you wants to insert : ";
	cin>>x;
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<x;i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		cin>>newnode->data;
		newnode->next = 0;
		if(head == 0)
		{
			head  = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = temp->next;	
		}
	}
	cout<<"For Deletetion an elements Press:-\n1 for Delete at beginning"<<endl;
	cout<<"2 for Delete at End"<<endl<<"3 for Delete at any position"<<endl<<"4 for No Deletetion"<<endl;
	cin>>x;
	switch(x)
	{
		case 1:
			delete_beginning();
			break;
		case 2:
			delete_end();
			break;
		case 3:
			delete_any_position();
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
	return 0;
	
}

void delete_beginning()
{
	if(head == 0)
	{
		cout<<"Empty linked list !!"<<endl;
	}
	temp = head;
	head = temp->next;
	free(temp);
}
void delete_end()
{
	struct node *prevnode;
	temp = head;
	while(temp->next!=0)
	{
		prevnode = temp;
		temp = temp->next;
	}
	if(temp == head) 
	{ 
		head =0; 
		free(temp); 
	}
	else
	{
		prevnode->next = 0;
		free(temp);
	}
}
void delete_any_position()
{
	int pos;
	struct node *nextnode;
	cout<<"Enter Which position do you wants to delete? :";
	cin>>pos;
	temp = head;
	if(pos == 1)
	{
		delete_beginning();
	}
	else if(pos>1)
	{
		for(int i=1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		nextnode = temp->next;
		temp->next = nextnode->next;	
		free(nextnode);
	}
	else
		cout<<"Invalid position !!"<<endl;
}









