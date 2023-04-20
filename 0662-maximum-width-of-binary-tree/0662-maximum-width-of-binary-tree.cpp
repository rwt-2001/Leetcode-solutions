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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,1});
        
        long long ans = 1;
        long long f,l;
        while(q.size())
        {
            int sz = q.size();
            f = q.front().second;
            for(int i = 0; i < sz; i++)
            {
                auto node = q.front();
                q.pop();
                long long n = node.second - f;
                if(node.first->left)
                {
                    q.push({node.first->left,2*n});
                }
                if(node.first->right)
                {
                    q.push({node.first->right,2*n+1});
                }
                if(i == sz - 1)
                {
                    l = node.second;    
                }
            }
            
            if(sz > 1)
            {
                ans = max(ans, l - f + 1);
            }
        }
        
        return ans;
    }
};