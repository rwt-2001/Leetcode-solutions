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
    map<string, pair<TreeNode *, int>> mp;
    
public:
    string dfs(TreeNode *root)
    {
        if(!root){
            return "";
        }
        
        string res = to_string(root->val);
        
        string leftR =dfs(root->left);
        string rightL = dfs(root->right);
      
        res+="(";
        res+=leftR;
        res+=")";
        
        
 
        res+="(";
        res+=rightL;
        res+=")";
        
        
        mp[res].first = root;
        mp[res].second++;
        return res;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        dfs(root);
        vector<TreeNode *> ans;
        
        for(auto val : mp)
        {
            if(val.second.second > 1)
            {
                ans.push_back(val.second.first);
            }
        }
        return ans;
    }
};
// 1(2(3))
// 2(1)(1)