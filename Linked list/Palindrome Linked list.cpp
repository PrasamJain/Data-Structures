// In this file we check whether the linked list is palindrome or not.

/*
 * Definition for singly-linked list somthing like that.
 
 * struct Node {
 *     int val;
 *     Node *next;
 *     Node(int x, Node *next) : val(x), next(next) {}
 * };
*/ 

// we don't write whole code instead we simply make the boolean function which returns the true-false value.

class Solution {
public:
    ListNode* mid(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* prev = NULL;
        while(cur){
            ListNode* t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        return prev;
    }
    
    
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode* f = head;
        ListNode* s = mid(head);
        
        s = reverse(s);
        
        ListNode* i = f;     // f contains the first pointer
        ListNode* j = s;     // s contains the last pointer 
        
        while(j){
            // cout << i->val << endl;
            if(i->val != j->val){
                return false;
            }
            i = i->next;
            j = j->next;
        }
        
        return true;
    }
};
