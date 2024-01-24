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
    int dfs(TreeNode* node, vector<int> &mp)
    {
        if(!node) return 0;
        if(!node->left && !node->right){
            mp[node->val]++;
            int odd = 0;
            for(int i = 0; i < mp.size(); i++){
                if(mp[i]&1) odd++;
                if(odd > 1) break;
            }   
            mp[node->val]--;
            return odd < 2;
        }
        
        
        mp[node->val]++;
        int ans = dfs(node->left, mp) + dfs(node->right, mp);
        mp[node->val]--;
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> mp(10,0);
        return dfs(root, mp );
    }
};