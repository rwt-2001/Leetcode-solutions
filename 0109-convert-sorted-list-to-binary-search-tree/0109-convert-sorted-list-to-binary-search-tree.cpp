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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* builtTree(int l, int r, vector<int> &arr)
    {
        if(l>r) return nullptr;
        
        int mid = l + (r - l)/2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = builtTree(l, mid-1, arr);
        node->right = builtTree(mid+1, r, arr);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        
        while(head)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        
        return builtTree(0, arr.size()-1, arr);
    }
};