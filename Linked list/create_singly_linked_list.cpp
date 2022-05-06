//define single linked list using c 

#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head, *newnode, *temp;
	head=0;
	char c;
	do
	{
		newnode = (struct node*) malloc(sizeof(struct node));
		cout<<"Enter the element\n";
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
		cout<<"Do you wnat to enter the more elements?(y/n)\n";
		fflush stdin;
		cin>>c;
	}while(c !='n');
	temp=head;
	cout<<"Elements\tAddresses\n";
	while(temp!=0)
	{
		cout<<"%d\t\t",temp->data;
		cout<<"%d\n",temp->next;
		temp = temp->next;
	}
	return 0;
}
