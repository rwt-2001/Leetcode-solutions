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
    TreeNode* startNode;
    int startNum;
    map<TreeNode*,TreeNode*> mp;
    void dfs(TreeNode* parent)
    {
        if(!parent) return;
        if(parent->val == startNum) startNode = parent;
        if(parent->left)
        {
            mp[parent->left] = parent;
            dfs(parent->left);
        }
        
        if(parent->right)
        {
            mp[parent->right] = parent;
            dfs(parent->right);
        }
        
    }
    int amountOfTime(TreeNode* root, int start) {
        
        startNum = start;
        dfs(root);
        
        map<TreeNode*,int> visited;
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode]++;
        int ans = -1;
        while(q.size())
        {
            int n = q.size();
            
            while(n--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    visited[node->left]++;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    visited[node->right]++;
                    q.push(node->right);
                }
                
                if(mp[node] && !visited[mp[node]])
                {
                    visited[mp[node]]++;
                    q.push(mp[node]);
                }
            }
            ans++;
        }
        return ans;
    }
};