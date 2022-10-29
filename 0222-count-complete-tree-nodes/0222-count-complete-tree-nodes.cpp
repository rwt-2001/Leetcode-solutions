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

    int dfsL(TreeNode * root){
        if(!root) return 0;
        
        return 1 + dfsL(root->left);
    }
    int dfsR(TreeNode * root){
        if(!root) return 0;
        
        return 1 + dfsR(root->right);
    }
    
    int f(TreeNode* root){
        if(!root) return 0;
        
        int leftH = dfsL(root);
        int rightH = dfsR(root);
        
        if(leftH == rightH){
            return pow(2, leftH) - 1;
        }
        
        return 1 + f(root->left) + f(root->right);
        
    }
    
    int countNodes(TreeNode* root) {
        return f(root);
    }
};