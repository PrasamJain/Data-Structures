							/******  Search an element in single Linked list *******/

/* 	Searching is performed to find the location of a particular element in the linked list. 
	Searching any element in the linked list, needs traversing through the list and Comparing every element of the list with the Key element. 
	If the Key element is matched with any of the list element then the Position of the element is returned from the function otherwise return NULL.
*/


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
}*head=0, *newnode, *temp;

int search(int n);

int main()
{
	char c;
	int x,n;
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
	
	cout<<"Enter the element for search : ";
	cin>>n;
	n = search(n);
	if(n != 0)
		cout<<"Element found at position "<<n<<endl;
	else
		cout<<"Element not found"<<endl;
	return 0;
}

int search(int n)
{
	int count=1;
	temp = head;
	while(temp != 0)
	{
		if(n == temp->data)
			return count;
		temp = temp->next;
		count++;
	}
	return 0;
}

