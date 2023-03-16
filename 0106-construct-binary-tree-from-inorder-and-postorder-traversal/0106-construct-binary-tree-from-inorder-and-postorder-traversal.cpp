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
    unordered_map<int,int> in;
    unordered_map<int,int> po;
    
public:
    TreeNode* build(int l1, int r1, vector<int>& inorder, vector<int>& postorder)
    {
        if(l1==r1) return (new TreeNode(inorder[l1]));
        if(l1 > r1 ) return nullptr;
        
        int index = 0;
        
        for(int i = l1; i <= r1; i++){
           index = max(index, po[inorder[i]]);
        }    
        
        int rootdata = postorder[index];
        TreeNode *node = new TreeNode(rootdata);

        int newR1 = in[rootdata] - 1;
        int newL1 = in[rootdata] + 1;
        node->left = build(l1, newR1, inorder, postorder);
        node->right = build(newL1, r1, inorder, postorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
        {
            in[inorder[i]] = i;
        }
        for(int i = 0; i < inorder.size(); i++)
        {
            po[postorder[i]] = i;
        }
        
        return build(0, inorder.size() - 1, inorder, postorder);
    }
};