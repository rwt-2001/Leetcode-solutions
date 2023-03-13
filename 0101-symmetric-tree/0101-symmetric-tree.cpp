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
    bool checkSymetric(TreeNode * leftN, TreeNode *rightN){
        if(!leftN || !rightN) return (!leftN && !rightN);
        
        if(leftN->val != rightN->val) return false;
        
        return checkSymetric(leftN->left, rightN->right) && checkSymetric(leftN->right, rightN->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        return checkSymetric(root->left, root->right);
    }
};