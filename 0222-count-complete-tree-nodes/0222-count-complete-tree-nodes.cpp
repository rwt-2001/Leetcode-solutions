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
    int calculateHeightLeft(TreeNode * root){
        if(!root) return 0;
        
        return 1 + calculateHeightLeft(root->left);
    }
    int calculateHeightRight(TreeNode * root){
        if(!root) return 0;
        
        return 1 + calculateHeightRight(root->right);
    }
    
    
    int calculateheight(TreeNode * root){
        if(!root) return 0;
        int hleft = calculateHeightLeft(root);
        int hright = calculateHeightRight(root);
        
        if(hleft == hright){
            return pow(2, hright) - 1;
        }
        
        return 1 + calculateheight(root->left) + calculateheight(root->right);
    }
    int countNodes(TreeNode* root) {
        return calculateheight(root);
    }
};