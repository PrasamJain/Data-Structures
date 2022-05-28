//define double linked list using c/c++

/*
Doubly Circular linked list is a linked list where all nodes are connected to form a circle i.e No Null End.
In Singly circular LL we traverse only in one direction i.e their is No way to move backword.
But in Doubly circular we move forword as well as backword direction because One node contain three fields - 

		Pointer to previous node  | DATA  | Pointer to next node

In this file we first create Doubly circular linked list and then perform Insertion and Deletion operation using switch case.

TYPES...
INSERTION : at_Begin , at_end , at_any_point.
DELETION : at_Begin , at_end , at_any_point.

*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head, *newnode, *temp;


void insert_beginning();
void insert_end();
void insert_any_position();


void delete_beginning();
void delete_end();
void delete_any_position();


int main()
{
	int x;
	char c;
	head=0;
	cout<<"How many elements do you wants to enter ?\n";
	cin>>x;
	cout<<"Enter the data : "<<endl;
	for(int i=0;i<x;i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));  //newnode is the temparory node that contain data,prev address
		cin>>newnode->data;                                  // and next node address. And then connect to head node.
		newnode->next = 0;
		newnode->prev = 0;
		if(head == 0) 
		{
			head = temp = newnode;    //head contain the address of first node
		}
		else
		{
			temp->next = newnode;
			newnode->prev = temp;
			temp = newnode;    //temp contain the address of last node i.e tail address
		}
	}
	
	cout<<"1 for INSERTING\n2 for DELETETION"<<endl;
	cin>>x;
	if(x == 1)
	{
		do{
			cout<<"Press:-\n1 for Insert at beginning"<<endl;
			cout<<"2 for Insert at End"<<endl<<"3 for Insert at any position"<<endl<<"4 for No Insertion"<<endl;
			cin>>x;
			switch(x)
			{
				case 1:
					insert_beginning();
					cout<<"Insert successfully...!!"<<endl;
					break;
				case 2:
					insert_end();
					cout<<"Insert successfully...!!"<<endl;
					break;
				case 3:
					insert_any_position();
					cout<<"Insert successfully...!!"<<endl;
					break;
				default:
					cout<<"Thanks"<<endl;
			}
			cout<<"Do you wants to insert again ? (y/n) : ";
			cin>>c;
		}while(c!='n');
		
		temp=head;
		
		while(temp!=0)
		{
			cout<<temp->data<<"\t";
			temp = temp->next;
		} 
	}
	else if(x == 2)
	{
		do{
			cout<<"Press:-\n1 for delete at beginning"<<endl;
			cout<<"2 for delete at End"<<endl<<"3 for delete at any position"<<endl<<"4 for No deletetion"<<endl;
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
			cout<<"Do you wants to Delete again? (y/n) : ";
			cin>>c;
		}while(c!='n');
		
		temp=head;
		
		while(temp!=0)
		{
			cout<<temp->data<<"\t";
			temp = temp->next;
		} 
	}
	else
	{
		cout<<"Invalid Input...!!"<<endl;
	}
	return 0;
}


void insert_beginning()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data : ";
	cin>>newnode->data;
	newnode->prev = 0;
	head->prev = newnode;
	newnode->next = head;
	head = newnode;
}

void insert_end()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data : ";
	cin>>newnode->data;
	newnode->next = 0;
	temp->next = newnode;
	newnode->prev = temp;
	temp = newnode;
}

void insert_any_position()
{
	int pos;
	cout<<"Enter the position : ";
	cin>>pos;
	if(pos == 1)
	{
		insert_beginning();
	}
	else
	{
		struct node *temp1;
		temp1 = head;
		newnode = (struct node*)malloc(sizeof(struct node));
		cout<<"Enter the data : ";
		cin>>newnode->data;
		for(int i=1;i<pos-1;i++)
		{
			temp1 = temp1->next;
		}
		newnode->prev = temp1;
		newnode->next = temp1->next;
		temp1->next = newnode;
		newnode->next->prev = newnode;
	}
}

void delete_beginning()
{
	if(head == 0) 
	{
		cout<<"list is Empty"<<endl;
	}
	else
	{
		temp = head;
		head = head->next;
		head->prev = 0;
		free(temp);
	}
}

void delete_end()
{
	struct node *count;
	if(temp == 0)
	{
		cout<<"list is Empty"<<endl;
	}
	else
	{
		count = temp;   //temp contain the address of last node i.e tail address
		temp->prev->next = 0;
		temp->prev = 0;
		temp = temp->prev;
		free(count);
	}
}

void delete_any_position()
{
	struct node *count;
	count = head;
	int pos;
	cout<<"Enter the position : ";
	cin>>pos;
	for(int i=1;i<pos;i++)
	{
		count = count->next;
	}
	count->prev->next = count->next;
	count->next->prev = count->prev;
	free(count);
}
