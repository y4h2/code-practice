/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

//注意：这题与reverse linked list II相似
//注意学习这种反转链表的方法
//直接结点的next指针反向链接，并不丢失结点即可
//如果每次都按照把后面的结点插入到前面来做，过于复杂

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) 
    {
        if (head == NULL) return NULL;
        if (1 == k) return head;
        
        int count = k;
        ListNode *nextHead = head;
        
        while (count > 0 && nextHead)
        {
            --count;
            nextHead = nextHead->next;
        }
        if (count > 0)
            return head;
            
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur != nextHead)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        head->next = reverseKGroup(nextHead, k);
        
        return pre;
    }
};


// 代码缩减版
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* nextHead = head;
        
        for(int i = 0; i < k; ++i) {
            if(nextHead == NULL)
                return head;
            nextHead = nextHead->next;
        }
        
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != nextHead) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        head->next = reverseKGroup(nextHead, k);
        
        return pre;
    }
};
