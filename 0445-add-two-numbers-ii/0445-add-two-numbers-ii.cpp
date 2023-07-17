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
    ListNode* reverse(ListNode *node)
    {
        if(!node || node->next == nullptr)
            return node;
        
        
        ListNode *newNode = reverse(node->next);
        node->next->next = node;
        node->next = NULL;
        return newNode;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int  carry=0,sum;
        
        l1 = reverse(l1);

        l2 = reverse(l2);
    
        ListNode * head = new ListNode();
        ListNode *temp = head;
        while(l1 != NULL || l2 != NULL || carry){
            sum = 0;
            sum += carry;
            if(l1!=NULL){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum+=l2->val;
                l2 = l2->next;
            }
            
           carry = sum/10;
            
            ListNode * node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
            
        }
        head->next = reverse(head->next);
        return head->next;
    }
};