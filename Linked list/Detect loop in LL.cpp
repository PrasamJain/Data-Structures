// In this file we simply detect the loop/cycle in linked list using [TortoiseHare Method]

/*
 * Definition for singly-linked list somthing like that.
 
 * struct Node {
 *     int val;
 *     Node *next;
 *     Node(int x, Node *next) : val(x), next(next) {}
 * };
*/ 

// we only write the function - "hasCycle()" to detect the loop/cycle

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
	    ListNode *fast=head;
	    if(head == NULL)
        {
	        return false;
	    }
	    else
	    {
            while(fast != NULL and fast->next != NULL)
	        {
	            slow = slow->next;
	            fast = fast->next->next;
                if(slow == fast)
                    return true;
            }
            return false;
	    }
    }
};
