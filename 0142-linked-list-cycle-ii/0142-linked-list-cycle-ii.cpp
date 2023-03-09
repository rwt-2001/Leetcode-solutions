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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode *start = head;
        ListNode *end = head;
        
        do{
            start = start->next;
            end = end->next->next;
        }while(end && end->next && start != end);
        
        if(start != end) return nullptr;
        
        start = head;
        while(end && end->next && start != end){
            start = start->next;
            end = end->next;
        } 
        return start;
    }
};