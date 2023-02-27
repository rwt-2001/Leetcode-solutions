/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>> &grid, int r1, int r2, int c1, int c2)
    {
        if(r1==r2 && c1==c2)
        {
            Node *leaf = new Node(grid[r1][c1], true);
        }
        
        int isSame = true;
        int value = grid[r1][c1];

        for(int i = r1; i <= r2 ; i++)
        {
            for(int j = c1; j <=c2 ; j++)
            {
                if(grid[i][j] != value)
                {
                    isSame = false;
                }
            }
        }
        
        if(isSame) return new Node(value, true);
        
        
        Node * node = new Node(1,false);
        
        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;
        int rowMid = r1 + rows / 2 - 1;
        int colMid = c1 + cols / 2 - 1;
        
        //topLeft
        node->topLeft = solve(grid, r1, rowMid, c1, colMid);
        
        //topRight
        node->topRight = solve(grid, r1, rowMid, colMid + 1, c2);
        
        //bottomLeft
        node->bottomLeft = solve(grid, rowMid + 1, r2, c1, colMid);
        
        //bottomRight
        node->bottomRight = solve(grid,rowMid + 1, r2, colMid + 1, c2);
        
        return node;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, grid.size() - 1, 0, grid[0].size() - 1);
    }
};