// In this file we simply find the middle to linked list using [TortoiseHare Method]

/*
 * Definition for singly-linked list somthing like that.
 
 * struct Node {
 *     int val;
 *     Node *next;
 *     Node(int x, Node *next) : val(x), next(next) {}
 * };
*/
 
// we only write the function - "middleNode()" to find middle element of linked list

class Solution 
{
	public:
	    Node* middleNode(Node* head)      // pass head pointer.
		{
	        
	        Node *slow=head;
	        Node *fast=head;
	        if(head == NULL)
	        {
	            return head;
	        }
	        else
	        {
	            while(fast != NULL and fast->next != NULL)
	            {
	                slow = slow->next;
	                fast = fast->next->next;
	            }
	            return slow;        // returning middle pointer.
	        }
	    }
};
