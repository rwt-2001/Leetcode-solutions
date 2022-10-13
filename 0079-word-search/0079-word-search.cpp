class Solution {
public:
    bool isAvailable(string & word, vector<vector<char>> & board, int i, int j, int index ){
        if(index>=word.size()) return true;
        if(i<0 || i>=board.size() || j < 0 || j>=board[0].size()|| board[i][j]!=word[index]) return false;
        
        board[i][j] = '0';
        
        bool isWordAvailable = false;
        
        isWordAvailable = isAvailable(word, board, i-1,j,index+1) || isAvailable(word, board, i,j-1,index+1) || isAvailable(word, board, i,j+1,index+1) || isAvailable(word, board, i+1,j,index+1);
        
        board[i][j] = word[index];
        
        return isWordAvailable;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                
                if(isAvailable(word, board, i,j,0)) return 1;
                
            }
        }
        return false;
    }
};