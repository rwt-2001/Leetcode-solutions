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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = new ListNode();
        ListNode *even = new ListNode();
        ListNode *sodd = odd;
        ListNode *seven = even;
        int i = 1;
        while(head){
            if(i & 1){
                odd->next = head;
                odd = odd->next;
            }else{
                even->next = head;
                even = even->next;
            }
            i++;
            head = head->next;
        }
        even->next = NULL;
        odd->next = NULL;
        odd->next = seven->next;
        return sodd->next;
    }
};