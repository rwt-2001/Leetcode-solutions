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
    int ans = INT_MIN;
public:
    int dfs(TreeNode* node, int val){
        
        if(!node->left && !node->right){
            return abs(val - node->val);
        }else{
            int nl = 0, nr = 0;
            if(node->left)
                nl = dfs(node->left, val);
            if(node->right)
                nr = dfs(node->right, val);
            return max({abs(node->val - val), nl, nr});
        }
    }
    
    void dfsMain(TreeNode* node){
        if(!node) return;
        if(node->left){
            ans = max(ans, dfs(node->left, node->val));
            dfsMain(node->left);
        }
            
        if(node->right){
           ans = max(ans, dfs(node->right, node->val));
            dfsMain(node->right);
        }
            
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        dfsMain(root);
        return ans;
    }
};