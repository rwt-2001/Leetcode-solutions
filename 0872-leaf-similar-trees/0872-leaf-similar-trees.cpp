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

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        stack<TreeNode*> q1, q2;
        vector<int> qv1, qv2;
        
        q1.push(root1);
        while(q1.size())
        {
            
            TreeNode* node  = q1.top();
                q1.pop();
                if(!node->left && !node->right) qv1.push_back(node->val); 
                if(node->right)q1.push(node->right);
                if(node->left) q1.push(node->left);
        }
        
        q2.push(root2);
        while(q2.size())
        {
            TreeNode* node  = q2.top();
                q2.pop();
                if(!node->left && !node->right) qv2.push_back(node->val); 
                if(node->right)q2.push(node->right);
                if(node->left) q2.push(node->left);
            
        }

        if(qv1.size() != qv2.size()) return false;
        
        for(int i = 0; i < qv1.size(); i++)
        {
            
            if(qv1[i]!=qv2[i]) return false;
        }
        return true;
            
    }
};