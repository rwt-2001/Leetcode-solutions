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
    string f(TreeNode* node)
    {
        string ls = "", rs = "";
        if(node->left)
        {
            ls = '(' + f(node->left) + ')';
        }
        if(node->right)
        {
            if(!node->left) ls="()";
            rs = '(' + f(node->right) + ')';
        }
        return to_string(node->val) + ls + rs;
    }
    string tree2str(TreeNode* root) {
        return f(root);
    }
};