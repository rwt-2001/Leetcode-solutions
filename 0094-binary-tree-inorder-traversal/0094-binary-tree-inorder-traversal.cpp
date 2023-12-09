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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        TreeNode* curNode = root;
        
        while(stk.size() || curNode)
        {
            if(curNode)
            {
                stk.push(curNode);
                curNode = curNode->left;
            }else{
                curNode = stk.top();
                stk.pop();
                ans.push_back(curNode->val);
                curNode = curNode->right;
            }
            
        }
        
        
        return ans;
    }
};

