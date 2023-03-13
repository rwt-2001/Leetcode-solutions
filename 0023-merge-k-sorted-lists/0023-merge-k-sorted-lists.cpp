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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        int n = lists.size();
        for(int i = 1; i < n; i++)
        {
            lists[i] = mergeTwoLists(lists[i-1], lists[i]);
        }
        
        return lists[n-1];
    }
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* nodeHead = head;
        
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                head->next = list1;
                list1 = list1->next;
                head = head->next;
            }
            else{
                head->next = list2;
                list2 = list2->next;
                head = head->next;
            }
        }
        if(list1 == NULL && list2 != NULL){
            while(list2!=NULL){
                head->next = list2;
                list2 = list2->next;
                head = head->next;
            }
        }
        else if(list2 == NULL && list1 != NULL){
                head->next = list1;
                list1 = list1->next;
                head = head->next;
        }
       head = NULL;
        return nodeHead->next;
        
    }
};