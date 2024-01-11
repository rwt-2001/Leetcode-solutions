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
    int ans = -1;
public:
    pair<int,int> dfs(TreeNode* node)
    {
        if(!node->left && !node->right) return {node->val,node->val};
        pair<int,int> res = {INT_MAX, INT_MIN};
        if(node->left)
        {
            auto result = dfs(node->left);
            res = {min(res.first,result.first), max(res.second, result.second)};
        }
        if(node->right)
        {
            auto result = dfs(node->right);
            res = {min(res.first,result.first), max(res.second, result.second)};
        }
        
        ans = max({abs(node->val - res.first), abs(node->val - res.second), ans});
        return {min(res.first, node->val), max(res.second, node->val)};
        
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};