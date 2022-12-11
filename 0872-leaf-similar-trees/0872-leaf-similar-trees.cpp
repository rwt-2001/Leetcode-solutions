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
    vector<int> leaves1;
    int i = 0;
public:
    bool dfs1(TreeNode* node){
       
        if(!node->left && !node->right){
            if(node->val != leaves1[i++]) return false;
        }
        bool l1 = node->left ? dfs1(node->left) : true;
        bool l2 = node->right ? dfs1(node->right) : true;
        return l1 && l2;
    }
    void dfs2(TreeNode * node){
        if(!node) return;
        if(!node->left && !node->right) leaves1.push_back(node->val);
        dfs2(node->left);
        dfs2(node->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs2(root1);
        return dfs1(root2) && i==leaves1.size() ;
        
    }
};