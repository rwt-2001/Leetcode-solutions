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
    void markParent(TreeNode *root, map<int, TreeNode *> &parent, TreeNode* startNode, int start){
        if(!root) return;
        if(root->val == start) *startNode = *root;
        if(root->left) parent[root->left->val] = root;
        if(root->right) parent[root->right->val] = root;
        markParent(root->left, parent, startNode, start);
        markParent(root->right, parent, startNode, start);
        
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode * startNode = new TreeNode();
        map<int, TreeNode *> parent;
        markParent(root, parent, startNode, start);
        map<int,int> visited;
        
        
        queue<TreeNode *> q;
        q.push(startNode);
        int time = -1;
        
        while(!q.empty()){
            int n = q.size();
            time++;
            
            for(int i = 0;i<n;i++){
                
                TreeNode * curNode = q.front();
                int curVal = curNode->val;
             
                q.pop();
                
                visited[curVal] = 1;
                TreeNode * parentNode = parent[curVal];
                
                if(parentNode && !visited[parentNode->val]){
                    q.push(parentNode);
                }
                if(curNode->left && !visited[curNode->left->val]){
                    q.push(curNode->left);
                }
                if(curNode->right && !visited[curNode->right->val]){
                    q.push(curNode->right);
                }
                
            }
            
            
        }
        return time;
    }
};