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
    int ans = 0;
public:
    void findLength(TreeNode * node, int past, int len)
    {
        ans = max(ans, len);
        if(node->left)
        {
            if(past == 1)
            {
                findLength(node->left, 0, len + 1);
            }else{
                findLength(node->left, 0, 1);
            }
            
        }
        if(node->right)
        {
            if(past == 0)
            {
                findLength(node->right, 1, len + 1);
                return;
            }else{
                findLength(node->right, 1, 1);
            }
            
        }
        
    }
    int longestZigZag(TreeNode* root) {
        
        if(!root->left && !root->right) return 0;
        findLength(root, -1, 0);
        return ans;
    }
};