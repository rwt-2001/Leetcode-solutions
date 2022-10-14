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
    ListNode* reverse(ListNode *head){
        if(!head->next) return head;     
        ListNode * newHead = reverse(head->next);   
        head->next->next = head;
        head->next = NULL;
        return newHead;
    } 
    
    void reorderList(ListNode* head) {
        if(!head->next || !head->next->next){
            return;
        }
        
        ListNode * slow = head;
        ListNode *fast = head->next->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *l1 = head;
        ListNode *l2 = reverse(slow->next);
        
        
        while(l1->next && l2->next){
            ListNode *tempL1 = l1->next;
            ListNode *tempL2 = l2->next;
            l1->next = l2;
            l2->next = tempL1;
            l1 = tempL1;
            l2 = tempL2;

        }
        
        
    }
};