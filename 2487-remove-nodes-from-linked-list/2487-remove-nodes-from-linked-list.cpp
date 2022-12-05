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
    ListNode* removeNodes(ListNode* head) {
        stack<int> stk;
        while(head){
            
            while(!stk.empty() && stk.top() < head->val){
                stk.pop();
            }
            stk.push(head->val);
            head = head->next;
            
        }
        
    
        
        while(!stk.empty()){
            ListNode *node = new ListNode(stk.top());
            node->next = head;
            head = node;
            stk.pop();
        }
        
        return head;
    }
};