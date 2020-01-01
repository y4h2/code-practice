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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        int sum = 0;
        while (l1 != NULL || l2 != NULL)
        {
            sum /= 10;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            
            cur->next = new ListNode(sum % 10);
            cur = cur->next; //第一个节点是用不到的，再怎么开头也是第二个节点
        }
        
        if (sum / 10 != 0)
        {
            cur->next = new ListNode(1);
        }
        
        return dummyHead->next;
    }
};
