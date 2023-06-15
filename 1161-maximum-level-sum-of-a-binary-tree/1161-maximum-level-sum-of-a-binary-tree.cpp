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
    int maxLevelSum(TreeNode* root) {
        int MaxSum = INT_MIN;
        int level = -1;
        
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        int sz;
        while(sz = q.size())
        {
            lvl++;
            int curLvlSum = 0;
            for(int i = 0; i < sz; i++)
            {
                TreeNode* curNode = q.front();
                q.pop();
                curLvlSum+= curNode->val;
                
                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }
            
            if(curLvlSum > MaxSum)
            {
                MaxSum = curLvlSum;
                level = lvl;
            }
            
        }
        
        return level;
    }
};