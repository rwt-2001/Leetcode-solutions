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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        
        int cur_level_nodes = 1;
        queue<TreeNode *> q;
        bool isbottom = false;
        q.push(root);
        
        while(q.size())
        {
            int sz = q.size();
            bool isLeveled = true;
            for(int i = 0; i < sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if((!node->left && node->right)||(!isLeveled && (node->left || node->right)))
                {
                    return false;
                }
                else if(node->left && !node->right)
                {
                    q.push(node->left);
                    isLeveled = false;
                }else if(node->left && node->right){
                    q.push(node->left);
                    q.push(node->right);
                }else{
                    isLeveled = false;
                }
            }
            
            if(q.size()!=0 && sz != cur_level_nodes){
                return false;
            }else{
                cur_level_nodes*=2;
            }
            
            
            
        }
        
        return true;
    }
};