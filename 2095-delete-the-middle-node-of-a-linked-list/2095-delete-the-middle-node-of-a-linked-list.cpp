/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* fast = head;
        int i = 0;
        while(fast && fast->next){
            i++;
            prev = cur;
            cur = cur->next;
            fast = fast->next->next;
        }
        if(!prev){
            head->next = NULL;
        }
        else{
         prev->next = cur->next;
        }
        
        return head;
    }
};