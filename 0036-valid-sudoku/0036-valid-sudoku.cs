class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<char>> rows;
        map<int, set<char>> cols;
        // wach queare is one 3X3 matrix in sudoku
        map<pair<int,int>, set<char>> square;
        for(int i =0;i<9;i++){
            
            for(int j = 0;j<9;j++){
                
                if(board[i][j]=='.') continue;
                if(rows[i].count(board[i][j]) || cols[j].count(board[i][j]) ||                                                   square[{i/3,j/3}].count(board[i][j])) return false;
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                square[{i/3,j/3}].insert(board[i][j]);
                
            }
            
            
        }
        return true;
    }
    
};