//define circular linked list using c/c++

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};
struct node *head, *newnode, *temp, *tail;


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
		if(head == 0) 
		{
			head = temp = newnode;    //head contain the address of first node
		}
		else
		{
			temp->next = newnode;
			temp = newnode;    //temp contain the address of last node i.e tail address
		}
		temp->next = head;
	}
	
	tail = temp;
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
		
		cout<<"Head address : "<<head<<endl;
		cout<<"Tail address : "<<tail<<endl;
		temp=head;
		cout<<"Elements\tNext.Addresses\n";
		
		while(temp->next != head)
		{
			cout.width(6);
			cout<<temp->data<<"       |";
			cout.width(12);
			cout<<temp->next<<"\n";
			temp = temp->next;
		} 
		cout.width(6);
		cout<<temp->data<<"       |";
		cout.width(12);
		cout<<temp->next<<"\n";
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
		
		cout<<"Head address : "<<tail->next<<endl;
		cout<<"Tail address : "<<tail<<endl;
		temp=tail->next;
		cout<<"Elements\tNext.Addresses\n";
		
		while(temp->next != tail->next)
		{
			cout.width(6);
			cout<<temp->data<<"       |";
			cout.width(12);
			cout<<temp->next<<"\n";
			temp = temp->next;
		} 
		cout.width(6);
		cout<<temp->data<<"       |";
		cout.width(12);
		cout<<temp->next<<"\n";
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
	newnode->next = 0;
	if(tail == 0)
	{
		tail = newnode;
		tail->next = newnode;
	}
	else
	{
		newnode->next = tail->next;
		tail->next = newnode;
		head = newnode;
	}
}

void insert_end()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data : ";
	cin>>newnode->data;
	newnode->next = 0;
	if(tail == 0)
	{
		tail = newnode;
		tail->next = newnode;
	}
	else
	{
		newnode->next = tail->next;
		tail->next = newnode;
		tail = newnode;
	}
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
		newnode = (struct node*)malloc(sizeof(struct node));
		cout<<"Enter the data : ";
		cin>>newnode->data;
		temp = tail->next;
		for(int i=1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
}

void delete_beginning()
{
	temp = tail->next;
	if(tail == 0) 
	{
		cout<<"list is Empty"<<endl;
	}
	else if(temp == tail) //check if their is only one node
	{
		tail = 0;
		free(temp);
	}
	else
	{
		tail->next = temp->next;
		free(temp);
	}
}

void delete_end()
{
	struct node *current, *prev;
	current = tail->next;
	if(tail == 0) 
	{
		cout<<"list is Empty"<<endl;
	}
	else if(tail == current) //check if their is only one node
	{
		tail = 0;
		free(current);
	}
	else
	{
		while(current != tail)
		{
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
		tail = prev;
		free(current);
	}
}

void delete_any_position()
{
	int pos;
	struct node *current, *next;
	current = tail->next;
	cout<<"Enter the position : ";
	cin>>pos;
	if(pos == 1)
	{
		delete_beginning();
	}
	else
	{
		for(int i=1;i<pos-1;i++)
		{
			current = current->next;
		}
		next = current->next;
		current->next = next->next;
		free(next);
	}
}

