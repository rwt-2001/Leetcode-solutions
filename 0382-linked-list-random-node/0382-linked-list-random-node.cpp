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
        int size;
        ListNode *temp;
public:
    Solution(ListNode* head) {
        size = 0;
        temp = head;
        ListNode * node = head;
        while(node)
        {
            node = node->next;
            size++;
        }
    }
    
    int getRandom() {
        int random = rand() % (size-0);
        ListNode * node = temp;
        while(random--)
        {
            node = node->next;
        }
        
        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */