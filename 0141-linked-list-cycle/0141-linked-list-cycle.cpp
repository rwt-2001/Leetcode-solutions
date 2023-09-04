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
    bool hasCycle(ListNode *head) {
        ListNode *n1 = head;
        ListNode *n2 = head;
        
        while(n1 && n2 && n2->next)
        {
            n1 = n1->next;
            n2 = n2->next->next;
            if(n1==n2) return true;
        }
        
        return false;
    }
};