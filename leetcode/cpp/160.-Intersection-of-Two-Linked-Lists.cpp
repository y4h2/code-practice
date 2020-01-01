/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

//保持两条链节点数相同就行，顺着往后找到值相同的即可

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //280ms
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if (headA == NULL || headB == NULL) return NULL;
        int count1 = 0, count2 = 0, offset = 0;
        ListNode *A = headA, *B = headB;
        while (A->next != NULL)
        {
            ++count1;
            A = A->next;
        }
        while (B->next != NULL)
        {
            ++count2;
            B = B->next;
        }
        offset = abs(count2 - count1);
        A = headA;
        B = headB;
        if (count1 >= count2)
        {
            while (offset != 0)
            {
                --offset;
                A = A->next;
            }
        }
        else
        {
            while (offset != 0)
            {
                --offset;
                B = B->next;
            }
        }
        
        while (A != NULL && B != NULL)
        {
            if (A->val == B->val)
            {
                return A;
            }
            A = A->next;
            B = B->next;
        }
        
        return NULL;
        
    }
};

//224ms
//改进在于没有使用abs函数
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *l1 = headA, *l2 = headB;
        int countA = 0, countB = 0;
        while (l1 != NULL)
        {
            l1 = l1->next;
            ++countA;
        }   
        while (l2 != NULL)
        {
            l2 = l2->next;
            ++countB;
        }
        int n = countA - countB;
        while (n != 0)
        {
            if (n > 0)
            {
                --n;
                headA = headA->next;
            }
            else if (n < 0)
            {
                ++n;
                headB = headB->next;
            }
        }
        
        while (headA != NULL && headB != NULL)
        {
            if (headA->val == headB->val)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
        
    }
};
