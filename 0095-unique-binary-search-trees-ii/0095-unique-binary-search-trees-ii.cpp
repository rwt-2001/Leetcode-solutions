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
    vector<TreeNode*> solve(int i, int j)
    {
        if(i>j) return {NULL};
        
        vector<TreeNode *> res;
        
        for(int l = i ; l <= j; l++)
        {
            auto lefts = solve(i,l-1);
            auto rights = solve(l+1, j);
            
            for(auto &left: lefts)
            {
                for(auto &right: rights)
                {
                    TreeNode *node = new TreeNode(l);
                    node->left = left;
                    node->right = right;
                    res.push_back(node);
                }
            }
        }
        return res;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};