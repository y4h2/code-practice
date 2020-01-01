/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nex = NULL;
        
        while(cur != NULL)
        {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        
        return prev;
    }
};

//递归写法
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = head->next;
        head->next = NULL;
        
        ListNode* newhead = reverseList(p);
        p->next = head;
        
        return newhead;
    }
};
