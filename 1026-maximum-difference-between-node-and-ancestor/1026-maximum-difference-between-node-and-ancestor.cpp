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
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, root->val, root->val);
    }
    
    int dfs(TreeNode *node, int minInt, int maxInt){
        if(!node) return maxInt - minInt;
        
        minInt = min(minInt, node->val);
        maxInt = max(maxInt, node->val);
        int nl = dfs(node->left, minInt, maxInt);
        int nr = dfs(node->right, minInt, maxInt);
        return max(nl, nr);
    }
};