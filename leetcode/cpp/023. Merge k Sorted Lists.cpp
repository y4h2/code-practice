/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

//把所有链表的当前结点放入小顶堆中


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
    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {
        vector<ListNode *> minHeap;
        
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] != NULL)
                minHeap.push_back(lists[i]);
        }
        make_heap(minHeap.begin(), minHeap.end(), cmp);
        
        ListNode *head = NULL;
        ListNode *cur = NULL;
        while (!minHeap.empty())
        {
            ListNode *min = minHeap.front();
            pop_heap(minHeap.begin(), minHeap.end(), cmp);
            minHeap.pop_back();
            if (head == NULL)
            {
                head = min;
            }
            if (cur != NULL)
            {
                cur->next = min;
            }
            cur = min;
            
            if (cur->next != NULL) //把后续结点继续放入堆
            {
                minHeap.push_back(cur->next);
                push_heap(minHeap.begin(), minHeap.end(), cmp);
            }
        }
        
        return head;
    }
    
    static bool cmp(const ListNode *a, const ListNode *b)
    {
        return a->val > b->val;
    }
};


//暴力解法， 结果超时
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;

        while (!lists.empty()) {
            ListNode* temp = NULL;
            int max_i;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] == NULL) {
                    lists.erase(lists.begin() + i);
                    // continue;
                }
                
                if (temp == NULL && lists[i] != NULL) {
                    temp = lists[i];
                    max_i = i;
                }
                else if (temp != NULL && lists[i] != NULL && temp->val > lists[i]->val) {
                    temp = lists[i];
                    max_i = i;
                }
                
            }
            if (cur != NULL && temp != NULL){
                cur->next = temp;
                cur = cur->next;
                lists[max_i] = lists[max_i]->next;
            }
        }
        
        return dummyHead->next;
    }
};
